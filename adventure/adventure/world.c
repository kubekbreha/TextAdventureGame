//
//  world.c
//  adventure
//
//  Created by Jakub Brehuv on 10/05/2018.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"world.h"

struct container* create_world(){
    struct container* cont = (struct container*)calloc(1, sizeof(struct container));
  
    cont->command = NULL;
    cont->item = NULL;
    cont->room = NULL;
    cont->text = NULL;
    cont->next = NULL;
   
    return cont;
}

struct container* add_room_to_world(struct container* world, struct room* room){
    if(world == NULL || room == NULL){
        return NULL;
    }
    
    world->room = room;
    return world;
}

struct container* destroy_world(struct container* world){
    if(world == NULL){
        return NULL;
    }
    free(world);
    return NULL;
}

struct room* get_room(struct container* world, char* name){
    if(world == NULL || name == NULL){
        return NULL;
    }
    if(strlen(name)<1){
        return NULL;
    }

    struct container* container = world;
    
    while (world != NULL){
        if (container->room->name == name)
            return container->room;
        container = container->next;
    }
    return NULL;
}
