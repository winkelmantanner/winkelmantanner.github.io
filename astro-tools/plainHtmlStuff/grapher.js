
function _getLineOrBarGraph(graph_type_string, data_lists, dataset_labels, dataset_colors, horizontal_axis_label, vertical_axis_label) {
  // data_lists: array of arrays of arrays.
  // Innermost array is of length 3 and takes the form [x, y, label].  label is optional.
  // Middle-level array is the list of points to plot.
  // Outer array is the list of datasets.  Each dataset is plotted with a different line on the same axes.
  // ALL DATASETS MUST HAVE THE EXACT SAME SET OF X VALUES

  // dataset_labels: array of strings.  Should be the same length as data_lists

  // dataset_colors: list of color strings.  Should be the same length as data_lists

  // horizontal_axis_label: string

  // vertical_axis_label: string

  const container = document.createElement('div');
  const canvas = document.createElement('canvas');
  container.appendChild(canvas);
  const ctx = canvas.getContext('2d');

  let x_labels = {};
  const datasets = data_lists.map((data, index) => {
    const data_map = {};
    const formatted_data = [];
    for(const [x, y, label] of data) {
      formatted_data.push({x: Number(x), y: Number(y), label});
      data_map[x] = y;
    }
    x_labels = Object.keys(data_map); // this won't work if the datasets have different sets of x values
    x_labels.sort();
    let y_values = x_labels.map(label => data_map[label]);

    return {
      data: y_values,
      fill: false,
      borderColor: dataset_colors[index],
      backgroundColor: dataset_colors[index],
      lineTension: 0,
      borderWidth: 1,
      label: dataset_labels[index]
    };

  })

  const myChart = new Chart(ctx, {
      type: graph_type_string,
      data: {
          labels: x_labels,
          datasets
      },
      options: {
          scales: {
              y: {
                  beginAtZero: true,
                  title: {
                    display: true,
                    text: vertical_axis_label
                  }
              },
              x: {
                  title: {
                    display: true,
                    text: horizontal_axis_label
                  }
              }
          }
      }
  });


  return container;
}


function getLineGraph(...params) {
  return _getLineOrBarGraph('line', ...params);
}

function getBarGraph(...params) {
  return _getLineOrBarGraph('bar', ...params);
}
