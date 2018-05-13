

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"world.h"

struct container* create_world(){
    struct container* world = (struct container*)calloc(1, sizeof(struct container));
    world->room = create_room("intrakad", "Velmi smradlava izba");
//    world->room->west = create_room("intrak2", "Velmi smradlava izba2");
//    world->room->north = create_room("intrak3", "Velmi smradlava izba3");
//    world->room->south = create_room("intrak4", "Velmi smradlava izba4");
    return world;
}


struct container* add_room_to_world(struct container* world, struct room* room){
    if(world == NULL){
        world = create_world();
    }
    
    if(room == NULL){
        return NULL;
    }
    
    struct container* newWorld = (struct container*)calloc(1, sizeof(struct container));

    if(newWorld == NULL){
        fprintf(stderr, "Unable to allocate memory for new node\n");
        exit(-1);
    }
    
    newWorld->room = room;
    newWorld->next = NULL;
    
    if(world->next == NULL){
        world->next = newWorld;
        printf("added at beginning\n");
    }
    
    else{
        struct container* current = world;
        while (true) {
            if(current->next == NULL){
                current->next = newWorld;
                printf("added later\n");
                break; // Change 3
            }
            current = current->next;
        };
    }
    
    free(newWorld);
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
    
    while (container != NULL){
        if (strcmp(container->room->name,name))
            return container->room;
        container = container->next;
    }
    return NULL;
}
