// Copyright 2011 Emilie Gillet.
//
// Author: Emilie Gillet (emilie.o.gillet@gmail.com)
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
#define BLEP_NO_DIVISION

typedef struct Blep {
  uint16_t phase;
  int8_t scale;
} Blep;

typedef struct BlepOscillator {
  uint32_t phase;
  uint32_t phase_increment;
  uint32_t pw;
  uint8_t lru_blep;
  uint8_t up;
  int8_t previous_sample;

  // They are used for the dual saw oscillator which gives a PWM effect
  // by mixing two dephased sawtooth waves.
  uint32_t secondary_phase;
  int8_t secondary_previous_sample;
  Blep blep_pool[BLEP_POOL_SIZE];
} BlepOscillator;

void blep_init(BlepOscillator* me);
void blep_set_increment(BlepOscillator* me, uint32_t increment);
void blep_set_pw(BlepOscillator* me, double pulse_width);
void blep_add_blep(
    BlepOscillator* me,
    uint32_t phase_remainder,
    int8_t scale);
int16_t blep_accumulate_bleps(BlepOscillator* me);
int16_t blep_render_saw(BlepOscillator* me);
int16_t blep_render_dual_saw(BlepOscillator* me);
int16_t blep_render_square(BlepOscillator* me);

uint8_t blep_has_completed_cycle(BlepOscillator* me);
void blep_reset_phase(BlepOscillator* me);

#endif  // BLEP_H_
