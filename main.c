#include<unistd.h>
#include"PipeReader.h"
#include"cutter.h"

int main(int argc, char** argv)
{
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

	if(args.mode == head)
	{
		char* cutted = read_from_head(input,&args);
		printf("%s",cutted);
		free(cutted);		
	}
	else if(args.mode == tail)
	{
		char* cutted = read_from_tail(input,&args);
		printf("%s",cutted);
		free(cutted);		
	}
	
	return 0;
}
