//
//  container.c
//  adventure
//
//  Created by Jakub Brehuv on 10/05/2018.
//

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#include"container.h"


//enum container_type {
//    ROOM, ITEM, COMMAND, TEXT
//};


//struct container {
//    enum container_type type;       /// type of container
//    union{
//        struct room*    room;       /// pointer to room
//        struct item*    item;       /// pointer to item
//        struct command* command;    /// pointer to command
//        char*           text;       /// pointer to text
//    };
//    struct container* next;         /// pointer to next data container in list
//};


struct container* create_container(struct container* first, enum container_type type, void* entry){
    if(first== NULL || entry==NULL){
        return NULL;
    }
    struct container* container = (struct container*)calloc(1, sizeof(struct container));
    container->type = type;
    
    if(type == ROOM){
        container->room= entry;
    }
    
    if(type == ITEM){
        container->item= entry;
    }
    
    if(type == COMMAND){
        container->command= entry;
    }
    
    if(type == TEXT){
        container->text= entry;
    }
    container->next= NULL;
    
    if(first == NULL)
        return container;
    
    first->next= container;
    
    return first;
}



struct container* destroy_containers(struct container* first){
    if(first == NULL){
        return NULL;
    }
    
    struct container* container= first;
    while(container!= NULL){
        struct container* ptr= container;
        container= container->next;
        free(ptr);
    }
    return NULL;
}


void* get_from_container_by_name(struct container *first, const char *name){
    return NULL;
}

struct container* remove_container(struct container *first, void *entry){
    return NULL;
}







