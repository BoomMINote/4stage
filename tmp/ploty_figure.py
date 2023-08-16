import plotly.graph_objects as go
import numpy as np
x = list(range(1, 21))

y1 = np.random.uniform(2.00, 15.00, 20)
y2 = np.random.uniform(10.00, 25.00, 20)
y3 = np.random.uniform(15.00, 30.00, 20)
y4 = np.random.uniform(20.00, 35.00, 20)
y5 = np.random.uniform(150.00, 250.00, 20)

# Define marker shapes and colors for each dataset
marker_shapes = ['circle', 'square', 'diamond', 'cross', 'star']
line_colors = ['blue', 'red', 'green', 'orange', 'purple']
line_names = ['line0','line1','line2','line3','line4']

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
    yaxis_title='Mean Square Error',
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
fig.update_layout(width=700, height=500)

# Display the figure
fig.show()
fig.write_image("figure.png", format="png", engine="kaleido",scale=3)
