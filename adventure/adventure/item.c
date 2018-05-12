//
//  item.c
//  adventure
//
//  Created by Jakub Brehuv on 10/05/2018.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"item.h"

struct item* create_item(char* name, char* description, unsigned int properties){
    
    if(name == NULL || description== NULL){
        return NULL;
    }
    if(strlen(name)<1 || strlen(description)<1){
        return NULL;
    }
    
    struct item* new_item = (struct item*)calloc(1, sizeof(struct item));
    new_item->name = name;
    new_item->description = description;
    new_item->properties = properties;
    
    return new_item;
}

struct item* destroy_item(struct item* item){
    free(item);
    return NULL;
}
