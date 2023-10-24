
from spleeter.separator import Separator
# Remove when debug
import warnings
warnings.filterwarnings('ignore')
import numpy as np
from scipy.io.wavfile import write

# Use audio loader explicitly for loading audio waveform :
from spleeter.audio.adapter import AudioAdapter

# wavepath - path to the waveform
# stems - number of stems meaning to separate
def stem_split_as_wav(wavepath, stems=5):
    # Using embedded configuration.
    separator = Separator('spleeter:'+ stems +'stems')

    audio_loader = AudioAdapter.default()
    sample_rate = 44100
    waveform, _ = audio_loader.load(wavepath, sample_rate=sample_rate)

    # Perform the separation :
    prediction = separator.separate(waveform)
    
    # convert values to wave file
    for key in prediction:
        write(key + '.wav', sample_rate, prediction[key])