#include"cutter.h"

char* prepare_sub(char* input, args_t* arguments)
{
	size_t input_len = strlen(input);
	if(input_len < arguments->begin &&
	   input_len < arguments->end)
	{
		printf("stringtease error: range is out of input boundaries!\n");
		exit(-1);   	
	}

	long int len = arguments->end - arguments->begin;
	char* sub = (char*)malloc(sizeof(char)* len);
	if(sub == NULL)
	{
		printf("stringtease error: failed to init memory for substring to read from stdin!\n");
		exit(-1);
	}

	return sub;
}
char* read_char_by_char_from_head(char* input, args_t* arguments)
{
	char* sub = prepare_sub(input, arguments);
	
	long int n = 0;
	for(long int i = arguments->begin;i<arguments->end;++i,++n)
		sub[n] = input[i];
	
	return sub;
}
char* read_char_by_char_from_tail(char* input, args_t* arguments)
{
	char* sub = prepare_sub(input, arguments);

	long int n = 0;
	for(long int i = arguments->end;i>arguments->begin;--i,++n)
		sub[n] = input[i];

	return sub;
}

char* read_from_head(char* input, args_t* arguments)
{
	if(arguments->type == ch)
		return read_char_by_char_from_head(input,arguments);
	
}
char* read_from_tail(char* input, args_t* arguments)
{
	if(arguments->type == ch)
		return read_char_by_char_from_tail(input,arguments);			
}
