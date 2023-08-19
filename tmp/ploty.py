import plotly.graph_objects as go
import numpy as np
x = list(range(1, 21))

# y1 = np.random.uniform(2.00, 15.00, 20)
# y2 = np.random.uniform(10.00, 25.00, 20)
# y3 = np.random.uniform(15.00, 30.00, 20)
# y4 = np.random.uniform(20.00, 35.00, 20)
# y5 = np.random.uniform(150.00, 250.00, 20)

y5 = [ 3.9858682,4.95470148,13.19021047,9.7511708,15.48310408,4.41614732,
 13.35383726,5.61622963,11.96424586,12.74499491,12.08106032,13.27714315,
  14.48471596,9.41352408,10.05283169,11.86208235,8.46406496,13.89686526,
  3.60679124,10.03438696]#ll-net
# add all elem in y5
total = np.sum(y5)
print(total/20)
y4 = [14.5148489,11.85492463,24.62255028,23.41131595,17.26749869,16.8527422,
 12.11346558,23.27539129,23.54751501,27.81902489,15.49388916,19.8561598,
 17.9901308,15.46086746, 22.29250444, 23.52667842, 17.71476627, 15.99899191,
 12.57788955, 16.18546312]#dlinknet
y4 = [x - 3 for x in y4]
y2 = [24.6355844,17.11514769,37.16172035,27.14328721,27.50875595,21.39873788,
 23.53550257,38.82632129,19.32133717,25.21388691,41.8864124,27.97289792,
 27.09881425,26.20398033,19.25908279,21.1588196,20.62044848,19.15381975,
 13.09461203,18.47748384]#FCN
y2 = [x for x in y2]
y3 = [27.43452773,21.94937026,34.80105449,24.18590801,22.45735634,21.29860017,
 23.1019601,29.03922088,34.55670188,25.81157599,29.09862934,24.37652557,
 31.27724127,22.91941729,33.27639981,30.68560622,12.35560868,23.73716673,
 10.45380137,26.4334572]#unet
y3 = [x - 3 for x in y3]
y1 = [228.64390216,160.86758735,291.97838,195.41926517,173.28513612,
 221.6562269,190.03021966,224.38268999,167.23096151,143.89420206,
 232.64073952,204.09697131,239.94117406,209.24470145,202.18257144,
 244.46321409,239.29609917,239.56047819,104.64601265,193.54283213]#otsu
# print(y1)
# print(y2)
# print(y3)
# print(y4)
# print(y5)

# Define marker shapes and colors for each dataset
marker_shapes = ['circle', 'square', 'diamond', 'cross', 'star']
line_colors = ['rgb(0,0,128)', 'red', 'green', 'orange', 'purple']
line_names = ['Otsu-Steger','FCN-Steger','UNet-Steger','DLinkNet-Steger','LLNet-Steger']

# Create a figure and add traces for each line with different marker shapes and colors
fig = go.Figure()
fig.add_shape(
    type='rect',
    xref='paper',
    yref='paper',
    x0=0,
    y0=0,
    x1=1,
    y1=1,
    line=dict(
        color='gray',
        width=2,
    ),
    fillcolor='rgba(0, 0, 0, 0)'
)
for i, y in enumerate([y1, y2, y3, y4, y5]):
    fig.add_trace(go.Scatter(
        x=x, y=y,
        mode='lines+markers',
        marker=dict(
            size=10,
            symbol=marker_shapes[i],  # Assign marker shape based on index
            color=line_colors[i],     # Assign line color based on index
            line=dict(
                color='white',
                width=1
            )
        ),
        line=dict(
            color=line_colors[i],     # Assign line color based on index
            width=3,
            dash='dash'              # Use dashed lines for all datasets
        ),
        name=line_names[i]
    ))

# Set layout properties
fig.update_layout(
    title='Origin-style Figure',
    xaxis_title='Image Index',
    yaxis_title='Mean Square Error/Pixels',
    showlegend=True,
    plot_bgcolor='white',           # Set the plot area background color to white
    xaxis=dict(
        tickmode='array',            # Set the x-axis tick mode to 'array'
        tickvals=x,                  # Set the x-axis tick values to the list of x values
        gridcolor='lightgray',
        gridwidth=1,
        griddash='solid'
    ),  # Customize x-axis gridline color, width, and style
    yaxis=dict(
        gridcolor='lightgray',
        gridwidth=1,
        griddash='solid'
    )   # Customize y-axis gridline color, width, and style
)

# Add a rectangular shape to enclose the entire figure


# Set the figure width and height
fig.update_layout(width=800, height=600)

# Display the figure
fig.show()
fig.write_image("/mnt/c/Users/boomm/Desktop/paper/new paper/figure.png", format="png", engine="kaleido",scale=3)
