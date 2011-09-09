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

#include <string.h>

const uint32_t kWrap24bits = 0x00ffffff;

void blep_init(BlepOscillator* me) {
  me->phase = 0;
  me->phase_increment = 0;
  memset(me->blep_pool, 0, sizeof(me->blep_pool));
  me->lru_blep = 0;
}

void blep_set_increment(BlepOscillator* me, uint32_t increment) {
  me->phase_increment = increment;
}

void blep_set_pw(BlepOscillator* me, double pulse_width) {
  me->pw = kWrap24bits * pulse_width;
}

void blep_add_blep(
    BlepOscillator* me,
    uint32_t phase_remainder,
    int16_t scale) {
  me->lru_blep = (me->lru_blep + 1) % BLEP_POOL_SIZE;
  uint16_t blep_phase = (BLEP_OVERSAMPLING * phase_remainder) / me->phase_increment;
  me->blep_pool[me->lru_blep].phase = blep_phase;
  me->blep_pool[me->lru_blep].scale = scale;
  me->blep_pool[me->lru_blep].active = 1;
}

int16_t blep_accumulate_bleps(BlepOscillator* me) {
  int16_t result = 0;
  // Unroll-me!
  for (uint8_t i = 0; i < BLEP_POOL_SIZE; ++i) {
    if (me->blep_pool[i].active) {
      int32_t value = blep[me->blep_pool[i].phase];
      result += (value * me->blep_pool[i].scale) >> 14;
      me->blep_pool[i].phase += BLEP_OVERSAMPLING;
      if (me->blep_pool[i].phase >= BLEP_TABLE_SIZE) {
        me->blep_pool[i].active = 0;
      }
    }
  }
  return result;
}

int16_t blep_render_saw(BlepOscillator* me) {
  me->phase = (me->phase + me->phase_increment) & kWrap24bits;
  if (me->phase < me->phase_increment) {
    blep_add_blep(me, me->phase, 32767);
  }
  int16_t output = (me->phase >> 9) - 16384;
  output += blep_accumulate_bleps(me);
  return output;
}

int16_t blep_render_square(BlepOscillator* me) {
  me->phase = (me->phase + me->phase_increment) & kWrap24bits;
  if (me->phase >= me->pw) {
    if (me->up) {
      blep_add_blep(me, me->phase - me->pw, 32767);
    }
    me->up = 0;
  }
  if (me->phase < me->phase_increment) {
    blep_add_blep(me, me->phase, -32767);
    me->up = 1;
  }
  int16_t output = me->up ? 16383 : -16384;
  output += blep_accumulate_bleps(me);
  return output;
}
