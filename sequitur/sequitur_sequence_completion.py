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
Given a sequence with gaps marked with a ? character, replace the ? by other
tokens in the sequence so that to maximize the compressibility of the string
using the sequitur algorithm.

Two optimizers are provided: simulated annealing and genetic algorithms.
"""

from sequitur import Sequitur

import sets
import math
import random
import copy

debug = False

def mutate(sequence, probabilities, alphabet, nmutations):
  seq = copy.copy(sequence)
  for i in range(0,nmutations):
    indices = [i for (i,x) in enumerate(probabilities) if x < 1]
    index = random.choice(indices)
    prob = probabilities[index]
    if random.uniform(0,1) > prob:
      seq[index] = random.choice(alphabet)
  return seq

      
def crossover(papa, maman):
  fiston = copy.copy(papa) # Political statement !
  crossover_point = random.randint(0, len(papa))
  fiston[0:crossover_point] = maman[0:crossover_point]
  return fiston
    

def bits_reduction_GA(sequence, probabilities):
  # Get the alphabet
  alphabet = sets.Set(sequence)
  if not "?" in alphabet:
    return sequence
  alphabet.remove("?")
  alphabet = list(alphabet)
  
  GA_population = 30
  GA_generations = 25
  GA_growth_rate = 5 #RABBIT
  
  population = []
  
  GA_cache = {}
  
  # Generate initial population
  for i in range(0,GA_population*GA_growth_rate):
    s = []
    for e in sequence:
      if e == "?":
        s.append(random.choice(alphabet))
      else:
        s.append(e)
    population.append( (GA_cache.setdefault(str(s), Sequitur(s).bits()), s)  )
  
  # For each generation
  for i in range(0, GA_generations):
    print "Generation %d" % i
    # Survival of the fittest
    population.sort()
    population = population[0:GA_population]

    # Create new individuals
    for i in range(0, GA_population * (GA_growth_rate - 1)):
      # Reproduction
      papa = random.choice(population)
      maman = random.choice(population)
    
      # Cross-over and mutation
      fiston = mutate(crossover(papa[1], maman[1]), probabilities, alphabet, 2)
      population.append(  (GA_cache.setdefault(str(fiston), Sequitur(fiston).bits()), fiston)  )
    
    print sum([negfitness for (negfitness, sequence) in population])/len(population)
  population.sort()
  return population[0][1]


def bits_reduction_annealing(sequence, probabilities):
  # Get the alphabet
  alphabet = sets.Set(sequence)
  if not "?" in alphabet:
    return sequence
  alphabet.remove("?")
  
  # Stores the best value and the best sequence
  E = Sequitur(sequence).bits()
  best = (E, copy.copy(sequence))
  
  # Annealing scheduling
  trials_per_round = 100
  successful_trials = 10
  
  temperature = 1.0
  temperature_steps = 25
  temperature_decrease_factor = 0.95
  
  evals = 1
    
  for step in range(0,temperature_steps):
    
    if debug: print "Temp: %f" % temperature
    
    changes = 0
    for i in range(0, trials_per_round):
      
      # Select an element that can be modified
      indices = [i for (i,x) in enumerate(probabilities) if x < 1]
      index = random.choice(indices)
      prob = probabilities[index]
    
      # Save the old item
      old_item = sequence[index]
    
      # Calculate the new energy
      sequence[index] = random.choice(list(alphabet))
      nE = Sequitur(sequence).bits()
      evals = evals + 1
    
      # Check if state change is allowed
      # Always allowed when a smaller energy configuration is reached
      if nE < E:
        allowed = True
      else:
        # Otherwise, do metropolis sampling!
        allowed = (1-prob) * math.exp((E - nE) / temperature) > random.uniform(0,1)
        if debug: print "DE: %f -> %s" % (new_bits-current_bits, str(allowed))
      
      # Cancel modification
      if not allowed:
        sequence[index] = old_item
      # Validate state change
      else:
        changes = changes + 1
        E = nE
        
        if E < best[0]:
          best = (E, copy.copy(sequence))
        
        if changes == successful_trials:
          break
    
      #(E, sequence) = best
    if changes == 0:
      break
      
    temperature = temperature * temperature_decrease_factor
  
  print evals 
  if debug: print best
  return sequence


if __name__ == "__main__":
  a = "B-H-S-H-B-H-S-H-B-H-S-H?B???????"
  print Sequitur(a)
  print
  probs = [int(i != '?') for i in a]
  new_a = bits_reduction_GA(list(a), probs)
  
  print " ".join(new_a)
  result = Sequitur(new_a)
  print result
  print result.bits()
  