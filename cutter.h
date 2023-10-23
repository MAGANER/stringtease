#ifndef CUTTER_H
#define CUTTER_H
#include"ArgParser.h"

//inner functions
char* read_char_by_char_from_head(char* input,args_t* arguments);
char* read_char_by_char_from_tail(char* input,args_t* arguments);

char* read_line_by_line_from_head(char* input,args_t* arguments);
char* read_line_by_line_from_tail(char* input,args_t* arguments);

char* prepare_sub(char* input, args_t* arguments);
//

//public functions
char* read_from_head(char* input, args_t* arguments);
char* read_from_tail(char* input, args_t* arguments);
//

#endif //CUTTER_H
