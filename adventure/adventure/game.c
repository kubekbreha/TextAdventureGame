//
//  game.c
//  adventure
//
//  Created by Jakub Brehuv on 11/05/2018.
//

#include<stdio.h>
#include<stdlib.h>
#include "game.h"

/*struct game{
 enum gamestate      state;          /// game state
 struct parser*      parser;         /// command line parser
 struct container*   world;          /// list of all rooms
 struct room*        current_room;   /// reference to the current room
 struct backpack*    backpack;       /// player's backpack
 };
 */

void play_game(struct game* game){
    
}

struct game* create_game(void){
    struct game* game = (struct game*)calloc(1, sizeof(struct game));
    game->parser= NULL;
    game->world= NULL;
    game->current_room= NULL;
    game->backpack= NULL;
    return game;
}

struct game* destroy_game(struct game* game){
    free(game);
    return NULL;
}

void execute_command(struct game* game, struct command* command){
  
}
