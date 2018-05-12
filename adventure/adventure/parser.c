
#include<stdio.h>
#include <stdlib.h>
#include"parser.h"

struct parser* create_parser(){
 
    return NULL;
}

struct parser* destroy_parser(struct parser* parser){
    free(parser->commands);
    free(parser->history);
    free(parser);
    return NULL;
}

struct command* parse_input(struct parser* parser, char* input){
    return NULL;
}
