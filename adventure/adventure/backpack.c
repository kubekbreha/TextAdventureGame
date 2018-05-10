//
//  backpack.c
//  adventure
//
//  Created by Jakub Brehuv on 10/05/2018.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include "backpack.h"


struct backpack* create_backpack(const int capacity){
    struct backpack* back = (struct backpack*)calloc(1, sizeof(struct backpack));
    back->capacity = capacity;
    back->items = NULL;
    back->size = 0;
    
    return back;
}


struct backpack* destroy_backpack(struct backpack* backpack){
    free(backpack);
    return NULL;
}


bool add_item_to_backpack(struct backpack* backpack, struct item* item){
    return false;
}

void delete_item_from_backpack(struct backpack* backpack, struct item* item){
    
}

struct item* get_item_from_backpack(const struct backpack* backpack, char* name){
    return NULL;
}
