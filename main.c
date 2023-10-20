#include<unistd.h>
#include"ArgParser.h"
#include"PipeReader.h"

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
		
	}
	
	return 0;
}
