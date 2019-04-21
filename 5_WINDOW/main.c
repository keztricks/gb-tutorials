#include <gb/gb.h>
#include <stdio.h>
#include "background-tiles.c"
#include "background.c"
#include "window-map.c"
#include <gb/font.h>


void main() {
    font_t minFont;

    font_init();

    minFont = font_load(font_min);
    font_set(minFont);

    set_bkg_data(37, 16, backgroundTiles);
    set_bkg_tiles(0, 0, 40, 18, background);

    set_win_tiles(0, 0, 5, 1, windowMap);
    move_win(0, 135);

    SHOW_BKG;
    SHOW_WIN;
    DISPLAY_ON;

    delay(1000);

    windowMap[1] = 0x17;
    set_win_tiles(0, 0, 5, 1, windowMap);

    // while (TRUE) {
    //     scroll_bkg(1, 0);
    //     delay(100);
    // }

}
