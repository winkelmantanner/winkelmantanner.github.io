"""
This program is used to analyze the results of the placebo-controlled trial of ibuprofen.

This version of the program does not depend on any other files.
Instead of reading from a CSV file, this file contains the data in the form of constants.
Additionally, there were some functions imported from other python files, so I put the code for those functions in this file and removed the imports.

Note for readers: "troublesomeness" means head pain.
"""


import pandas as pd
from scipy.stats import pearsonr, spearmanr, ttest_ind
import numpy as np
import re
from datetime import datetime


class IbuprofenTrialRound:
    def __init__(self, min_date_string, max_date_string, mapping):
        self.min_date_string = min_date_string
        self.max_date_string = max_date_string
        self.mapping = mapping


IBUPROFEN_400MG = 'IBUPROFEN_400MG'
PLACEBO = 'PLACEBO'

ROUNDS = [
    IbuprofenTrialRound(
        '2023-03-04',
        '2023-05-13',
        {
            1: IBUPROFEN_400MG,
            2: IBUPROFEN_400MG,
            3: PLACEBO,
            4: PLACEBO,
            5: PLACEBO,
            6: IBUPROFEN_400MG,
            7: PLACEBO,
            8: IBUPROFEN_400MG,
            9: IBUPROFEN_400MG,
            10: PLACEBO
        }
    ),
    IbuprofenTrialRound(
        '2023-05-14',
        '2023-07-29',
        {
            1: IBUPROFEN_400MG,
            2: PLACEBO,
            3: IBUPROFEN_400MG,
            4: PLACEBO,
            5: PLACEBO,
            6: IBUPROFEN_400MG,
            7: IBUPROFEN_400MG,
            8: PLACEBO,
            9: IBUPROFEN_400MG,
            10: PLACEBO
        }
    ),
    IbuprofenTrialRound(
        '2023-08-26',
        '2023-11-14',
        {
            1: PLACEBO,
            2: IBUPROFEN_400MG,
            3: IBUPROFEN_400MG,
            4: IBUPROFEN_400MG,
            5: IBUPROFEN_400MG,
            6: PLACEBO,
            7: PLACEBO,
            8: PLACEBO,
            9: IBUPROFEN_400MG,
            10: PLACEBO
        }
    )
]

VALUES_COL = 'avg_after_treatment_minus_value_at_treatment'

RECORDS_COLUMNS = ('date', 'medications', 'timetroublesomeness')
RECORDS = [
    ('2023-03-19', 'bag7@9:40am', '6@7:40am, 6@9:15am, 6@10:30am, 6@10:55am, 6@11:15am, 6@11:45am, 7@12:45pm, 7@1:45pm, 7@3:50pm, 6@6:10pm, 4@7:50pm, 3@8:30pm'),
    ('2023-03-23', 'bag10@12:50pm', '6@6:50am, 6@7:30am, 5@11:40am, 5@12:20pm, 5@1:35pm, 6@1:50pm, 6@3pm, 7@3:10pm, 7@3:25pm, 6@3:55pm, 7@4:15pm, 7@4:55pm, 7@5:10pm, 7@5:30pm, 7@7:40pm'),
    ('2023-03-29', 'bag6@4:20pm', '5@3:30pm, 5@3:45pm, 5@4:05pm, 5@4:25pm, 5@5:15pm, 5@5:35pm, 5@6:05pm, 5@6:15pm, 5@6:35pm, 6@7:55pm, 6@8:10pm, 6@8:20pm, 5@9pm'),
    ('2023-03-30', 'bag9@3pm', '5@10am, 6@10:10am, 5@3pm, 5@4:30pm, 4@8:45pm, 4@9:15pm'),
    ('2023-04-03', 'bag5@12:55pm', '6@12:15pm, 6@12:30pm, 6@12:55pm, 6@1:15pm, 6@1:40pm, 6@1:50pm, 6@2pm, 6@2:20pm, 6@2:30pm, 7@2:45pm, 7@2:55pm, 7@3:45pm, 6@5pm, 7@5:25pm, 7@5:45pm, 7@6:35pm, 8@7:10pm, 8@7:40pm, 8@8:25pm'),
    ('2023-04-11', 'bag4@5:50pm', '5@2pm, 5@2:15pm, 6@2:30pm, 6@2:40pm, 5@2:50pm, 5@3:05pm, 5@3:35pm, 5@4:45pm, 6@5:20pm, 6@5:45pm, 5@6:40pm, 5@7:30pm, 6@8:10pm, 6@8:45pm'),
    ('2023-04-16', 'bag3@2:45pm', '6@2pm, 6@2:15pm, 6@2:40pm, 6@3:10pm, 6@4:05pm, 6@5pm, 6@5:50pm, 6@6:30pm, 6@6:40pm, 6@7pm, 7@7:20pm, 7@8:20pm'),
    ('2023-04-23', 'bag2@4:20pm', '6@2:30pm, 5@2:45pm, 6@3:30pm, 6@3:50pm, 6@4:15pm, 6@4:20pm, 6@4:40pm, 6@5pm, 6@5:30pm, 6@5:45pm, 4@7:30pm, 4@8:20pm'),
    ('2023-05-01', 'bag1@5:40pm', '5@1:15pm, 5@1:35pm, 5@1:50pm, 5@2pm, 5@2:40pm, 6@2:50pm, 6@3:30pm, 6@3:50pm, 6@4:25pm, 6@4:40pm, 6@5:15pm, 6@5:40pm, 6@7pm, 5@8pm, 5@8:30pm, 5@8:50pm, 5@9:05pm'),
    ('2023-05-08', 'bag8@1:10pm', '6@12:45pm, 6@1pm, 6@1:10pm, 6@1:40pm, 6@2:05pm, 6@2:40pm, 6@3:10pm, 6@3:30pm, 6@4pm, 6@4:15pm, 6@4:40pm, 6@5:05pm, 6@5:30pm, 6@6pm, 6@6:40pm, 6@7:30pm, 6@8:25pm'),
    ('2023-05-14', 'bag5@12:05pm, 1nur@3:30pm', '6@11:40am, 6@12:05pm, 6@12:30pm, 6@1:10pm, 6@1:45pm, 6@2:25pm, 6@3pm, 7@3:20pm, 7@3:30pm, 6@4:25pm, 6@5:10pm, 5@5:35pm, 4@6:20pm, 3@7:55pm, 3@9:15pm'),
    ('2023-05-21', 'bag1@4:10pm', '5@10:15am, 5@10:55am, 5@11:45am, 5@1:50pm, 5@2:45pm, 5@3pm, 5@3:45pm, 6@3:55pm, 6@4:10pm, 6@4:30pm, 6@4:50pm, 6@6:15pm, 5@7:10pm, 4@7:30pm, 4@8:45pm, 3@9pm'),
    ('2023-05-28', 'bag3@5pm', '5@2:30pm, 5@2:50pm, 5@3:35pm, 6@5pm, 6@5:35pm, 6@7pm, 6@8:10pm, 6@9pm, 6@9:15pm, 6@9:45pm'),
    ('2023-06-01', 'bag10@8:45am', '5@7:25am, 5@7:45am, 6@8:30am, 6@8:45am, 6@9:30am, 6@9:45am, 6@10:10am, 6@10:30am, 6@11:15am, 6@12:15pm, 6@12:30pm, 7@12:40pm, 7@1:40pm, 8@2:15pm, 7@3:25pm, 7@3:55pm, 8@4:25pm, 7@4:40pm, 7@5:10pm, 7@6pm, 6@7pm, 6@7:30pm, 5@8:05pm, 4@9:20pm'),
    ('2023-06-15', 'bag8@5:55pm', '5@2:50pm, 5@3:40pm, 6@5:40pm, 6@5:55pm, 6@7pm, 6@7:50pm, 6@8:40pm, 6@9:05pm'),
    ('2023-06-18', 'bag9@11:10am', '6@10:10am, 5@10:25am, 6@11:10am, 6@11:30pm, 6@1:10pm, 6@1:35pm, 6@2:30pm, 5@3:15pm, 5@5pm, 4@6pm, 3@8:05pm'),
    ('2023-07-03', 'bag4@3:35pm', '6@12:50pm, 6@12:55pm, 6@1:10pm, 6@1:45pm, 6@2:30pm, 6@3:35pm, 6@4pm, 7@5pm, 7@5:15pm, 7@5:35pm, 8@6:35pm, 7@7:25pm, 7@7:45pm, 7@8pm, 6@8:40pm, 6@9pm, 6@9:30pm'),
    ('2023-07-11', 'bag2@12:50pm', '5@11:30am, 4@12:20pm, 5@12:50pm, 5@1:25pm, 5@2:30pm, 5@2:40pm, 6@3pm, 6@3:20pm, 6@3:50pm, 6@4:20pm, 6@5:05pm, 6@5:40pm, 6@6:45pm, 6@7:30pm, 6@7:40pm, 6@8pm, 6@8:35pm'),
    ('2023-07-24', 'bag6@5:55pm', '5@5:50pm, 5@5:55pm, 5@6:20pm, 5@6:50pm, 5@7pm, 5@7:20pm, 5@7:40pm, 5@8:20pm, 5@9:10pm'),
    ('2023-07-28', 'bag7@6:45pm', '5@12:20am, 3@1:30pm, 6@6:30pm, 6@6:45pm, 6@7pm, 6@7:20pm, 6@7:35pm, 6@8:20pm, 5@9pm'),
    ('2023-08-27', 'bag10@4:15pm', '5@1:45pm, 5@2:05pm, 6@2:20pm, 6@3:30pm, 6@4pm, 6@4:15pm, 6@4:35pm, 6@4:55pm, 6@5:30pm, 7@6pm, 6@6:30pm, 7@6:45pm, 6@8:10pm, 6@8:20pm, 6@8:45pm'),
    ('2023-09-01', 'bag7@5:55pm', '5@2:45pm, 5@3:50pm, 6@4:15pm, 6@4:20pm, 6@4:55pm, 6@5:30pm, 6@5:55pm, 6@6:30pm, 6@7:15pm, 7@7:50pm, 6@8:45pm'),
    ('2023-09-10', 'bag5@2:15pm', '5@11:40am, 5@12:05pm, 6@12:20pm, 6@12:50pm, 6@1:30pm, 6@2pm, 6@2:15pm, 6@2:25pm, 5@2:55pm, 4@3pm, 4@3:25pm, 3@4pm, 3@4:40pm'),
    ('2023-09-24', 'bag8@11:50am', '5@7:40am, 6@8:05am, 6@8:40am, 6@9:55am, 6@10:45am, 7@11:10am, 7@11:40am, 7@11:50am, 7@12:30pm, 7@1:10pm, 7@1:50pm, 7@2pm, 7@3:30pm, 8@4:05pm, 7@4:45pm, 7@5:15pm, 7@5:50pm, 6@6:10pm, 6@6:30pm, 6@7:20pm, 5@7:55pm'),
    ('2023-10-01', 'bag3@3:10pm', '5@12:35pm, 5@12:55pm, 6@2:05pm, 6@2:45pm, 6@3:10pm, 6@3:20pm, 6@3:45pm, 6@4:05pm, 6@4:30pm, 6@4:45pm, 6@5:05pm, 6@5:45pm, 7@6:15pm, 6@6:45pm, 6@7:10pm, 6@7:15pm, 6@7:45pm, 6@8:20pm, 5@8:50pm'),
    ('2023-10-08', 'bag6@5:35pm', '5@2:40pm, 6@3:30pm, 6@4pm, 6@4:30pm, 6@5pm, 6@5:35pm, 6@6pm, 6@6:20pm, 6@6:30pm, 6@6:45pm, 6@7:05pm, 6@7:20pm, 5@8:30pm'),
    ('2023-10-10', 'bag2@10:50am', '6@6:40am, 6@7am, 6@7:20am, 6@8am, 6@9am, 5@9:25am, 6@10:05am, 6@10:45am, 6@11:45am, 5@12:30pm, 5@1pm, 5@1:25pm, 4@2:15pm, 5@2:25pm, 4@2:45pm, 4@3:30pm, 4@4:15pm'),
    ('2023-10-29', 'bag1@1:10pm', '5@11:25am, 6@12:30pm, 6@1:05pm, 6@1:10pm, 6@1:50pm, 6@2pm, 6@2:25pm, 6@2:45pm, 6@3:10pm, 6@4pm, 6@4:15pm, 6@4:30pm, 6@5pm, 6@5:20pm, 6@5:45pm, 6@6:15pm, 6@6:30pm, 6@6:50pm, 6@7pm, 6@7:20pm, 7@7:35pm, 7@8pm'),
    ('2023-10-31', 'bag4@4:20pm', '6@3pm, 6@3:15pm, 6@3:50pm, 6@4:10pm, 6@4:20pm, 6@4:45pm, 7@5pm, 6@5:50pm, 6@6:15pm, 5@7pm, 5@7:25pm, 4@8:25pm'),
    ('2023-11-12', 'bag9@3:05pm', '6@12:05pm, 6@12:30pm, 6@1:15pm, 6@2:05pm, 6@2:45pm, 6@3:05pm, 6@3:25pm, 6@4:20pm, 6@4:55pm, 6@5:25pm, 6@5:50pm, 6@6:25pm, 5@6:45pm, 4@7:20pm, 4@8:30pm')
]


def get_datetime_from_time_string(time_str):
    """
    time_str should be a string from my records, like "8am" or "7:55pm"
    """
    time_format = '%I'
    if ':' in time_str:
        time_format += ':%M'
    if time_str.lower().endswith('m'):
        time_format += '%p'
    return datetime.strptime(time_str, time_format)


TIME_WITH_AMPM_REGEX = r'[0-9]*(:[0-9]*)?(am|pm)'
def getMedicationDict(medicationIdentifier, medicationRecordStringOrNan):
    """
    Returns a dictionary mapping datetime to quantity.
    If there is data with no datetime attached, None is used as the key.
    """
    resultDict = dict()
    if not pd.isnull(medicationRecordStringOrNan):
        regex = r'(^|[^A-z0-9_.])(?P<quantity>[0-9]*(\.[0-9]+)?){}($|@(?P<time_of_day>{}))'.format(
            medicationIdentifier,
            TIME_WITH_AMPM_REGEX
        )
        for part in medicationRecordStringOrNan.split(','):
            m = re.search(regex, part.strip(), re.IGNORECASE)
            if m:
                quantity = (
                    float(m.group('quantity'))
                    if m.group('quantity') != ''
                    else 1
                )
                dt = None
                if not (m.group('time_of_day') is None):
                    dt = get_datetime_from_time_string(m.group('time_of_day'))
                if dt not in resultDict:
                    resultDict[dt] = 0
                resultDict[dt] += quantity
    return resultDict


def getTimeTroublesomenessDict(recordString):
    """
    Returns a dictionary mapping datetime to troublesomeness.
    """
    if not pd.isnull(recordString):
        regex = r'(?P<troublesomeness>[0-9]+)@(?P<time_of_day>{})'.format(
            TIME_WITH_AMPM_REGEX
        )
        searchResults = list(re.finditer(regex, recordString))
        if searchResults:
            resultDict = dict()
            for m in searchResults:
                dt = get_datetime_from_time_string(m.group('time_of_day'))
                resultDict[dt] = float(m.group('troublesomeness'))
            return resultDict
    return {}


def get_medication_key_from_bag_number(bag_number):
    return 'bag{}'.format(bag_number)


def get_number_from_time_of_day_datetime(dt):
    return dt.hour + (dt.minute / 60.0)


def getTroublesomenessAtTime(tt_string, time_of_bag_datetime):
    """
    Uses linear interpolation.
    This will probably have an error if pass a time_of_bag_datetime
        that is outside of the range of the timetroublesomeness data.
    """
    tt_dict = getTimeTroublesomenessDict(tt_string)

    bag_time_number = get_number_from_time_of_day_datetime(
        time_of_bag_datetime
    )
    pairs_nparr = np.array(sorted(
        (get_number_from_time_of_day_datetime(ts), v)
        for ts, v in tt_dict.items()
    ))
    [np_result] = np.interp(
        [bag_time_number],
        pairs_nparr[:, 0],
        pairs_nparr[:, 1]
    )

    lower_troublesomeness = None
    lower_seconds_off = 1234567890
    upper_troublesomeness = None
    upper_seconds_off = 1234567890
    for tt_dt in tt_dict:
        w = (tt_dt - time_of_bag_datetime).total_seconds()
        if w <= 0 and -w < lower_seconds_off:
            lower_troublesomeness = tt_dict[tt_dt]
            lower_seconds_off = -w
        if w >= 0 and w < upper_seconds_off:
            upper_troublesomeness = tt_dict[tt_dt]
            upper_seconds_off = w
    my_result = lower_troublesomeness + (
        0 if 0 == lower_seconds_off + upper_seconds_off
        else (
            (upper_troublesomeness - lower_troublesomeness)
            * lower_seconds_off
            / (lower_seconds_off + upper_seconds_off)
        )
    )

    assert round(np_result, 3) == round(my_result, 3)

    return my_result


def average_over_time(datetime_value_pairs):
    pairs = list(p for p in datetime_value_pairs)
    pairs.sort()
    total_weight = 0
    running_sum = 0
    for idx in range(len(pairs)):
        time_to_next = 0
        if idx + 1 < len(pairs):
            time_to_next = \
                (pairs[idx + 1][0] - pairs[idx][0]).total_seconds()
        time_to_prev = 0
        if idx - 1 >= 0:
            time_to_prev = \
                (pairs[idx][0] - pairs[idx - 1][0]).total_seconds()
        weight = time_to_next + time_to_prev
        total_weight += weight
        running_sum += weight * pairs[idx][1]
    return running_sum / total_weight


def getAverageTroublesomenessAfterTime(tt_string, time_of_bag_datetime):
    pairs = list()
    pairs.append((
        time_of_bag_datetime,
        getTroublesomenessAtTime(tt_string, time_of_bag_datetime)
    ))
    tt_dict = getTimeTroublesomenessDict(tt_string)
    for tt_dt, troublesomeness in tt_dict.items():
        if tt_dt >= time_of_bag_datetime:
            pairs.append((tt_dt, troublesomeness))
    return average_over_time(pairs)


if __name__ == '__main__':
    df = pd.DataFrame(RECORDS, columns=RECORDS_COLUMNS)
    results = list()
    for round_idx, roundObj in enumerate(ROUNDS):
        sdf = df
        sdf = sdf[sdf['date'] >= roundObj.min_date_string]
        sdf = sdf[sdf['date'] <= roundObj.max_date_string]
        for row_idx, row in sdf.iterrows():
            for bag_number, bag_contents in roundObj.mapping.items():
                med_key = get_medication_key_from_bag_number(bag_number)
                med_dict = getMedicationDict(med_key, row['medications'])
                if len(med_dict) == 1:
                    time_of_treatment = list(med_dict.keys())[0]
                    troublesomeness_at_time_of_treatment = getTroublesomenessAtTime(
                        row['timetroublesomeness'],
                        time_of_treatment
                    )
                    average_troublesomeness_after_treatment = getAverageTroublesomenessAfterTime(
                        row['timetroublesomeness'],
                        time_of_treatment
                    )
                    substance = roundObj.mapping[bag_number]
                    results.append((
                        row['date'],
                        substance == IBUPROFEN_400MG,
                        average_troublesomeness_after_treatment - troublesomeness_at_time_of_treatment
                    ))

    results_df = pd.DataFrame(
        results,
        columns=[
            'date',
            'ibuprofen',
            VALUES_COL
        ]
    )
    print(results_df)
    print("pearsonr:", pearsonr(
        results_df['ibuprofen'],
        results_df[VALUES_COL]
    ))
    print("spearmanr:", spearmanr(
        results_df['ibuprofen'],
        results_df[VALUES_COL]
    ))
    def getValuesWhereIbuprofenIs(i):
        return (
            results_df
            [results_df['ibuprofen'] == i]
            [VALUES_COL]
        )
    print(
        "ttest_ind:",
        ttest_ind(
            getValuesWhereIbuprofenIs(True),
            getValuesWhereIbuprofenIs(False),
            equal_var=False
        )
    )

