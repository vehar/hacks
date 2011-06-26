#!/usr/bin/python2.6
#
# Author: Olivier Gillet (ol.gillet@gmail.com)

"""Shows a task progress bar on a text terminal."""

import fcntl
import struct
import sys
import termios
import time

sys.path.append('.')

_CAPTION_WIDTH = 40
_PROGRESS_WIDTH = 10


class TextProgressBar(object):
  """Text progress bar."""
  
  def __init__(self, caption):
    self._caption = caption[:_CAPTION_WIDTH]
    self._max_progress = 0
    self._progress = 0
    self._start_time = 0
    self._started = False
    
  def set_max_progress(self, max_progress):
    self._max_progress = max(self._max_progress, max_progress)

  def Start(self):
    self._start_time = time.time()
    self._progress = 0
    self._started = True
    self._Draw()
  
  def IncrementBy(self, increment):
    self._progress += increment
    self._Draw()
    
  def Finish(self):
    self._started = False
    self._progress = self._max_progress
    self._Draw()
    sys.stderr.write('\n')
  
  @property
  def _window_size(self):
    buffer = fcntl.ioctl(sys.stderr, termios.TIOCGWINSZ, 'xxxxxxxx')
    return struct.unpack('hhhh', buffer)[1]
  
  def _Draw(self):
    width = max(self._window_size, 80)
    line = '\r' + self._caption
    line += ' ' * (_CAPTION_WIDTH - len(self._caption))
    line += '\x1b[94m[\x1b[92m'
    if not self._started and self._progress == self._max_progress:
      line += '\x1b[0m'
    pb_width = width - _CAPTION_WIDTH - 2 - _PROGRESS_WIDTH - 2
    filled_width = self._progress * pb_width / self._max_progress
    line +=  '=' * filled_width
    line += '\x1b[0m'
    line += '.' * (pb_width - filled_width)
    line += '\x1b[94m]\x1b[0m'
    if not self._started and self._progress == self._max_progress:
      line += ' %.1fs' % (time.time() - self._start_time)
    else:
      line += ' %d%%' % ((self._progress * 100) / self._max_progress)
    sys.stderr.write(line)


if __name__ == '__main__':
  pb = TextProgressBar('Fooing')
  pb.set_max_progress(1000)
  for i in xrange(1000):
    pb.IncrementBy(1)
    t = time.time()
    while (time.time() - t) < 0.005:
      pass
  pb.Finish()
