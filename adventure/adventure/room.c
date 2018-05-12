//
//  room.c
//  adventure
//
//  Created by Jakub Brehuv on 10/05/2018.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "room.h"
#include "container.h"

/*
 struct room {
 char* name;                 /// name of the room/location
 char* description;          /// description of the room/location
 struct room *north;         /// reference to the room on north
 struct room *south;         /// reference to the room on south
 struct room *east;          /// reference to the room on east
 struct room *west;          /// reference to the room on west
 struct container* items;    /// list of items in the room/location
 };
 */

struct room* create_room(char *name, char *description){
    if(name == NULL || description== NULL){
        return NULL;
    }
    if(strlen(name)<1 || strlen(description)<1){
        return NULL;
    }
    
    struct room* new_room = (struct room*)calloc(1, sizeof(struct room));
    new_room->name = name;
    new_room->description = description;
    new_room->north = NULL;
    new_room->south = NULL;
    new_room->east = NULL;
    new_room->west = NULL;
    new_room->items = NULL;
    return new_room;
}

struct room* destroy_room(struct room* room){
    free(room);
    return NULL;
}


void set_exits_from_room(struct room *room, struct room *north, struct room *south, struct room *east, struct room *west){
    if(room == NULL){
        return;
    }
    room->north = north;
    room->south = south;
    room->east = east;
    room->west = west;
}

void show_room(const struct room* room){
    printf("%s\n", room->description);
    printf("Pokracovat mozes na:\n");
    if(room->north!= NULL)
        printf("sever\n");
    if(room->south!= NULL)
        printf("juh\n");
    if(room->east!= NULL)
        printf("vychod\n");
    if(room->west!= NULL) 
        printf("zapad\n");
}

void delete_item_from_room(struct room* room, struct item* item){
    if(room == NULL || item == NULL) return;
    
    if(room->items->next == NULL){
        free(room->items->next);
        return;
    }else{
        struct container* container;
        container = room->items;
        
        while(container->next != NULL){
            if(container->item == item){
                
                struct container* temp = container->next;
                container->item = container->next->item;
                container->next = temp->next;
                free(temp);
                return;
            }
            if(container->next->next == NULL ){
                struct container* temp = container->next;
                container->next = temp->next;
                free(temp);
                return;
            }
            container = container->next;
        }
    }
}
    



void add_item_to_room(struct room* room, struct item* item){
    if(room == NULL || item == NULL){
        return;
    }
    
    if(room->items == NULL){
    
        struct container* new_container = (struct container*)calloc(1, sizeof(struct container));
        new_container->type = ITEM;
        new_container->item= item;
        new_container->next= NULL;
        
        room->items = new_container;
  
    }else{
        struct container* container;
        container = room->items;
        while (container->next != NULL){
            container = container->next;
        }
        struct container* new_container = (struct container*)calloc(1, sizeof(struct container));
        new_container->type = ITEM;
        new_container->item= item;
        new_container->next= NULL;
        
        container->next = new_container;
    }
}


struct item* get_item_from_room(const struct room* room, const char* name){
    if(room == NULL || name == NULL){
        return NULL;
    }
    if(strlen(name)<1){
        return NULL;
    }
    
    struct container* container = room->items;
    
    while (container != NULL){
        if (container->item->name == name)
            return container->item;
        container = container->next;
    }
    return NULL;
}


