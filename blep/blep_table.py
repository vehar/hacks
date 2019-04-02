#!/usr/bin/python2.6
#
# Copyright 2011 Emilie Gillet.
#
# Author: Emilie Gillet (emilie.o.gillet@gmail.com)
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

import numpy

NUM_ZERO_CROSSINGS = 16
OVERSAMPLING = 256
THRESHOLD = 3

def minimum_phase_reconstruction(signal, fft_size=32768):
  Xf = numpy.fft.fft(signal, fft_size)
  real_cepstrum = numpy.fft.ifft(numpy.log(1e-50 + numpy.abs(Xf))).real
  real_cepstrum[1:fft_size / 2] *= 2
  real_cepstrum[fft_size / 2 + 1:] = 0
  min_phi = numpy.fft.ifft(numpy.exp(numpy.fft.fft(real_cepstrum))).real
  return min_phi


def print_table(name, data):
  # Truncate small oscillations
  last_sample = numpy.max(numpy.where(numpy.abs(data) > THRESHOLD)[0])
  data = data[:last_sample + 1]
  print '#define BLEP_OVERSAMPLING %d' % OVERSAMPLING
  print '#define BLEP_OVERSAMPLING_BITS %d' % numpy.log2(OVERSAMPLING)
  print '#define BLEP_TABLE_SIZE %d' % len(data)
  print 'int16_t %s[] = {' % name
  for i in xrange(0, len(data), 8):
    data_slice = data[i:i+8]
    print ', '.join(['%d' % x for x in data_slice]) + ','
  print '};'


def main():
  n = NUM_ZERO_CROSSINGS * OVERSAMPLING * 2 + 1
  t = numpy.arange(0, n)
  sinc = numpy.sinc(-NUM_ZERO_CROSSINGS + 2.0 * t / (n - 1) * NUM_ZERO_CROSSINGS)
  windowed_sinc = sinc * numpy.blackman(n)
  blep = minimum_phase_reconstruction(windowed_sinc)[:n]
  blep = numpy.cumsum(blep)

  blep = 1.0 - (blep / blep[-1])
  blep_s2_14 = (blep * 32767).round().astype(numpy.int16)
  print_table('blep', blep_s2_14)


if __name__ == '__main__':
  main()
