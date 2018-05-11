//
//  main.c
//  adventure
//
//  Created by Jakub Brehuv on 10/05/2018.
//

#include <stdio.h>

#include "command.h"
#include "room.h"
#include "item.h"
#include "backpack.h"
#include "container.h"


int main(int argc, const char * argv[]) {
    
    struct command* help = create_command("POMOC", "Zobrazi zoznam vsetkych prikazov", NULL, 0);
    printf("%s\n%s\n", help->name, help->description);
    
    struct backpack* back = create_backpack(3);
    struct item* itemB = create_item("SKALA1B", "Pokial nie si sochar tak si ju prestan vsimat.", USABLE | EXAMINABLE);
    struct item* itemB2 = create_item("SKALA12", "Pokial nie si sochar tak si ju prestan vsimat.", USABLE );
    struct item* itemB3 = create_item("SKALA1C", "Pokial nie si sochar tak si ju prestan vsimat.", USABLE );
    add_item_to_backpack(back, itemB);
    add_item_to_backpack(back, itemB2);
    add_item_to_backpack(back, itemB3);
    
    
    
    struct room* home = create_room("start", "Nachadzas sa v chyzi svarneho suhaja. Na vychode sa nachadzaju dvere veduce z chyze von.");
    struct room* garden = create_room("garden", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
    
    
    struct item* item = create_item("SKALA", "Pokial nie si sochar tak si ju prestan vsimat.", USABLE | EXAMINABLE);
    struct item* item2 = create_item("SKALA2", "Pokial nie si sochar tak si ju prestan vsimat.2", USABLE);
//    struct item* item3 = create_item("SKALA3", "Pokial nie si sochar tak si ju prestan vsimat.2", USABLE);
//    struct item* item4 = create_item("SKALA4", "Pokial nie si sochar tak si ju prestan vsimat.2", USABLE);
//    struct item* item5 = create_item("SKALA5", "Pokial nie si sochar tak si ju prestan vsimat.2", USABLE);
    
    add_item_to_room(garden, item);
    add_item_to_room(garden, item2);
//    add_item_to_room(garden, item3);
//    add_item_to_room(garden, item4);
//    add_item_to_room(garden, item5);
    
    // show room
    show_room(home);
    
    printf("-=-=-=-=-=-=-=-=-=-=\n");
    show_room(garden);
    if(NULL != get_item_from_room(garden, "SKALA")){
        printf("hura\n");
    }
    
    printf("-=-=-=-=-=-=-=-=-=-=\n");
    show_room(garden);
    
    return 0;
}
