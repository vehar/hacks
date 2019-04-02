import os
import re
import urllib2

class TextileToTexConverter(object):

  DOCUMENT = """\documentclass[a4paper,10pt]{article}
\usepackage[latin1]{inputenc}
\usepackage[T1]{fontenc}
\usepackage[english]{babel}
\usepackage{pgfcore, pgfbaseimage}
\usepackage{tabularx}
\usepackage{fancyvrb}
\usepackage{hyperref}
\usepackage{color}
\\textwidth=6in
\\textheight=9in
\headheight=0in
\headsep=0in
\oddsidemargin=0in
\evensidemargin=0in
\\author{%(author)s}
\\title{%(title)s}
\date{}
\\renewcommand{\\familydefault}{\sfdefault}
\\begin{document}
\maketitle
%(body)s
\end{document}
"""

  HEADINGS = {
    'h2.': 'section',
    'h3.': 'subsection',
    'h4.': 'subsubsection',
  }
  
  TAGS = {
    '*': 'textbf',
    '_': 'textit',
    '@': 'texttt'
  }
  
  NAIVE_TRANSLATIONS = {
    '<lcd>': '\\begin{Verbatim}[frame=single,framerule=1mm,formatcom=\color{blue}]\n',
    '</lcd>': '\n\end{Verbatim}',
    '<pre>': '\\begin{verbatim}',
    '</pre>': '\end{verbatim}',
    '==<div class="error">': '\paragraph{Important}',
    '==<div class="warning">': '\paragraph{Warning}',
    '</div>==': '\n',
    '&': '\&',
    '%': '\%',
    '\&\&\&\&': '&',
    '#': '\#',
    '^': '|',
    '_': '\\_',
  }
  
  LIST_TYPES = {
    '#': 'enumerate',
    '*': 'itemize',
  }
  
  IMAGE_PATTERN = re.compile('![^ !]+!')
  LINK_PATTERN = re.compile('"[^"]+":[^ ]+')
  
  IMAGES_PATH = 'images'
  
  def __init__(self):
    self._fixes = [self.FixLists, self.FixImages, self.FixHeadings, self.FixTables, self.FixLinks]
    self._patterns_cache = {}
    
  def FixLinks(self, line):
    for occurrence in self.LINK_PATTERN.findall(line):
      parts = occurrence.split(':')
      anchor = parts[0]
      url = ':'.join(parts[1:]).strip('.()[]')
      anchor = anchor.strip('"')
      line = line.replace(occurrence, '\href{%s}{%s}' % (url, anchor))
    return line
    
  def FixLists(self, line):
    if self._current_list_type and (not line or line[0] != self._current_list_type):
      line = '\\end{%s}\n%s' % (self.LIST_TYPES[self._current_list_type], line)
      self._current_list_type = None
    if len(line) >= 2 and line[0] in self.LIST_TYPES and line[1] == ' ':
      if line[0] != self._current_list_type:
        self._current_list_type = line[0]
        line = '\\begin{%s}\n\item %s' % (self.LIST_TYPES[self._current_list_type], line[2:])
      else:
        line = '\\item ' + line[2:]
    return line
  
  def FixTables(self, line):
    if self._in_table:
      if line and line[0] == '|':
        line = line.strip('|').replace('|', ' & ') + ' \\\\'
        line = self.Protect(line)
      else:
        line = '\hline\n\end{tabularx}\n\end{small}\n' + line
        line = self.Protect(line)
        self._in_table = 0
    else:
      if line and line[0] == '|':
        columns = line.strip('|').replace('_.', '').split('|')
        num_columns = len(columns) - 1
        line = '\n\\begin{small}\\begin{tabularx}{\\textwidth}{|l|' + 'X|' * num_columns + '}\n\hline\n \\textbf{' + \
          '} & \\textbf{'.join(columns) + '} \\\\\n\hline'
        line = self.Protect(line)
        self._in_table = num_columns
    return line
    
  def Protect(self, line):
    for to_protect in '&_':
      line = line.replace(to_protect, 'pPpP' + to_protect + 'pPpP')
    return line
    
  def FixTag(self, line, tag, tex_tag):
    if not tag in self._patterns_cache:
      ttag = tag
      if tag in '*+[]()\\':
        ttag = '\\' + tag
      self._patterns_cache[tag] = [
        re.compile(' %s[^%s]+%s' % (ttag, ttag, ttag)),
        re.compile('^%s[^%s]+%s' % (ttag, ttag, ttag))]
    for pattern in self._patterns_cache[tag]:
      for occurrence in pattern.findall(line):
        line = line.replace(occurrence, '\\%s{ %s}' % (tex_tag, occurrence.strip(' ' + tag)))
    return line
    
  def FixImages(self, line):
    for occurrence in self.IMAGE_PATTERN.findall(line):
      url = occurrence[1:-1]
      name = os.path.split(url)
      local_version = os.path.join(self._image_path, name[-1])
      if not os.path.isfile(local_version):
        if not os.path.exists(self._image_path):
          os.mkdir(self._image_path)
        f = file(local_version, 'w')
        if not url.startswith('http'):
          url = os.path.join(self._root, url)
        f.write(urllib2.urlopen(url).read())
        f.close()
      width = 0.8
      if self._in_table:
        width /= self._in_table * 1.5
      if 'waveform' in local_version:
        width /= 4
      line = line.replace(
          occurrence,
          '\pgfimage[width=%.2f \\textwidth]{%s}' % (width, local_version))
      line = self.Protect(line)
    return line
  
  def FixHeadings(self, line):
    if len(line) > 3 and line[:3] in self.HEADINGS:
      line = '\\%s{%s}'% (self.HEADINGS[line[:3]], line[3:])
    return line
    
  def Convert(self, content, root, author='', title='', image_path=None):
    self._image_path = image_path or self.IMAGES_PATH
    self._root = root
    lines = content.split('\n')
    corrected_lines = []
    self._current_list_type = None
    self._in_table = 0
    for line in lines:
      for fix in self._fixes:
        line = fix(line)
      for tag, latex_tag in self.TAGS.items():
        line = self.FixTag(line, tag, latex_tag)
      for source, destination in self.NAIVE_TRANSLATIONS.items():
        line = line.replace(source, destination)
      willshow = 'prot' in line
      for source, destination in self.NAIVE_TRANSLATIONS.items():
        line = line.replace('pPpP' + destination + 'pPpP', source)
      while 'pPpP' in line:
        line = line.replace('pPpP', '')
      if willshow:
        print '>>>>', line
      corrected_lines.append(line)
    body = '\n'.join(corrected_lines)
    return self.DOCUMENT % locals()


if __name__ == '__main__':
  c = TextileToTexConverter()
  content = c.Convert(
      file('shruthi1.tx').read(),
      'http://mutable-instruments.net',
      author='Mutable Instruments',
      title='Digital control board assembly instructions')
  file('shruthi1_doc.tex', 'w').write(content)
