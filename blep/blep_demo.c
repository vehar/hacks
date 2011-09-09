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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "blep.h"

const double kSampleRate = 44100.0;

// Converts a frequency to a 24-bits phase increment
uint32_t phase_increment(double frequency) {
  return (int)((1 << 24) * frequency / kSampleRate);
}

// Converts a MIDI note number to a frequency
double midi_to_hertz(double midi_note) {
  return 440.0 * pow(2.0, (midi_note - 69.0) / 12.0);
}

uint8_t division_groundtruth(uint32_t a, uint32_t b) {
  return (256 * a) / b;
}

uint8_t division_fast(uint32_t a, uint32_t b) {
  return (256 * a) / b;
}

void write_wav_header(FILE* fp, int num_samples) {
  // Writes the WAV header for 16-bits mono PCM data.
  char data[4];
  uint32_t l;
  uint16_t s;
  
  fwrite("RIFF", 4, 1, fp);
  l = 36 + num_samples * 2;
  fwrite(&l, 4, 1, fp);
  fwrite("WAVE", 4, 1, fp);
  
  fwrite("fmt ", 4, 1, fp);
  l = 16;
  fwrite(&l, 4, 1, fp);
  s = 1;
  fwrite(&s, 2, 1, fp);
  fwrite(&s, 2, 1, fp);
  l = kSampleRate;
  fwrite(&l, 4, 1, fp);
  l = kSampleRate * 2;
  fwrite(&l, 4, 1, fp);
  s = 2;
  fwrite(&s, 2, 1, fp);
  s = 16;
  fwrite(&s, 2, 1, fp);
  
  fwrite("data", 4, 1, fp);
  l = num_samples * 2;
  fwrite(&l, 4, 1, fp);
}

int main(int argc, char** argv) {
  // Create .wav header.
  FILE* square_fp = fopen("square.wav", "wb");
  FILE* saw_fp = fopen("saw.wav", "wb");
  write_wav_header(square_fp, kSampleRate * 3);
  write_wav_header(saw_fp, kSampleRate * 3);
  
  // Initialize BLEP structure.
  BlepOscillator saw;
  BlepOscillator square;
  blep_init(&saw);
  blep_init(&square);

  // Render a sweep.
  for (int i = 0; i < kSampleRate * 5; ++i) {
    // Update modulations.
    if ((i % 40) == 0) {
      double note = 60 + 48 * sin(i * 4.0 / kSampleRate);
      double pw = 0.5 + 0.3 * sin(i * 17.0 / kSampleRate);
      blep_set_pw(&square, pw);
      blep_set_increment(&saw, phase_increment(midi_to_hertz(note)));
      blep_set_increment(&square, phase_increment(midi_to_hertz(note)));
    }
    
    // Compute samples and write them to a WAV file.
    int16_t saw_sample = blep_render_saw(&saw);
    int16_t square_sample = blep_render_square(&square);
    fwrite(&saw_sample, sizeof(int16_t), 1, saw_fp);
    fwrite(&square_sample, sizeof(int16_t), 1, square_fp);
  }

  fclose(square_fp);
  fclose(saw_fp);
  
  /*while (1) {
    uint32_t b = rand() % 0xffffff;
    uint32_t a = rand() % b;
    uint8_t x = division_groundtruth(a, b);
    uint8_t y = division_fast(a, b);
    if (x != y) {
      printf("%d %d %d %d\n", a, b, x, y);
    }
  }*/
}
