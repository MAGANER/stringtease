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

char* read_line_by_line_from_head(char* input,args_t* arguments)
{
	size_t len = 2;
	char* sub = (char*)malloc(sizeof(char)*len);
	if(sub == NULL)
	{
		printf("stringtease error:failed to prepare memory for substring to read from stdin!\n");
		exit(-1);
	}

	size_t new_line_counter = 0;
	size_t n = 0;
	for(size_t i = 0;i<strlen(input);++i)
	{
		if(input[i] == '\n')
			new_line_counter++;
			
		if(new_line_counter >= arguments->begin &&
		   new_line_counter < arguments->end)
		{
			if(len == 1)
			{
				sub[n] = input[i];
			}	
			else
			{
				len+=1;
				sub = (char*)realloc(sub,sizeof(char)*len);
				sub[n] = input[i];
			}
			++n;
		}
	}	
	
	return sub;	
}
char* read_line_by_line_from_tail(char* input, args_t* arguments)
{
	size_t len = 2;
	char* sub = (char*)malloc(sizeof(char)* len);
	if(sub == NULL)
	{
		printf("stringtease error:failed to prepare memory for substring to read from stdin!\n");
		exit(-1);
	}	
	
	size_t new_line_counter = 0;
	size_t n = 0;
	for(size_t i = strlen(input)-1;i!=0;--i)
	{
		if(input[i] == '\n')
			new_line_counter++;

		if(new_line_counter >= arguments->begin &&
		   new_line_counter < arguments->end)
		{
			if(len == 1)
			{
				sub[n] = input[i];
			}
			else
			{
				len+=1;
				sub = (char*)realloc(sub,sizeof(char)*len);
				sub[n] = input[i];
			}
			++n;
		}
	}

	return sub;
}
char* read_from_head(char* input, args_t* arguments)
{
	if(arguments->type == ch)
		return read_char_by_char_from_head(input,arguments);
	if(arguments->type == str)
		return read_line_by_line_from_head(input,arguments);	
}
char* read_from_tail(char* input, args_t* arguments)
{
	if(arguments->type == ch)
		return read_char_by_char_from_tail(input,arguments);
	if(arguments->type == str)
		return read_line_by_line_from_tail(input,arguments);			
}
