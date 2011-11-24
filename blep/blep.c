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

#include "blep.h"
#include "blep_table.h"
#include "reciprocal_table.h"

#include <string.h>
#include <stdio.h>

const uint32_t kWrap24bits = 0x00ffffff;

void blep_init(BlepOscillator* me) {
  me->phase = 0;
  me->phase_increment = 0;
  memset(me->blep_pool, 0, sizeof(me->blep_pool));
  me->lru_blep = 0;
  me->pw = kWrap24bits >> 1;
}

void blep_set_increment(BlepOscillator* me, uint32_t increment) {
  me->phase_increment = increment;
}

void blep_set_pw(BlepOscillator* me, double pulse_width) {
  me->pw = kWrap24bits * pulse_width;
}

uint16_t blep_phase_fraction(uint32_t a, uint32_t b) {
  return (BLEP_OVERSAMPLING * a) / b;
}

uint16_t blep_phase_fraction_fast(uint32_t a, uint32_t b) {
  // Shift by 8 if we have a very high value.
  if ((b >> 16) & 0xff) {
    b >>= 8;
    a >>= 8;
  }
  // Shift until the divisor is below 256.
  while (b >> 8) {
    b >>= 1;
    a >>= 1;
  }
  // Very rare case where a > b, used when PWM is modulated.
  // Add 1 to the result.
  uint16_t result = 0;
  while (a > b) {
    result += 256;
    a -= b;
  }
  result += ((reciprocal_table[b] * a) >> 8);
  return result;
}

void blep_add_blep(
    BlepOscillator* me,
    uint32_t phase_remainder,
    int8_t scale) {
  me->lru_blep = (me->lru_blep + 1) % BLEP_POOL_SIZE;
#ifdef BLEP_NO_DIVISION
  uint16_t blep_phase = blep_phase_fraction_fast(
    phase_remainder,
    me->phase_increment);
#else
  uint16_t blep_phase = blep_phase_fraction(
    phase_remainder,
    me->phase_increment);
#endif  // BLEP_NO_DIVISION
  me->blep_pool[me->lru_blep].phase = blep_phase;
  me->blep_pool[me->lru_blep].scale = scale;
}

int16_t blep_accumulate_bleps(BlepOscillator* me) {
  int16_t result = 0;
  // Unroll-me!
  for (uint8_t i = 0; i < BLEP_POOL_SIZE; ++i) {
    if (me->blep_pool[i].scale) {
      int32_t value = blep[me->blep_pool[i].phase];
      result += (value * me->blep_pool[i].scale) >> 7;
      me->blep_pool[i].phase += BLEP_OVERSAMPLING;
      if (me->blep_pool[i].phase >= BLEP_TABLE_SIZE) {
        me->blep_pool[i].scale = 0;
      }
    }
  }
  return result;
}

int16_t blep_render_saw(BlepOscillator* me) {
  me->phase = (me->phase + me->phase_increment) & kWrap24bits;
  if (me->phase < me->phase_increment) {
    blep_add_blep(me, me->phase, me->previous_sample);
  }
  int16_t output = (me->phase >> 9) - 16384;
  me->previous_sample = me->phase >> 17;
  output += blep_accumulate_bleps(me);
  return output;
}

int16_t blep_render_dual_saw(BlepOscillator* me) {
  me->phase = (me->phase + me->phase_increment) & kWrap24bits;
  if (me->phase < me->phase_increment) {
    blep_add_blep(me, me->phase, me->previous_sample);
    me->secondary_phase = me->phase + me->pw;
  }
  
  me->secondary_phase = (me->secondary_phase + me->phase_increment) & kWrap24bits;
  if (me->secondary_phase < me->phase_increment) {
    blep_add_blep(me, me->secondary_phase, me->secondary_previous_sample);
  }
  
  int16_t output = me->phase >> 10;
  output += me->secondary_phase >> 10;
  output -= 16384;
  me->previous_sample = me->phase >> 18;
  me->secondary_previous_sample = (me->phase + me->pw) >> 18;
  output += blep_accumulate_bleps(me);
  return output;
}

int16_t blep_render_square(BlepOscillator* me) {
  me->phase = (me->phase + me->phase_increment) & kWrap24bits;
  if (me->up) {
    if (me->phase >= me->pw) {
      blep_add_blep(me, me->phase - me->pw, 32767 >> 8);
      me->up = 0;
    }
  } else {
    if (me->phase < me->phase_increment) {
      blep_add_blep(me, me->phase, -32767 >> 8);
      me->up = 1;
    }
  }
  int16_t output = me->up ? 16383 : -16384;
  output += blep_accumulate_bleps(me);
  return output;
}

uint8_t blep_has_completed_cycle(BlepOscillator* me) {
  return me->phase < me->phase_increment;
}

void blep_reset_phase(BlepOscillator* me) {
  me->phase = -me->phase_increment;
}
