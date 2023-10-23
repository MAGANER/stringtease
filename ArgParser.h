#ifndef ARG_PARSER_H
#define ARG_PARSER_H
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

//this enumeration specifies the start direction of cutting process
typedef enum
{
	head,
	tail,
	no_mode
} arg_mode_t;

//this enumeration specifies 1 element to cut: string or character
typedef enum
{
	str,
	ch,
	no_type
} arg_type_t;

typedef struct
{
	arg_mode_t mode;
	arg_type_t type;
	long int begin, end;
} args_t;

//inner functions
#define IS_RANGE(x) check_last_ch(x,'s') || check_last_ch(x,'c')
bool check_last_ch(char* arg, char ch);
bool check_first_ch(char* arg, char ch);
bool check_is_numeric(char* arg);
//

//public functions
void args_init(args_t* arguments);
void args_parse(int argc, char** argv,args_t* arguments);
//

#endif
