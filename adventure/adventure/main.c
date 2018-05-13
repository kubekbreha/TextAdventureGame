
#include <stdio.h>

#include "command.h"
#include "room.h"
#include "item.h"
#include "backpack.h"
#include "container.h"
#include "game.h"

int main(int argc, const char * argv[]) {
    
//    struct command* help = create_command("POMOC", "Zobrazi zoznam vsetkych prikazov", NULL, 0);
//    printf("%s\n%s\n", help->name, help->description);

    
   printf( "--------------------TEST BACKPACK--------------------------------\n");

    struct backpack* back = create_backpack(3);
    struct item* itemA = create_item("SKALA1", "Pokial nie si sochar tak si ju prestan vsimat.", USABLE | EXAMINABLE);
    struct item* itemB = create_item("SKALA2", "Pokial nie si sochar tak si ju prestan vsimat.", USABLE );
    struct item* itemC = create_item("SKALA3", "Pokial nie si sochar tak si ju prestan vsimat.", USABLE );

//    add_item_to_backpack(back, itemA);
//    add_item_to_backpack(back, itemB);
    printf("%d\n", add_item_to_backpack(back, itemB));


    //delete_item_from_backpack(back, itemB);

    if(get_item_from_backpack(back, itemC->name) != NULL){
        printf("hure %s\n", itemC->name);
    }

    print_backpack(back);

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
//    //show_room(garden);
//
//    create_game();
    
    return 0;
}
