#include <stdint.h>
#include <conio.h>
#include <peekpoke.h>
#include <vic20.h>

#include "charmap.h"

int main() {
    uint16_t i;
    uint16_t j;

    //POKE()
    bgcolor(COLOR_BLACK);
    bordercolor(COLOR_BLACK);
    textcolor(COLOR_CYAN);
    clrscr();
    cputs("\r\n");
    cputs("\r\n");
    cputs("\r\n");
    cputs("\r\n");
    cputs("\r\n");
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 16; i++) {
            POKE(0x1000 + 2 + i + j * 22, i + (8 + j) * 16);
        }
    }
    cputs("Hamburger      $ 1.20\r\n");
    cputs("Fries          $ 0.90\r\n");
    cputs("\r\n");
    for (i = 0; i < 21; i++) {
        POKE(0x1000 + 7*22 + i, 1);
    }
    cputs("Total          $ 2.10\r\n");

    // enable 8x16 characters, with 11 lines
    VIC.linecount = 2*11 + 1;

    // video RAM start at default, 0x1000, but change character table to 0x1400
    VIC.addr = 0xcd;

    while (1);

    return 0;
}
