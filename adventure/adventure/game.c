
#include<stdio.h>
#include<stdlib.h>
#include "game.h"
#include "world.h"
#include "room.h"

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
    game->world = create_world();
    
    struct room* garden = create_room("garden1", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
    struct room* garden2 = create_room("garden2", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
    struct room* garden3 = create_room("garden3", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
    struct room* garden4 = create_room("garden4", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
    struct room* garden5 = create_room("garden5", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
    struct room* garden6 = create_room("garden6", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
    struct room* garden7 = create_room("garden7", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
    struct room* garden8 = create_room("garden8", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
    struct room* garden9 = create_room("garden9", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
    struct room* garden10 = create_room("garden10", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
    struct room* garden11 = create_room("garden11", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
    struct room* garden12 = create_room("garden12", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
    struct room* garden13 = create_room("garden13", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
    struct room* garden14 = create_room("garden14", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
    struct room* garden15 = create_room("garden15", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
    struct room* garden16 = create_room("garden16", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
    struct room* garden17 = create_room("garden17", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
   
    add_room_to_world(game->world,garden );
    add_room_to_world(game->world,garden2 );
    add_room_to_world(game->world,garden3 );
    add_room_to_world(game->world,garden4 );
    add_room_to_world(game->world,garden5 );
    add_room_to_world(game->world,garden6 );
    add_room_to_world(game->world,garden7 );
    add_room_to_world(game->world,garden8 );
    add_room_to_world(game->world,garden9 );
    add_room_to_world(game->world,garden10 );
    add_room_to_world(game->world,garden11 );
    add_room_to_world(game->world,garden12 );
    add_room_to_world(game->world,garden13 );
    add_room_to_world(game->world,garden14 );
    add_room_to_world(game->world,garden15 );
    add_room_to_world(game->world,garden16 );
    add_room_to_world(game->world,garden17);
    
    struct item* item = create_item("SKALA", "Pokial nie si sochar tak si ju prestan vsimat.", USABLE | EXAMINABLE);
    struct item* item2 = create_item("SKALA2", "Pokial nie si sochar tak si ju prestan vsimat.2", USABLE);
    struct item* item3 = create_item("SKALA3", "Pokial nie si sochar tak si ju prestan vsimat.2", USABLE);
    struct item* item4 = create_item("SKALA4", "Pokial nie si sochar tak si ju prestan vsimat.2", USABLE);
    struct item* item5 = create_item("SKALA5", "Pokial nie si sochar tak si ju prestan vsimat.2", USABLE);
    struct item* item6 = create_item("SKALA6", "Pokial nie si sochar tak si ju prestan vsimat.2", USABLE);
    
    add_item_to_room(garden, item);
    add_item_to_room(garden, item2);
    add_item_to_room(garden, item3);
    add_item_to_room(garden, item4);
    add_item_to_room(garden, item5);
    add_item_to_room(garden, item6);
    
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
