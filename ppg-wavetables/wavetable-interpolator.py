import numpy
import os


_DATA_CHUNK_HEADER_SIZE = 8
_FMT_CHUNK_DATA_SIZE = 16
_FMT_CHUNK_HEADER_SIZE = 8
_RIFF_FORMAT_DESCRIPTOR_SIZE = 4


def load_ppg_waves():
  raw_waves = numpy.fromfile('data/ppg.bin', dtype=numpy.uint8)
  waves = []
  for i in xrange(0, 16384, 64):
    half = raw_waves[i:i + 64]
    wave = numpy.hstack((half, -half[:0:-1])).astype(float)
    wave[64] = wave[63] / 2 + wave[65] / 2
    wave[-1] = wave[0] / 2 + wave[-2] / 2
    # Remove the high frequencies introduced by the mirroring and possibly
    # by patching the two halves of the waveform.
    wave_f = numpy.fft.rfft(wave)
    wave_f[len(wave_f) / 2:] = 0
    wave = numpy.fft.irfft(wave_f)
    waves.append((wave - 128.0) / 128.0)
  return waves


def mw_interpolate_wavetable(waves, wavetable, target_wave_size=256, steps=16):
  intervals = zip(wavetable[:-1], wavetable[1:])
  wavetable = numpy.zeros((target_wave_size * steps,))
  for step in xrange(steps):
    mw_t = (step * 60.0 / steps)
    while True:
      (t_1, w_1), (t_2, w_2) = intervals[0]
      end = t_2 * steps / 60.0
      if mw_t > t_2:
        intervals.pop(0)
      else:
        break
    gain = float(mw_t - t_1) / float(t_2 - t_1)
    wave = waves[w_2] * gain + waves[w_1] * (1.0 - gain)
    scale = target_wave_size / float(len(wave))
    wave = numpy.fft.irfft(numpy.fft.rfft(wave), target_wave_size)
    wave *= scale
    wavetable[step * target_wave_size:(step + 1) * target_wave_size] = wave
  m = numpy.abs(wavetable).max()
  wavetable /= numpy.abs(wavetable.max())
  wavetable *= 127
  wavetable += 128
  return wavetable.astype(numpy.uint8)
  

waves = load_ppg_waves()
wavetables = {
  'bellish': [(0, 2), (24, 1), (48, 0), (60, 1)],
  'resonant': [(0, 101), (8, 69), (16, 70), (24, 71), (32, 72), (40, 73),
               (48, 74), (60, 75)],
  'resonant2': [(0, 77), (8, 78), (16, 79), (24, 80), (32, 81), (40, 82),
                (48, 83), (60, 84)],
  'malletsyn': [(0, 101), (30, 47), (38, 131), (46, 132), (55, 141), (60, 142)],
  'sqr_sweep': [(0, 101), (8, 94), (16, 95), (24, 96), (32, 97), (40, 98),
                (60, 100)],
  'pul_sweep': [(0, 131), (8, 132), (16, 141), (24, 142), (32, 143), (60, 144)],
  'saw_sweep': [(0, 101), (8, 54), (16, 55), (24, 56), (32, 57), (40, 88),
                (48, 89), (54, 53), (60, 104)],
  'mellow_saw': [(0, 114), (20, 115), (40, 116), (60, 99)],
  'feedback': [(0, 108), (24, 65), (40, 63), (60, 90)],
  'add_harm': [(0, 101), (7, 61), (16, 62), (24, 63), (32, 66), (40, 67),
               (60, 68)],
  'reso3hp': [(0, 42), (14, 43), (30, 44), (46, 45), (60, 46)],
  'wind_syn': [(0, 41), (16, 40), (32, 39), (48, 38), (60, 37)],
  'high_harm': [(0, 101), (8, 54), (16, 55), (24, 56), (32, 57), (40, 58),
                (48, 59), (60, 60)],
  'clipper': [(0, 241), (8, 242), (16, 243), (24, 244), (32, 245), (40, 241),
              (48, 242), (60, 243)],
  'organ_syn': [(0, 101), (12, 5), (24, 6), (36, 85), (48, 8), (60, 48)],
  'square_saw': [(0, 12), (20, 11), (50, 53), (60, 104)],
  'formant1': [(2 * i, 146 + i) for i in xrange(31)],
  'polated': [(0, 106), (8, 109), (14, 113), (22, 90), (27, 13), (60, 113)],
  'transient': [(0, 85), (8, 85), (16, 86), (24, 91), (32, 62), (40, 71),
               (48, 86), (56, 85), (60, 85)],
  'electrip': [(0, 117), (28, 117), (40, 116), (52, 119), (60, 119)],
  'electrip': [(0, 117), (28, 117), (40, 116), (52, 119), (60, 119)],
  'robotic': [(0, 101), (3, 101), (4, 80), (7, 80), (8, 69), (11, 69),
              (12, 81), (15, 81), (16, 70), (19, 70), (20, 82), (23, 82),
              (24, 71), (27, 71), (28, 83), (31, 83), (32, 72), (35, 72),
              (36, 84), (39, 84), (40, 73), (43, 73), (44, 85), (47, 85),
              (48, 74), (60, 74)],
  'stronghrm': [(0, 32), (12, 30), (17, 29), (22, 28), (27, 27), (32, 26), 
                (37, 25), (42, 24), (46, 23), (50, 22), (55, 21), (60, 21)],
  'percorgan': [(0, 32), (14, 33), (15, 32), (29, 34), (30, 32), (43, 35), 
                (44, 32), (60, 36)],
  'clipsweep': [(0, 136), (8, 136), (20, 137), (32, 138), (44, 139), (56, 140), 
                (60, 140)],
  'resonantharm': [(10 * i, 106 + i) for i in xrange(7)],
  '2echoes': [(0, 101), (16, 112), (17, 101), (32, 113), (33, 101), (48, 112),
              (49, 101), (60, 91)],
  'formant2': [(2 * i, 178 + i) for i in xrange(31)]}


for name, table in wavetables.items():
  wt = mw_interpolate_wavetable(waves, table, steps=16, target_wave_size=128)
  file(os.path.join('wavetables', name + '.bin'), 'w').write(wt.tostring())
