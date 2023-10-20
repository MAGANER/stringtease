#include"ArgParser.h"

void args_init(args_t* arguments)
{
	arguments->mode = no_mode;
	arguments->type = no_type;
	arguments->begin = -1;
	arguments->end = -1;
}
bool check_last_ch(char* arg, char ch)
{
	if(arg == NULL)return false;
	
	size_t len = strlen(arg);
	return arg[len-1] == ch;
}
bool check_first_ch(char* arg,char ch)
{
	if(arg == NULL)return false;
	return arg[0] == ch;
}
bool check_is_numeric(char* arg)
{
	//don't check last symbol
	for(int i = 0;i<strlen(arg);++i)
	{
		if(!isdigit(arg[i]))
			return false;
	}
	return true;
} 
void args_parse(int argc, char** argv, args_t* arguments)
{
	for (int i = 1; i< argc; ++i)
	{
		char* curr_arg = argv[i];
		if(strcmp(curr_arg,"--head") == 0)
		{
			if(arguments->mode != no_mode)
			{
				printf("stringtease error: mode is already set up!\n");
				exit(-1);
			}
			arguments->mode = head;
		}
		else if(strcmp(curr_arg,"--tail") == 0)
		{
			if(arguments->mode != no_mode)
			{
				printf("stringtease error: mode is already set up!\n");
				exit(-1);
			}
			arguments->mode = tail;
		}
		else if (IS_RANGE(curr_arg))
		{
			size_t len = strlen(curr_arg);
			char* sub = (char*)malloc(sizeof(char)*len);
			if(sub == NULL)
			{
				printf("stringtease error: failed to init memory while parsing arguments\n");
				exit(-1);
			}
			
			for(int i = 0;i<len-1;++i)
				sub[i]= curr_arg[i];
			sub[len-1] = '\0';
			
			if(!check_is_numeric(sub))
			{
				printf("stringtease error:%s is not numeric value!\n",sub);
				exit(-1);
			}

			if(arguments->begin == -1)
				arguments->begin = atoi(sub);
			else if(arguments->end == -1)
				arguments->end = atoi(sub);
			else
			{
				printf("stringtease error: range is already set up!\n");
				exit(-1);
			}
			free(sub);

			if(curr_arg[len-1] == 's')
				arguments->type = str;
			if(curr_arg[len-1] == 'c')
				arguments->type = ch;						
		}
		else
		{
			printf("stringtease error: %s is unknown argument!\n",curr_arg);
			exit(-1);
		}		
	}

	if(arguments->begin == -1 &&
	   arguments->end   == -1)
	{
		printf("stringtease error: no range specified!\n");
		exit(-1);   	
	}
	if(arguments->begin != -1 &&
	   arguments->end == -1)
	{
		arguments->end = (arguments->begin*2)+1;
	}
}
