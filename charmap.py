#!/usr/bin/env python3

ranges = [
    [0x60, 0x40, 0xa0]
]

for r in ranges:
    source, size, target = r
    for i in range(size):
        print("#pragma charmap (0x%02x, 0x%02x);" % (i + source, i + target))
