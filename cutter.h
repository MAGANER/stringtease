#ifndef CUTTER_H
#define CUTTER_H
#include"ArgParser.h"

char* read_char_by_char_from_head(char* input,args_t* arguments);
char* prepare_sub(char* input, args_t* arguments);

char* read_from_head(char* input, args_t* arguments);
char* read_from_tail(char* input, args_t* arguments);


#endif //CUTTER_H
