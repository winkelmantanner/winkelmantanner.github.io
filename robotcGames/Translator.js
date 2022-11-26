

const VARIABLE_DECL_WITH_INITIALIZATION_REGEX = /(float|double|int|short|long|bool) +(?<partToKeep>[A-z][A-z0-9_]*\s*=[^;]*;)/gm;
const VARIABLE_DECL_WITH_INITIALIZATION_REPLACEMENT = 'var $<partToKeep>';
const NUMERIC_VARIABLE_DECL_WITHOUT_INITIALIZATION_REGEX = /(float|double|int|short|long) +(?<partToKeep>[A-z][A-z0-9_]*)\s*;/gm;
const NUMERIC_VARIABLE_DECL_WITHOUT_INITIALIZATION_REPLACEMENT = 'var $<partToKeep> = 0;';
const BOOLEAN_VARIABLE_DECL_REGEX = /bool +(?<partToKeep>[A-z][A-z0-9_]*)\s*(=[^;]*)?;/gm;
const BOOLEAN_VARIABLE_DECL_REPLACEMENT = 'var $<partToKeep> = false;';

const JAVASCRIPT_VARIABLE_DECL_REGEX = /(var|const|let) +(?<variableName>[A-z][A-z0-9_$]*)\b/gm;

const C_FUNCTION_DECL_REGEX = /(void|float|double|int|short|long|bool|task) +(?<functionName>[A-z][A-z0-9_]*\s*\([^()]*\))/gm;
const C_FUNCTION_DECL_REPLACEMENT = 'async function $<functionName>';

const JAVASCRIPT_FUNCTION_DECL_REGEX = /function +(?<functionName>[A-z][A-z0-9_$]*)\s*\((?<parameters>[^()]*)\)/gm;
const PARAMETERS_REGEX = /\s*(?<parameterName>[A-z][A-z0-9_$]*)\s*($|(=[^,)]+)?[,)])/gm;

const WHILE_LOOP_OPENING_REGEX = /(?<whileOpening>while\s*\([^{]+\)[^{]*\{)/gm;
const WHILE_LOOP_OPENING_REPLACEMENT = "$<whileOpening>if(Math.random() < 0.001){wait1Msec(1);}";

function getCodeWithVariableNameMadeCaseSensitive(code, variableName) {
    return code.replace(
        new RegExp(`\\b${variableName}\\b`, 'gi'),
        variableName
    );
}

class Translator {

    static hasSensorPragma(robotcCode) {
        return null !== robotcCode.match(/^ *#pragma +config\( *sensor/gim);
    }

    static getJsFromRobotc(robotcCode) {
        let code = robotcCode;

        // Put Math.round everywhere an integer is assigned
        for(const matchObj of code.matchAll(/\b(?:int|short|long)\s*(?<variableName>[A-z][A-z0-9_]*)\s*[=;]/gm)) {
            const variableName = matchObj.groups.variableName;
            code = code.replace(
                new RegExp(`(?<theMatch>\\b${variableName}\\b\\s*(?:\\+\\+|--|(?:[+\\-*/%&|^]|<<|>>)?=(?:$|[^=]))(?:[^;])*;)`, 'gim'),
                `$<theMatch>${variableName} = Math.round(${variableName});`  // I am not sure whether RobotC rounds or floors
            );
        }

        // Replace variable declarations
        code = code.replace(
            VARIABLE_DECL_WITH_INITIALIZATION_REGEX,
            VARIABLE_DECL_WITH_INITIALIZATION_REPLACEMENT
        );
        code = code.replace(
            NUMERIC_VARIABLE_DECL_WITHOUT_INITIALIZATION_REGEX,
            NUMERIC_VARIABLE_DECL_WITHOUT_INITIALIZATION_REPLACEMENT
        );
        code = code.replace(
            BOOLEAN_VARIABLE_DECL_REGEX,
            BOOLEAN_VARIABLE_DECL_REPLACEMENT
        );
        // Make variables consistent case, because aparently variable names are not case sensitive in RobotC
        for(const matchObj of code.matchAll(JAVASCRIPT_VARIABLE_DECL_REGEX)) {
            code = getCodeWithVariableNameMadeCaseSensitive(code, matchObj.groups.variableName);
        }

        // Make all while loops release the thread
        code = code.replace(
            WHILE_LOOP_OPENING_REGEX,
            WHILE_LOOP_OPENING_REPLACEMENT
        );

        // Replace function declarations
        code = code.replace(
            C_FUNCTION_DECL_REGEX,
            C_FUNCTION_DECL_REPLACEMENT
        );

        // convert all function names to all lowercase,
        //  including both declarations and calls,
        //  and header keywords like while and if
        const UNIVERSAL_FUNCTION_REGEX = /\b[A-z][A-z0-9_$]*\s*\(/g;
        const matches = code.match(UNIVERSAL_FUNCTION_REGEX);
        const betweenMatches = code.split(UNIVERSAL_FUNCTION_REGEX)
        const toJoin = [betweenMatches[0]];
        for(let k = 0; k < matches.length; k++) {
            toJoin.push(matches[k].toLowerCase());
            toJoin.push(betweenMatches[k + 1])
        }
        code = toJoin.join('');

        // Arrays
        // I only knew how to make char arrays back in the day, so hardcode char.
        code = code.replace(
            /char\s+(?<arrayName>[A-z][A-z0-9_]*)\s*\[(?<arraySize>[^\[\]]*)\]/g,
            "var $<arrayName> = Array($<arraySize>).fill(0)"
        );

        // Make all functions async
        code.replace(
            JAVASCRIPT_FUNCTION_DECL_REGEX,
            "async function $<functionName>"
        );
        for(const matchObj of code.matchAll(JAVASCRIPT_FUNCTION_DECL_REGEX)) {
            // Make all occurences of the function name use consistent case
            code = getCodeWithVariableNameMadeCaseSensitive(code, matchObj.groups.functionName);

            // Make parameters use consistent case
            const parametersString = matchObj.groups.parameters;
            for(const parameterMatchObj of parametersString.matchAll(PARAMETERS_REGEX)) {
                code = getCodeWithVariableNameMadeCaseSensitive(code, parameterMatchObj.groups.parameterName);
            }

            const functionName = matchObj.groups.functionName;

            // Add await to all usages of the function name, including the declaration
            code = code.replace(
                new RegExp(`\\b${functionName}\\b`, 'ig'),
                'await ' + functionName
            );

            // Remove await from the declaration
            code = code.replace(
                new RegExp(`\\bfunction *await *${functionName}\\b`, 'ig'),
                'function ' + functionName
            );
        }
        // At this point, just remove the remaining usages of these keywords
        code = code.replace(/\b(int|bool|float|double)\b/g, '');

        code = code.replace(/(time10?0?\s*)\[([^\]]+)\]/gim, "$1($2)");
        code = code.replace(/\bSensorValue\s*\([^()]*\)/gi, "gettouchsensorvalue()");
        code = code.replace(/\bwait1Msec\b/gi, "await wait1Msec".toLowerCase());
        code = code.replace(/\bwait10Msec\b/gi, "await wait10Msec".toLowerCase());
        code = code.replace(/^ *#/gm, "// #"); // comment out lines beginning with #

        code = code + "await main();";

        return code;
    }
}

