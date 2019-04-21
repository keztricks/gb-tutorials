#include <gb/gb.h>
#include <stdio.h>
#include "background-tiles.c"
#include "background.c"
#include "birb-sprite.c"

void main() {
    UINT8 spriteIndex = 0;
    UINT8 birbX = 8;
    UINT8 birbY = 35;
    UINT8 count = 0;
    set_sprite_data(0, 2, birb);
    set_sprite_tile(0, 0);
    move_sprite(0, birbX, birbY);
    set_bkg_data(0, 16, backgroundTiles);
    set_bkg_tiles(0, 0, 40, 18, background);

    SHOW_BKG;
    DISPLAY_ON;

    SHOW_SPRITES;

    while (TRUE) {
        scroll_bkg(1, 0);
        delay(100);

        if (count == 2) {
            if (spriteIndex == 0) {
                spriteIndex = 1;
                birbY = 30;
            } else {
                spriteIndex = 0;
                birbY = 35;
            }
            birbX = birbX + 5;
            move_sprite(0, birbX, birbY);
            set_sprite_tile(0, spriteIndex);
            if (birbX > 150) {
                birbX = 0;
            }
            count = 0;
        }
        count++;
    }

}
