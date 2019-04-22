#include <gb/gb.h>
#include <stdio.h>
#include "GameCharacter.c"
#include "../assets/shipBug-sprite.c"


GameCharacter ship;
GameCharacter bug;
UBYTE spriteSize = 8;


void performantDelay(UINT8 numLoops) {
    UINT8 i;
    for (i = 0; i < numLoops; i++) {
       wait_vbl_done();
    }
}

void moveGameCharacter(GameCharacter* character, UINT8 x, UINT8 y) {  // * is pass by ref/pointer
    move_sprite(character->spriteIDs[0], x, y);
    move_sprite(character->spriteIDs[1], x + spriteSize, y);
    move_sprite(character->spriteIDs[2], x, y + spriteSize);
    move_sprite(character->spriteIDs[3], x + spriteSize, y + spriteSize);
}

void setupShip() {
    ship.x = 80;
    ship.y = 130;
    ship.width = 16;
    ship.height = 16;

    set_sprite_tile(0, 0);
    ship.spriteIDs[0] = 0;
    set_sprite_tile(1, 2);
    ship.spriteIDs[1] = 1;
    set_sprite_tile(2, 1);
    ship.spriteIDs[2] = 2;
    set_sprite_tile(3, 3);
    ship.spriteIDs[3] = 3;

    moveGameCharacter(&ship, ship.x, ship.y);
}

void setupBug(){
    bug.x = 30;
    bug.y = 0;
    bug.width = 16;
    bug.height = 16;    

    // load sprites for bug
    set_sprite_tile(4, 4);
    bug.spriteIDs[0] = 4;
    set_sprite_tile(5, 6);
    bug.spriteIDs[1] = 5;
    set_sprite_tile(6, 5);
    bug.spriteIDs[2] = 6;
    set_sprite_tile(7, 7);
    bug.spriteIDs[3] = 7;

    moveGameCharacter(&bug, bug.x, bug.y);
}

void main() {
    set_sprite_data(0, 8, shipBug);
    setupShip();
    setupBug();
    DISPLAY_ON;
    SHOW_SPRITES;

    while(TRUE) {
        if(joypad() & J_LEFT){
            ship.x -= 2;
            moveGameCharacter(&ship, ship.x, ship.y);
        }
        if(joypad() & J_RIGHT){
            ship.x += 2;
            moveGameCharacter(&ship, ship.x, ship.y);
        }

        bug.y += 5;
        moveGameCharacter(&bug, bug.x, bug.y);

        if(bug.y >= 144){
           bug.y=0;
           bug.x = ship.x;
       }

        performantDelay(5);
    }

}
