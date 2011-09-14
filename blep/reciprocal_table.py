#!/usr/bin/python2.6
#
# Copyright 2011 Olivier Gillet.
#
# Author: Olivier Gillet (ol.gillet@gmail.com)
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

def main():
  print 'uint16_t reciprocal_table[] = {'
  data = numpy.arange(0, 256)
  data[0] = 1
  data = 65535 / data
  for i in xrange(0, len(data), 8):
    data_slice = data[i:i+8]
    print ', '.join(['%d' % x for x in data_slice]) + ','
  print '};'


if __name__ == '__main__':
  main()
