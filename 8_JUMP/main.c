#include <gb/gb.h>
#include <stdio.h>
#include "../assets/frontMan-sprite.c"

INT8 playerLocation[2];
BYTE jumping;
UINT8 gravity = -2;
UINT8 currentSpeedY;
UINT8 floorYPosition = 100;

void performantDelay(UINT8 numLoops) {
    UINT8 i;
    for (i = 0; i < numLoops; i++) {
       wait_vbl_done();
    }
}

INT8 wouldHitSurface(UINT8 projectedYPosition) {
    if (projectedYPosition >= floorYPosition) {
        return floorYPosition;
    } else {
        return -1;
    }
}

void jump(UINT8 spriteID, UINT8 spriteLocation[2]) {
    INT8 possibleSurfaceY;
    if (jumping == 0) {
        jumping = 1;
        currentSpeedY = 10;
        set_sprite_tile(spriteID, 1);
    }

    currentSpeedY += gravity;

    spriteLocation[1] = spriteLocation[1] - currentSpeedY;

    possibleSurfaceY = wouldHitSurface(spriteLocation[1]);

    if (possibleSurfaceY > -1) {
        jumping = 0;
        currentSpeedY = 0;
        spriteLocation[1] = possibleSurfaceY;
        set_sprite_tile(spriteID, 0);
    }
    move_sprite(spriteID, spriteLocation[0], spriteLocation[1]);
}

void main() {

    UBYTE joypadState = joypad();

    set_sprite_data(0, 2, frontMan);
    set_sprite_tile(0, 0);

    playerLocation[0] = 10;
    playerLocation[1] = floorYPosition;
    move_sprite(0, playerLocation[0], playerLocation[1]);

    jumping = 0;
    DISPLAY_ON;
    SHOW_SPRITES;

    while(TRUE) {

        if((joypad() & J_A) || jumping == 1){
            jump(0, playerLocation);
        }

        if(joypad() & J_LEFT){
            playerLocation[0] = playerLocation[0] - 2;
            move_sprite(0, playerLocation[0], playerLocation[1]);
        }
        if(joypad() & J_RIGHT) {
            playerLocation[0] = playerLocation[0] + 2;
            move_sprite(0,playerLocation[0], playerLocation[1]);
        }
            performantDelay(5);
    }

}
