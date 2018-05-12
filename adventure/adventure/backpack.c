
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
    if(item == NULL || backpack == NULL){
        return false;
    }
    
    if(backpack->capacity >= backpack->size){
        if(backpack->items == NULL){
            printf("--empty backpack\n");
            struct container* new_container = (struct container*)calloc(1, sizeof(struct container));
            new_container->type = ITEM;
            new_container->item= item;
            new_container->next= NULL;
            backpack->size++;
            
            backpack->items = new_container;
            return true;
        }else{
            struct container* container;
            container = backpack->items;
            while (container->next != NULL){
                container = container->next;
                printf("--NOT empty backpack\n");
            }
            struct container* new_container = (struct container*)calloc(1, sizeof(struct container));
            new_container->type = ITEM;
            new_container->item= item;
            new_container->next= NULL;
            backpack->size++;
            container->next = new_container;
            return true;
        }
    }
    return false;
}


void delete_item_from_backpack(struct backpack* backpack, struct item* item){
    if(backpack == NULL || item == NULL) return;
    
    if(backpack->items->next == NULL){
        free(backpack->items);
        //backpack->size--;
        return;
    }else{
        struct container* container;
        container = backpack->items;
        
        for (int i = 0; i < backpack->size; i++){
            if(container->item == item){
                printf("found item %d\n", i);
            
                if(i == backpack->size-1 ){
                    free(container->next);
                    backpack->size--;
                    break;
                }else{
                    struct container* temp = container->next;
                    container->item = container->next->item;
                    container->next = temp->next;
                    free(temp);
                    backpack->size--;
                }
                return;
            }else{
                printf("NOT found item %d\n", i);
                container = container->next;
            }
        }
    }
}

void print_backpack(struct backpack* backpack){
        struct container* container;
        container = backpack->items;
    
        for (int i = 0; i < backpack->size; i++){
        
                printf("found: %s\n", container->item->name);
                container = container->next;
        
            }
    }


struct item* get_item_from_backpack(const struct backpack* backpack, char* name){
    if(backpack == NULL || name == NULL){
        return NULL;
    }
    if(strlen(name)<1 ){
        return NULL;
    }
    
    struct container* container = backpack->items;
    
    while (container != NULL){
        if (container->item->name == name)
            return container->item;
        else
            container = container->next;
    }
    return NULL;
}
