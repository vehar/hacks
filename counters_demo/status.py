#!/usr/bin/python2.5
#
# Basic status page, serving both json and html info.
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

"""Basic status page.

Can be used in external python code through the counter, export_counter and
Start(port) methods.

Can also be used stand-alone, in this case:
python status.py counters.cfg /tmp/counter 10 10000

Will read a list of counters from counters.cfg, and will read increment
updates from the fifos called /tmp/counter-00 ... /tmp/counter-09.
The status page will be served on port 10000. To tick a counter, simply write
its name followed by a \n to the fifo.

counters.cfg contains comment lines (starting by #), a counter name and optional
int arguments. When there is no argument, this is a simple event counter. When
there is int arguments x y, the counter counts the number of events per x, y
seconds.
"""

import BaseHTTPServer
import os
import sys
import threading

import simplejson

import rate_counter

_counters = {}

def counter(name):
  return _counters.setdefault(name, rate_counter.Counter())


def export_counter(name, counter):
  _counters[name] = counter


class StatusHandler(BaseHTTPServer.BaseHTTPRequestHandler):
  def RenderHtml(self):
    global _counters
    for name in sorted(_counters.keys()):
      self.wfile.write('<b>%s</b>: %s<br />' % (name, _counters[name].value()))

  def RenderJson(self):
    global _counters
    d = dict([(name, _counters[name].value()) for name in _counters.keys()])
    self.wfile.write(simplejson.dumps(d))
  
  def do_GET(self):
    if self.path != '/status' and self.path != '/status.json':
      self.send_error(404, 'Not found')
    else:
      self.send_response(200)
      self.send_header('Content-type', 'text/html')
      self.end_headers()
      if self.path == '/status':
        self.RenderHtml()
      else:
        self.RenderJson()


class StatusServerThread(threading.Thread):
  def __init__(self, httpd):
    threading.Thread.__init__(self)
    self._httpd = httpd
  
  def run(self):
    self._httpd.serve_forever()


def Start(port):
  server_address = ('', port)
  httpd = BaseHTTPServer.HTTPServer(server_address, StatusHandler)
  thread = StatusServerThread(httpd)
  thread.setDaemon(True)
  thread.start()


def CreateCountersFromConfigFile(config_file):
  for line in file(config_file):
    # Skip comments.
    if line[0] == '#':
      continue
    # Otherwise, parse the line.
    tokens = line.strip().split()
    if len(tokens) == 1:
      export_counter(tokens[0], rate_counter.Counter())
    else:
      rates = map(int, tokens[1:])
      export_counter(tokens[0], rate_counter.MultipleRateCounter(rates))


class FIFOReaderThread(threading.Thread):
  def __init__(self, fifo_name):
    threading.Thread.__init__(self)
    # Remove the fifo.
    try:
      os.unlink(fifo_name)
    except Exception:
      pass

    # Recreate the fifo and read from it.
    os.mkfifo(fifo_name)
    self._fifo_name = fifo_name
  
  def run(self):
    while True:
      for line in file(self._fifo_name):
        counter(line.strip()).Increment()
    

if __name__ == '__main__':
  if len(sys.argv) != 5:
    print 'Usage: status.py base_config_file num_fifos fifo_name port'
    sys.exit(1)
  # Initialize the counters and spawn the server thread.
  CreateCountersFromConfigFile(sys.argv[1])
  Start(int(sys.argv[4]))
  
  for fifo_num in range(int(sys.argv[3])):
    name = '%s-%02d' % (sys.argv[2], fifo_num)
    FIFOReaderThread(name).start()
