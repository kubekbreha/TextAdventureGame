//
//  container.c
//  adventure
//
//  Created by Jakub Brehuv on 10/05/2018.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

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
    free(container);
    free(first);
    return NULL;
}


int stricmp (const char *p1, const char *p2){
    register unsigned char *s1 = (unsigned char *) p1;
    register unsigned char *s2 = (unsigned char *) p2;
    unsigned char c1, c2;
    
    do{
        c1 = (unsigned char) toupper((int)*s1++);
        c2 = (unsigned char) toupper((int)*s2++);
        if (c1 == '\0'){
            return c1 - c2;
        }
    }
    while (c1 == c2);
    
    return c1 - c2;
}

void* get_from_container_by_name(struct container *first, const char *name){
    if(first == NULL || name == NULL){
        return  NULL;
    }
    if(strlen(name)<1){
        return NULL;
    }
    struct container* container = first;

    while (container != NULL){
        
        if (stricmp(container->item->name, name))
            return container->item;
        if (stricmp(container->command->name, name))
            return container->item;
        if (stricmp(container->room->name, name))
            return container->item;
        if (stricmp(container->text, name))
            return container->item;
        container = container->next;
    }

    return NULL;
}

struct container* remove_container(struct container *first, void *entry){
    free(first);
    return NULL;
}











