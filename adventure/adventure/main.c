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


int main(int argc, const char * argv[]) {
    
    struct command* help = create_command("POMOC", "Zobrazi zoznam vsetkych prikazov", NULL, 0);
    printf("%s\n%s\n", help->name, help->description);
    
    
    
    
    struct room* home = create_room("start", "Nachadzas sa v chyzi svarneho suhaja. Na vychode sa nachadzaju dvere veduce z chyze von.");
    struct room* garden = create_room("garden", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
    
    
    struct item* item = create_item("SKALA", "Pokial nie si sochar tak si ju prestan vsimat.", USABLE | EXAMINABLE);
    struct item* item2 = create_item("SKALA2", "Pokial nie si sochar tak si ju prestan vsimat.2", USABLE);
    
    add_item_to_room(garden, item);
     add_item_to_room(garden, item2);
    
    
    // show room
    show_room(home);
    
    printf("-=-=-=-=-=-=-=-=-=-=\n");
    show_room(garden);
    if(NULL != get_item_from_room(garden, "SKALA2")){
        printf("hura\n");
    }
    
    printf("-=-=-=-=-=-=-=-=-=-=\n");
    show_room(garden);
    
    return 0;
}
