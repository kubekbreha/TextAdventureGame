
#include <stdio.h>

#include "command.h"
#include "room.h"
#include "item.h"
#include "backpack.h"
#include "container.h"
#include "game.h"
#include "world.h"

int main(int argc, const char * argv[]) {
    
//    struct command* help = create_command("POMOC", "Zobrazi zoznam vsetkych prikazov", NULL, 0);
//    printf("%s\n%s\n", help->name, help->description);

    
//   printf( "--------------------TEST BACKPACK--------------------------------\n");

//    struct backpack* back = create_backpack(3);
//    struct item* itemA = create_item("SKALA1", "Pokial nie si sochar tak si ju prestan vsimat.", USABLE | EXAMINABLE);
//    struct item* itemB = create_item("SKALA2", "Pokial nie si sochar tak si ju prestan vsimat.", USABLE );
//    struct item* itemC = create_item("SKALA3", "Pokial nie si sochar tak si ju prestan vsimat.", USABLE );
//
//    add_item_to_backpack(back, itemA);
//    add_item_to_backpack(back, itemB);
//    add_item_to_backpack(back, itemC);
//
//
//    delete_item_from_backpack(back, itemB);
//
//    if(get_item_from_backpack(back, itemB->name) == NULL){
//        printf("hure \n");
//    }

  //  print_backpack(back);

//    printf( "--------------------TEST ROOM--------------------------------\n");
//    struct item* item = create_item("KLUC", "Touto vecou sa odomykaju ine veci.", MOVABLE | USABLE | EXAMINABLE);
//    if(create_container(NULL, ITEM, item) != NULL){printf("hura");}

//    struct room* garden = create_room("garden", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
//
//    struct item* item = create_item("SKALA", "Pokial nie si sochar tak si ju prestan vsimat.", USABLE | EXAMINABLE);
//    struct item* item2 = create_item("SKALA2", "Pokial nie si sochar tak si ju prestan vsimat.2", USABLE);
//    struct item* item3 = create_item("SKALA3", "Pokial nie si sochar tak si ju prestan vsimat.2", USABLE);
//    struct item* item4 = create_item("SKALA4", "Pokial nie si sochar tak si ju prestan vsimat.2", USABLE);
//    struct item* item5 = create_item("SKALA5", "Pokial nie si sochar tak si ju prestan vsimat.2", USABLE);
//
//    add_item_to_room(garden, item);
//    add_item_to_room(garden, item2);
//    add_item_to_room(garden, item3);
//    add_item_to_room(garden, item4);
//    add_item_to_room(garden, item5);
//
//    delete_item_from_room(garden, item5);
//    delete_item_from_room(garden, item4);
//    delete_item_from_room(garden, item3);
//
//
//    if(get_from_container_by_name(garden->items,"SKaLA5") != NULL){
//        printf("hure\n");
//    }
//
//    show_room(garden);
//
//    create_game();
//
    
//    struct room* room = create_room("Thief Guild", "The Thief Guild is a dark den of unprincipled types. You clutch your purse (though several other people here would like to clutch your purse as well).");
//    struct item* item = create_item("SKALA", "Pokial nie si sochar tak si ju prestan vsimat.", NONE);
//    struct item* item2 = create_item("SKALA2", "Pokial nie si sochar tak si ju prestan vsimat.", NONE);
//    struct item* item3 = create_item("SKALA3", "Pokial nie si sochar tak si ju prestan vsimat.", NONE);
//    add_item_to_room(room, item);
//    add_item_to_room(room, item2);
//    add_item_to_room(room, item3);
//
//    delete_item_from_room(room, item2);
//    if(get_item_from_room(room, item2->name) == NULL){
//        printf("hura\n");
//    };
//
//    print_room(room->items);
    
    
    
    struct room* item0 = create_room("intrak", "Velmi smradlava izba");
    struct room* item1 = create_room("intrak2", "Velmi smradlava izba2");
    struct room* item2 = create_room("intrak3", "Velmi smradlava izba3");
    struct room* item3 = create_room("intrak4", "Velmi smradlava izba4");
    
    struct container* world = add_room_to_world(world, item0);
    add_room_to_world(world, item1);
    add_room_to_world(world, item2);
    add_room_to_world(world, item3);
    
    printf("%s\n", get_room(world, "intrak2")->name);
    
    return 0;
}
