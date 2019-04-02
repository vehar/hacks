# -*- coding: utf-8 -*
#
# Copyright (c) 2009 Emilie Gillet (emilie.o.gillet@gmail.com)
#
# dynamic_range.py
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

"""Plots dynamic range charts from RAW images of a uniform light sources."""

import commands
import logging
import matplotlib.pylab
import numpy
import os

# Path to the directory containing the RAW images.
DNG_PATH = 'dng'

# Path to DCRAW.
DCRAW_BINARY = '/usr/local/bin/dcraw'

# Exposure used for the 0eV image.
REFERENCE_EXPOSURE = 1.0 / 60.0


METADATA_EXTENSION = '_metadata.txt'
CONVERT_TO_PGM_CMD = '%(binary)s -D -4 %(in_name)s'
EXTRACT_METADATA_CMD = '%(binary)s -i -v %(in_name)s > %(out_name)s'

pl = matplotlib.pylab
logging.basicConfig(level=logging.INFO)


def GetFiles(target_extension):
  """Gets the list of files matching an extension."""
  for file_name in os.listdir(DNG_PATH):
    base_name, extension = os.path.splitext(file_name)
    if extension.lower() == target_extension:
      yield os.path.join(DNG_PATH, file_name)


def ConvertDngFile(file_name):
  """Calls dcraw for the DNG -> PGM and DNG -> metadata conversions."""
  arguments = {
    'in_name': file_name,
    'out_name': os.path.splitext(file_name)[0] + METADATA_EXTENSION,
    'binary': DCRAW_BINARY
  }
  for command in [CONVERT_TO_PGM_CMD, EXTRACT_METADATA_CMD]:
    command = command % arguments
    logging.info('Running %s' % command)
    status, _ = commands.getstatusoutput(command)
    assert 0 == status


def ReadRawPgmImage(file_object):
  """Reads a RAW image saved into a PGM file."""
  format = file_object.readline().strip()
  dimensions = [int(x) for x in file_object.readline().strip().split()]
  dimensions = (dimensions[1], dimensions[0])
  value_range = int(file_object.readline().strip())
  bits = numpy.log2(value_range + 1)
  assert bits == 8 or bits == 16
  if bits == 16:
    datatype = numpy.dtype('>u2')
  else:
    datatype = numpy.dtype('>u1')
  read_data = numpy.fromfile(file_object, dtype=datatype)
  return read_data.reshape(dimensions)


def ReadMetadata(file_object):
  """Read the metadata output by DCRAW."""
  for line in file_object:
    line = line.split(':')
    if len(line) > 1:
      key = line[0].strip()
      value = line[1].strip()
      yield key, value


def ParseShutterSpeed(value):
  """Parses the shutter speed field."""
  return eval(value.split(' ')[0])


def BayerCell(image, color):
  """Extract pixels from the Bayer cell."""
  # Pas sûr du tout...
  _OFFSETS = {
    'r': (1, 1),
    'g1': (0, 1),
    'g2': (1, 0),
    'b': (0, 0)
  }
  assert color in _OFFSETS
  offsets = _OFFSETS[color]
  return image[offsets[0]::2, offsets[1]::2]


def CenterCrop(image, crop_size):
  """Crops the image to the target size (centered)."""
  offset_x = (image.shape[0] - crop_size[0]) / 2
  offset_y = (image.shape[1] - crop_size[1]) / 2
  return image[offset_x - 1:-offset_x, offset_y - 1:-offset_y]


def AnalyzeImage(image, color='r', crop_size=(400, 600)):
  """Collects useful image stats."""
  image = BayerCell(image, color)
  image = CenterCrop(image, crop_size=crop_size)
  median = numpy.median(image.reshape(-1, 1))[0]
  return image.min(), image.mean(), image.max(), image.std()


def LoadDngFile(file_name, convert=True):
  """Loads a RAW file."""
  base_name = os.path.splitext(file_name)[0]
  if convert:
    ConvertDngFile(file_name)
  image = ReadRawPgmImage(file(base_name + '.pgm'))
  metadata = dict(ReadMetadata(file(base_name + METADATA_EXTENSION)))
  return image, metadata
  

def main():
  logging.info('Converting DNGs')
  for file_name in GetFiles('.dng'):
    ConvertDngFile(file_name)

  logging.info('Collecting per-image stats')
  files = list(GetFiles('.pgm'))
  stats = numpy.zeros((len(files), 5))
  for i, file_name in enumerate(files):
    logging.info('Analyse de %s' % file_name)
    image, metadata = LoadDngFile(file_name, convert=False)
    stats[i, 0] = ParseShutterSpeed(metadata['Shutter'])
    stats[i, 1:] = list(AnalyzeImage(image))

  logging.info('Generating graphs')
  indices = numpy.argsort(stats[:, 0])
  pl.subplot(211)
  pl.plot(numpy.log2(stats[indices, 0] / REFERENCE_EXPOSURE),
          numpy.log2(1.0 + stats[indices, 1:4]))
  pl.xlabel('ev')
  pl.xticks(numpy.arange(-8,8))
  pl.ylabel('bits')
  pl.yticks(numpy.arange(0,12))
  pl.grid()

  pl.subplot(212)
  # Trace de l'histogramme de bruit pour l'image la plus sombre du lot.
  darkest = stats[:, 2].argmin()
  image, _ = LoadDngFile(files[darkest], convert=False)
  image = CenterCrop(BayerCell(image, 'r'), crop_size=(400, 600))
  counts = pl.hist(image, numpy.arange(0, image.max()))

  pl.savefig('plot.png')


if __name__ == '__main__':
  main()
