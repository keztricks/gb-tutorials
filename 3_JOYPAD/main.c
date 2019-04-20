#include <gb/gb.h>
#include <stdio.h>
#include "birb-sprite.c"

void main() {
    UINT8 spriteIndex = 0;
    UINT8 x = 8;
    UINT8 y = 35;
    UINT8 movementSpeed = 10;
    set_sprite_data(0, 2, birb);
    set_sprite_tile(0, 0);
    move_sprite(0, x, y);
    SHOW_SPRITES;

    while (TRUE) {
        switch(joypad()) {
            case J_LEFT:
                if (spriteIndex == 0) {
                    spriteIndex = 1;
                } else {
                    spriteIndex = 0;
                }
                set_sprite_tile(0, spriteIndex);
                if (x > 10) {
                    x = x - movementSpeed;
                    move_sprite(0, x, y);
                }
                break;
            case J_RIGHT:
                if (spriteIndex == 0) {
                    spriteIndex = 1;
                } else {
                    spriteIndex = 0;
                }
                set_sprite_tile(0, spriteIndex);
                if (x < 150) {
                    x = x + movementSpeed;
                    move_sprite(0, x, y);
                }
                break;
            case J_UP:
                if (spriteIndex == 0) {
                    spriteIndex = 1;
                } else {
                    spriteIndex = 0;
                }
                set_sprite_tile(0, spriteIndex);
                if (y > 10) {
                    y = y - movementSpeed;
                    move_sprite(0, x, y);
                }
                break;
            case J_DOWN:
                if (spriteIndex == 0) {
                    spriteIndex = 1;
                } else {
                    spriteIndex = 0;
                }
                set_sprite_tile(0, spriteIndex);
                if (y < 147) {
                    y = y + movementSpeed;
                    move_sprite(0, x, y);
                }
                break;
        }
        delay(100);
    }
}
