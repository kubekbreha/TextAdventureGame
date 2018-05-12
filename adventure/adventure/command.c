

#include "command.h"
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include "command.h"

struct command* create_command(char* name, char* description, char* pattern, size_t nmatch){
    if(name == NULL || description == NULL)
        return NULL;
    
    if(strlen(name)<1 || strlen(description)<1)
        return NULL;
    
    struct command* new_command = (struct command*)calloc(1, sizeof(struct command));
    new_command->name = name;
    new_command->description = description;
    new_command->nmatch= nmatch;
    new_command->groups = NULL;
    
    return new_command;
}

struct command* destroy_command(struct command* command){
    free(command);
    return NULL;
}
