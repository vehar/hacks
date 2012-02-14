import sys

MULTIPLIERS = {
  'p': 1e-12,
  'n': 1e-9,
  'u': 1e-6,
  'm': 1e-3,
  'k': 1e3,
  'M': 1e6,
}

def process_bom(f):
  parts = {}
  for line in list(file(f))[8:]:
    tokens = line.split()
    if len(tokens) == 7:
      name, value, package, lib, _, _, _ = tuple(tokens)
    else:
      name, package, lib, _, _, _ = tuple(tokens)
      value = ''
    part_type = ''.join([x for x in name if x not in '0123456789'])
    parts.setdefault(part_type, {}).setdefault(value, []).append(name)

  for values in parts.values():
    for value, occurrences in values.items():
      print ', '.join(occurrences) + '\t\t' + value + '\t' + str(len(occurrences))


def main(args):
  for arg in args:
    process_bom(arg)


if __name__ == '__main__':
  main(sys.argv[1:])
