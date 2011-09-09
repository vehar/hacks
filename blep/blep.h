// Copyright 2011 Olivier Gillet.
//
// Author: Olivier Gillet (ol.gillet@gmail.com)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef BLEP_H_
#define BLEP_H_

#include <stdint.h>

#define BLEP_POOL_SIZE 4

typedef struct Blep {
  uint16_t phase;
  int16_t scale;
  uint8_t active;
} Blep;

typedef struct BlepOscillator {
  uint32_t phase;
  uint32_t phase_increment;
  uint32_t pw;
  uint8_t lru_blep;
  uint8_t up;
  Blep blep_pool[BLEP_POOL_SIZE];
} BlepOscillator;

void blep_init(BlepOscillator* me);
void blep_set_increment(BlepOscillator* me, uint32_t increment);
void blep_set_pw(BlepOscillator* me, double pulse_width);
void blep_add_blep(
    BlepOscillator* me,
    uint32_t phase_remainder,
  int16_t scale);
int16_t blep_accumulate_bleps(BlepOscillator* me);
int16_t blep_render_saw(BlepOscillator* me);
int16_t blep_render_square(BlepOscillator* me);

#endif  // BLEP_H_
