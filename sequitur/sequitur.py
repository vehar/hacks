# Copyright (C) 2006 Olivier Gillet
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

"""
Given a string s, infer a compact grammar producing exactly s.

http://en.wikipedia.org/wiki/Sequitur_algorithm
"""

import math

max_terminals = 10000

def negentropy(p):
  p = [float(pi) / sum(p) for pi in p]
  return -sum([pi * math.log(pi) for pi in p]) / math.log(2)  


class Sequitur:
  """
  Embeds a set of rule and all the state information: bigrams dictionary,
  Lookup-table for tokens, rule indices
  """
  def __init__(self, seq):
    self.clean()
    self.root = Rule(self)
    self.extend(seq)
    
  def clean(self):
    """
    def clean(self)
    
    Clean the rule counter, the bigrams table and the symbol lookup table
    """
    self.num_rules = 0
    self.lut = dict()
    self.bigrams = dict()
    self.root = None
  
  def lookup(self, tag):
    """
    def lookup(self, tag)
    
    Search for a symbol in the lookup table
    """
    if len(self.lut) >= max_terminals:
      raise OverflowError("Too many terminals!")
    return self.lut.setdefault(tag, len(self.lut) + 1)
  
  def bits(self):
    """
    def bits(self)
    
    Compute an approximation of the number of bits
    Needed to store the grammar
    """
    rhs_count = self.root.rhs_distrib()
    # Assumption that the RHS symbols are independent
    bits_per_symbol = negentropy(rhs_count)
    symbols = sum(rhs_count)
    return bits_per_symbol * symbols
    
  def append(self, token):
    """
    def append(self, token)
    
    Update the grammar with a new token 
    """
    new_token = Terminal(self.lookup(token), token, self)
    self.root.last().insert(new_token)
    self.root.last().prev.check()
    
  def extend(self, sequence):
    """
    def extend(self, sequence)
    
    Update the grammar with a new sequence (iterable)
    """
    for item in sequence:
      self.append(item)
      
  def __repr__(self):
    return self.root.__repr__()


class Rule:
  def __init__(self, parent):
    parent.num_rules = parent.num_rules + 1
    self.guard = Guard(self, parent)
    self.ref_count = 0
    self.number = parent.num_rules
    
  def add_bigram(self, A, B):
    pos = self.last()
    pos.insert(A)
    pos.next.insert(B)
    
  def first(self):
    return self.guard.next

  def last(self):
    return self.guard.prev
  
  def traverse(self, rule_cbk, symbol_cbk):
    """
    def traverse(self, rule_cbk, symbol_cbk)
    
    Traverse the rule and its sub-rules.
    rule is called whenever a new rule is encountered.
    symbol is called whenever a new symbol is encountered.
    """
    to_visit = [self]
    indices = {self: 0}
    while len(to_visit) > 0:
      rule = to_visit.pop(0)
      sym = rule.first()
      rule_cbk(rule, indices[rule])
      while not sym.is_guard():
        ref_rule = None
        if sym.is_non_terminal():
          ref_rule = sym.rule
          if not indices.get(ref_rule):
            indices[ref_rule] = len(indices)
            to_visit.append(ref_rule)
        symbol_cbk(sym, indices.get(ref_rule))
        sym = sym.next
    
  def rhs_distrib(self):
    items = {}
    def rule_cbk(rule, indice):
      pass
    def symbol_cbk(sym, indice):
      items[sym.value] = items.setdefault(sym.value, 0) + 1
    self.traverse(rule_cbk, symbol_cbk)
    return items.values()
    
  def __repr__(self):
    output = []
    line = []
    def rule_cbk(rule, indice):
      if len(line):
        output.append(" ".join(line))
      del line[:]
      line.append("R%d -> " % indice)
      
    def symbol_cbk(sym, indice):
      if sym.is_non_terminal():
        line.append("R%d" % indice)
      else:
        line.append(sym.__atom_repr__())
    
    self.traverse(rule_cbk, symbol_cbk)
    if len(line):
      output.append(" ".join(line))
    return "\n".join(output)

class Symbol:
  def __init__(self, parent):
    self.prev = None
    self.next = None
    self.bigrams = parent.bigrams
    self.parent = parent
    
  def link(self, right):
    if self.next:
      self.delete_bigram()
      if right.prev and right.next and right.value == right.prev.value and right.value == right.next.value:
        self.bigrams[right] = right
      if self.prev and self.next and self.value == self.next.value and self.value == self.prev.value:
        self.bigrams[self.prev] = self.prev
    self.next = right
    right.prev = self
    
  def insert(self, middle):
    middle.link(self.next)
    self.link(middle)
  
  def delete_bigram(self):
    if self.next.is_guard():
      return
    if self.bigrams.get(self) is self:
      del self.bigrams[self]
      
  def is_guard(self):
    return False
    
  def is_non_terminal(self):
    return False
    
  def check(self):
    if self.next.is_guard():
      return False
    found = self.bigrams.get(self)
    if not found:
      self.bigrams[self] = self
      return False
    if not (found.next is self):
      self.match(self, found)
    return True
    
  def substitute(self, rule):
    q = self.prev
    q.next.delete()
    q.next.delete()
    q.insert(NonTerminal(rule, self.parent))
    if not q.check():
      q.next.check()
  
  def match(self, bigram_for_new_rule, matching):
    if matching.prev.is_guard() and matching.next.next.is_guard():
      rule = matching.prev.rule
      bigram_for_new_rule.substitute(rule)
    else:
      rule = Rule(self.parent)
      rule.add_bigram(bigram_for_new_rule.clone(), bigram_for_new_rule.next.clone())
      matching.substitute(rule)
      bigram_for_new_rule.substitute(rule)
      self.bigrams[rule.first()] = rule.first()
      
    if rule.first().is_non_terminal() and (rule.first().rule.ref_count == 1):
      rule.first().expand()
      
  def __eq__(self, other):
    return (self.value == other.value) and (self.next.value == other.next.value)
    
  def __hash__(self):
    return (21599 * self.value + 20507 * self.next.value) % 2265539

  def __repr__(self):
    return "%s,%s" % (self.__atom_repr__(), self.next.__atom_repr__())


class NonTerminal(Symbol):
  def __init__(self, rule, parent):
    Symbol.__init__(self, parent)
    self.rule = rule
    rule.ref_count = rule.ref_count + 1
    self.value = max_terminals + self.rule.number
    
  def delete(self):
    self.prev.link(self.next)
    self.delete_bigram()
    self.rule.ref_count = self.rule.ref_count - 1
    
  def is_non_terminal(self):
    return True
  
  def clone(self):
    return NonTerminal(self.rule, self.parent)
  
  def expand(self):
    left = self.prev
    right = self.next
    f = self.rule.first()
    l = self.rule.last()
    
    self.rule.guard.rule = None
    self.rule.guard = None
    
    found = self.bigrams[self]
    if found is self:
      del self.bigrams[self]
    
    left.link(f)
    l.link(right)
    self.bigrams[l] = l
    
  def __atom_repr__(self):
    return "Non terminal %d" % (self.value)
    

class Terminal(Symbol):
  def __init__(self, value, tag, parent):
    Symbol.__init__(self, parent)
    self.value = value
    self.tag = tag
    
  def delete(self):
    self.prev.link(self.next)
    self.delete_bigram()
  
  def __atom_repr__(self):
    return "%s" % self.tag
    
  def clone(self):
    return Terminal(self.value, self.tag, self.parent)
    

class Guard(Symbol):
  def __init__(self, rule, parent):
    Symbol.__init__(self, parent)
    self.rule = rule
    self.value = id(rule)
    self.prev = self
    self.next = self
    
  def delete(self):
    self.prev.link(self.next)
    
  def is_guard(self):
    return True
    
  def delete_bigram(self):
    pass
    
  def check(self):
    return False
    
  def __atom_repr__(self):
    return "#"
    
  def clone(self):
    return Guard(self.rule, parent)
  

if __name__ == "__main__":
  tests = [
  """
  I am Sam 
  I am Sam 
  Sam I am 

  That Sam I am
  Than Sam I am 
  I do not like
  that Sam I am 

  Do you like
  green eggs and ham

  I do not like them
  Sam I am
  I do not like
  green eggs and ham

  Would you like them
  here or there

  I would not like them
  here or there
  I would not like them
  anywhere
  I do not like
  green eggs and ham
  I do not like them
  Sam I am

  Would you like them
  in a house
  Would you like them
  with a mouse

  I do not like them 
  in a house
  I do not like them 
  with a mouse
  I do not like them
  here or there
  I do not like them
  anywhere
  I do not like green eggs and ham
  I do not like them Sam I am

  Would you eat them
  in a box
  Would you eat them
  with a fox

  Not in a box
  Not with a fox
  Not in a house
  Not with a mouse
  I would not eat them here or there
  I would not eat them anywhere
  I would not eat green eggs and ham
  I do not like them Sam I am

  Would you Could you
  In a car 
  Eat them Eat them
  Here they are

  I would not
  could not
  in a car

  You may like them
  You will see
  You may like them
  in a tree

  I would not could not in a tree
  Not in a car You let me be

  I do not like them in a box
  I do not like them with a fox
  I do not like them in a house
  I do not like them with a mouse
  I do not like them here or there
  I do not like them anywhere
  I do not like green eggs and ham
  I do not like them Sam I am

  A train A train
  A train A train
  Could you would you
  on a train

  Not on a train Not in a tree
  Not in a car Sam Let me be

  I would not could not in a box
  I could not would not with a fox
  I will not eat them with a mouse
  I will not eat them in a house
  I will not eat them here or there
  I will not eat them anywhere
  I do not eat green eggs and ham
  I do not like them Sam I am

  Say
  In the dark
  Here in the dark
  Would you could you in the dark

  I would not could not
  in the dark

  Would you could you in the rain

  I would not could not
  in the rain
  Not in the dark Not on a train
  Not in a car Not in a tree
  I do not like them Sam you see
  Not in a house Not in a box
  Not with a mouse Not with a fox
  I will not eat them here or there
  I do not like them anywhere

  You do not like
  green eggs and ham

  I do not
  like them
  Sam I am

  Could you would you
  with a goat

  I would not
  could not
  with a goat

  Would you could you
  on a boat 

  I could not would not on a boat
  I will not will not with a goat
  I will not eat them in the rain
  I will not eat them on a train
  Not in the dark Not in a tree
  Not in a car You let me be
  I do not like them in a box
  I do not like them with a fox
  I will not eat them in a house
  I do not like them with a mouse
  I do not like them here or there
  I do not like them ANYWHERE

  I do not like
  green eggs
  and ham

  I do not like them
  Sam I am

  You do not like them
  So you say
  Try them Try them
  And you may
  Try them and you may I say

  Sam
  If you will let me be
  I will try them
  You will see

  Say
  I like green eggs and ham
  I do I like them Sam I am
  And I would eat them in a boat
  And I would eat them with a goat

  And I will eat them in the rain
  And in the dark And on a train
  And in a car And in a tree
  They are so good so good you see

  So I will eat them in a box
  And I will eat them with a fox
  And I will eat them in a house
  And I will eat them with a mouse
  And I will eat them here and there
  Say I will eat them ANYWHERE

  I do so like
  green eggs and ham
  Thank you
  Thank you
  Sam I am
  """
  ]
  for sequence in tests:
    s = Sequitur(sequence.split())
    print s