#include<unistd.h>
#include"PipeReader.h"
#include"cutter.h"

void printf_reversed(char* str);
void print_help(void);
int main(int argc, char** argv)
{
	if(argc <= 1)
	{
		print_help();
		return 0;
	}

	//try to read from piped program
	//exit if it fails to read or there is no piped program
	char* input = NULL;
	if(!isatty(0))
	{
		input = readall(stdin,NULL);
		if(input == NULL)
		{
			printf("stringtease error: failed to read input!\n");
			exit(-1);
		}
	}
	else
	{
		printf("stringtease error: no input specified!\n");
		exit(-1);
	}
	
	args_t args;
	args_init(&args);
	args_parse(argc, argv, &args);


	//program can read from head or from tail only
	char* cutted = NULL;
	if(args.mode == head)
	{
		cutted = read_from_head(input,&args);
		if(args.reverse)
			printf_reversed(cutted);
		else
			printf("%s",cutted);
	}
	else if(args.mode == tail)
	{
		cutted = read_from_tail(input,&args);
		if(args.reverse)
			printf_reversed(cutted);
		else
			printf("%s",cutted);
	}
	free(cutted);
	printf("\n");	
	return 0;
}
void printf_reversed(char* str)
{
	size_t len = strlen(str);
	for(size_t i = len-1;i!=0;--i)
	{
		printf("%c",str[i]);
	}
}
void print_help(void)
{
	printf("%s","\t\tstringtease - cli utility that combines head and tail and adds some improvements.\n\n\
			Usage example:\n\
			cat file | stringtease --head | --tail 0s|c [Ns|c] [-r]\n\n\
			first argument is --head or --tail. It defines the beginning of cutting.\n\
			the second argument defines the start position Nth string(s) or Nth character.\n\
			the third optional argument defines the end position.It's start+10 by default.\n\
			the last optional argument defines should program output be reversed.\n");
}
