#!/usr/bin/env python3
from PIL import Image
import numpy as np

im = Image.open("bizcat.bmp")
im = im.convert('RGBA')
p = np.array(im)

print('#pragma data-name ("FONT")')
print('')
print('unsigned char font[] = {')
for i in range(256):
    print("    ", end = '');
    for y in range(16):
        d = 0
        for x in range(8):
            r, g, b, a = p[y + i // 16 * 16][x + (i % 16) * 8]
            if r == 0:
                d |= 1 << ( 7 - x)
        print("0x%02x, " % d, end = '');
    print("");
print('};')
