#!/usr/bin/python2.6
#
# Author: Emilie Gillet (emilie.o.gillet@gmail.com)

"""Template based denoiser."""

import numpy
import optparse
import os
import sys

sys.path.append('.')


from io import audio_io
from signals import filters
from signals import stft
from utils import text_progress_bar


def main(args, options):
  samples, sr = audio_io.ReadWavFile(args[0])
  
  # Convert to mono.
  samples = samples.sum(axis=1)

  # Use the last seconds as training data for noise.
  tail = int(options.seconds * sr)
  noise = samples[-tail:]
  
  # Compute the geometric average of the last STFT frames.
  noise_floor = numpy.log(numpy.abs(stft.Stft(noise)) + 2.0 ** -16)
  noise_floor = numpy.exp(2.0 * noise_power_db.mean(axis=0))
  
  # Compute the bin used for hi-pass filtering.
  hipass_bin = int(2 * options.hipass_frequency / sr * noise_floor.shape[0])

  # Here we go!
  signal = stft.Stft(samples)
  modified_signal = numpy.zeros(signal.shape, dtype=numpy.complex)
  
  progress = text_progress_bar.TextProgressBar('Denoising')
  progress.set_max_progress(signal.shape[0])
  progress.Start()
  
  # Process each STFT frame
  for i in xrange(signal.shape[0]):
    s = numpy.abs(signal[i, :]) ** 2.0
    estimated_signal = s - noise_floor
    estimated_signal = estimated_signal * (estimated_signal > 0.0)
    
    current_snr = estimated_signal / noise_floor
    previous_snr = modified_signal[i, :] / noise_floor
    
    snr = previous_snr * options.temporal_smoothing + \
        current_snr * (1 - options.temporal_smoothing)
    mask = (1 - options.level / ((snr + 1) ** 0.5))
    mask = mask * (mask > 0)
    
    # Apply mask.
    modified_signal[i, hipass_bin:] = signal[i, hipass_bin:] * mask[hipass_bin:]
    progress.IncrementBy(1)
  progress.Finish()
  
  audio_io.WriteWavFile(
      stft.OverlapAdd(modified_signal),
      sr,
      options.output_file,
      bitdepth=16, normalize=True)


if __name__ == '__main__':
  parser = optparse.OptionParser()
  parser.add_option(
      '-o',
      '--output_file',
      dest='output_file',
      default=None,
      help='Write output file to FILE',
      metavar='FILE')
  parser.add_option(
      '-l',
      '--level',
      dest='level',
      type=float,
      default=1.0,
      help='Threshold under which noise is suppressed')
  parser.add_option(
      '-t',
      '--temporal_smoothing',
      dest='temporal_smoothing',
      type=float,
      default=0.90,
      help='Temporal smoothing factor')
  parser.add_option(
      '-p',
      '--hipass_frequency',
      dest='hipass_frequency',
      type=float,
      default=80.0,
      help='Hi pass frequency')
  parser.add_option(
      '-s',
      '--seconds',
      dest='seconds',
      type=float,
      default=1.0,
      help='Seconds of silence at the end of the file to use as a' + \
           ' noise template')
  
  options, args = parser.parse_args()
  if len(args) != 1 or options.output_file is None:
    logging.fatal('usage: denoise.py -o output.wav input.wav')
  else:
    main(args, options)
    