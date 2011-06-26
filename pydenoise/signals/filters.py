#!/usr/bin/python2.6
#
# Author: Olivier Gillet (ol.gillet@gmail.com)

"""Utility functions for the music signal analyzer."""

import numpy
import sys

sys.path.append('.')


def NonLinearFilter(x, w, kernel=numpy.median):
  """Apply kernel function to w-samples long sliding windows of vector x.

  Args:
    x: vector to filter.
    w: width of the observation window.
    kernel: function to apply to a window of w samples centered at x[i] to
        compute the value of y[i]. By default, uses median filtering.

  Returns:
    filtered samples.

  Raises:
    ValueError:
    - the window size is even.
    - x is not a vector or a flat matrix.
  """
  if not w % 2 or w <= 0:
    raise ValueError('Window size must be an odd, positive integer')
  if x.ndim > 1:
    if x.ndim > 2:
      raise ValueError('Cannot process tensors')
    (r, c) = x.shape
    if r == 1:
      x = x[0, :]
    elif c == 1:
      x = x[:, 0]
    else:
      raise ValueError('Can only process flat matrices')

  fill_values = (w - 1) / 2
  n = len(x)
  x = numpy.concatenate((numpy.ones((fill_values,)) * x[0],
                         x,
                         numpy.ones((fill_values,)) * x[-1]))
  # Build a w x n toeplitz matrix with the content of the sliding windows.
  # Each column of the matrix represents a window
  toeplitz = numpy.zeros((w, n))
  for i in xrange(w):
    if not i:
      toeplitz[i, :] = x[w - 1:]
    else:
      toeplitz[i, :] = x[w - i - 1:-i]

  # Check if the kernel function requires an 'axis' argument.
  if 'axis' in list(kernel.func_code.co_varnames):
    return kernel(toeplitz, axis=0)
  else:
    return kernel(toeplitz)
