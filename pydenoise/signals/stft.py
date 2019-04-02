#!/usr/bin/python2.6
#
# Author: Emilie Gillet (Emilie@gmail.com)

"""Functions for short term fourier analysis/synthesis."""

import numpy
import sys

sys.path.append('.')

from utils import text_progress_bar


def RaisedCosine(n):
  return numpy.sin(numpy.arange(n) / float(n) * numpy.pi)


def Stft(signal, window_size=1024, overlap=4):
  """Short term Fourier transform of a 1-dimensional signal.
  
  The analysis window is a raised cosine window, and it must be applied during
  reconstruction. The raised cosine window verifies:
  w(n)^2 + w(n + window_size / 2)^2 == 1.
  
  Args:
    signal: input signal.
    window_size: size of an analysis window.
      The FFT size is twice the window size.
    overlap: overlap factor between analysis windows.
    
  Returns:
    N x (window_size + 1) matrix with the STFT frames.
  """
  hop_size = window_size / overlap
  window = RaisedCosine(window_size)
  num_frames = max(len(signal) - window_size + hop_size - 1, 0) / hop_size + 1
  fft_size = window_size * 2
  stft = numpy.zeros((num_frames, fft_size / 2 + 1), dtype=numpy.complex)
  progress = text_progress_bar.TextProgressBar('STFT')
  progress.set_max_progress(num_frames)
  progress.Start()
  analysis_block = numpy.zeros((fft_size,))
  for frame in xrange(num_frames):
    # Extract slice
    start = frame * hop_size
    signal_slice = signal[start:start + window_size]
    if len(signal_slice) != window_size:
      padded = numpy.zeros((window_size,))
      padded[:len(signal_slice)] = signal_slice
      signal_slice = padded
    # Apply window
    stft[frame, :] = numpy.fft.rfft(signal_slice * window, fft_size)
    progress.IncrementBy(1)
  progress.Finish()
  return stft


def OverlapAdd(stft, overlap=4):
  """Short term Fourier transform of a 1-dimensional signal.
  
  Args:
    signal: input signal.
    window_size: size of an analysis window.
      The FFT size is twice the window size.
    overlap: overlap factor between analysis windows.
    
  Returns:
    N x (window_size + 1) matrix with the STFT frames.
  """
  
  num_frames, fft_size = stft.shape
  fft_size = (fft_size - 1) * 2
  window_size = fft_size / 2
  window = RaisedCosine(window_size)
  hop_size = window_size / overlap
  signal_size = (num_frames - 1) * hop_size + window_size
  signal = numpy.zeros((signal_size,))
  progress = text_progress_bar.TextProgressBar('Overlap-Add')
  progress.set_max_progress(num_frames)
  progress.Start()

  window_normalization = 0.0
  for i in xrange(overlap):
    window_normalization += window[hop_size * i] * window[hop_size * i]
  
  window /= window_normalization
  
  for i in xrange(num_frames):
    start = i * hop_size
    signal[start:(start + window_size)] += numpy.fft.irfft(
        stft[i, :])[:window_size] * window
    progress.IncrementBy(1)
  progress.Finish()
  
  # Adjust the gain at the beginning and end of the signal to compensate for
  # the short segments during which less than 4 windows overlapped.
  head_compensation = numpy.zeros((hop_size * overlap)) + 1e-5
  for i in xrange(overlap):
    start = i * hop_size
    end = min(start + window_size, window_size)
    head_compensation[start:end] += window[:(end-start)] * window[:(end-start)]
  tail_compensation = numpy.flipud(head_compensation)
  
  n = min(len(signal), len(head_compensation))
  signal[:n] /= head_compensation[:n] * window_normalization
  signal[-n:] /= tail_compensation[-n:] * window_normalization
  
  return signal
