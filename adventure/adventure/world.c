

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"world.h"

struct container* create_world(){
    struct container* world = (struct container*)calloc(1, sizeof(struct container));
    world->next = NULL;
    world->room = NULL;
    return world;
}


struct container* add_room_to_world(struct container* world, struct room* room){
    if(world == NULL){
        world = create_world();
    }
    
    if(room == NULL){
        return NULL;
    }
    
    while(world->next != NULL){
        world = world->next;
    }
    
    
    world->room = room;
    world->next = NULL;
    
    return world;
}

struct container* destroy_world(struct container* world){
    if(world == NULL){
        return NULL;
    }
    free(world);
    world = NULL;
    return world;
}


struct room* get_room(struct container* world, char* name){
    if(world == NULL || name == NULL){
        return NULL;
    }
    if(strlen(name)<1){
        return NULL;
    }

    struct container* container = world;
    
    while (world->next != NULL){
        if (container->room->name == name)
            return container->room;
        container = container->next;
    }
    return NULL;
}
