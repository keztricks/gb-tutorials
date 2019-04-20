#include <gb/gb.h>
#include <stdio.h>
#include "birb-sprite.c"

void main() {
    UINT8 spriteIndex = 0;
    UINT8 birbX = 8;
    UINT8 birbY = 35;
    set_sprite_data(0, 2, birb);
    set_sprite_tile(0, 0);
    move_sprite(0, birbX, birbY);
    SHOW_SPRITES;

    while (TRUE) {
        delay(300);
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
    }
}
