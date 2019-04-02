#!/usr/bin/python2.5
#
# Counter on a status information page.
#
# Copyright (C) 2009 Emilie Gillet (emilie.o.gillet@gmail.com).
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

"""Counter on a status information page."""

import time


class Counter(object):
  def __init__(self):
    self._value = 0

  def set_value(self, value):
    self._value = value
    
  def value(self):
    return self._value
    
  def Increment(self):
    self._value += 1


class RateCounter(object):
  def __init__(self, interval):
    self._undo_list = []
    self._interval = interval
  
  def Increment(self):
    v = self.value()
    self._undo_list.append(time.time() + self._interval)
    
  def value(self):
    # TODO(pichenettes): use binary search instead to find the position
    # at which we have to slice. There is probably a better data structure for
    # this...
    while self._undo_list and self._undo_list[0] < time.time():
      self._undo_list.pop(0)
    return len(self._undo_list)


class MultipleRateCounter(object):
  def __init__(self, intervals):
    self._counters = [(i, RateCounter(i)) for i in intervals]
    
  def Increment(self):
    for _, counter in self._counters:
      counter.Increment()
      
  def value(self):
    return [(interval, c.value()) for (interval, c) in self._counters]


if __name__ == '__main__':
  s = MultipleRateCounter([1, 5, 10])
  s.Increment()
  s.Increment()
  time.sleep(3)
  s.Increment()
  s.Increment()
  while True:
    print s.value()
