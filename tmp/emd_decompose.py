import wave
import numpy as np
import plotly.graph_objects as go

# Load WAV audio file
audio_file = "/mnt/d/guitar.wav"
with wave.open(audio_file, 'rb') as wav:
    frames = wav.readframes(-1)
    signal = np.frombuffer(frames, dtype='int16')

# Perform EMD
emd = EMD()
imfs = emd.emd(signal)

# Create figure
fig = go.Figure()

# Add original signal trace
fig.add_trace(go.Scatter(x=np.arange(len(signal)), y=signal, name='Original Signal'))

# Add IMF traces
for i, imf in enumerate(imfs):
    fig.add_trace(go.Scatter(x=np.arange(len(imf)), y=imf, name=f'IMF {i+1}'))

# Update layout
fig.update_layout(
    title="EMD Decomposition",
    xaxis_title="Sample",
    yaxis_title="Amplitude",
    showlegend=True,
    xaxis_range=[0, 20000],  # Set x-axis range to 0-20k
)

# Show the figure
fig.update_layout(width=800, height=600)
fig.show()
fig.write_image("/mnt/d/figure.png", format="png", engine="kaleido", scale=3)
