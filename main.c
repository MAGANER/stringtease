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
			printf("cut error: failed to read input!\n");
			exit(-1);
		}
	}
	else
	{
		printf("cut error: no input specified!\n");
		exit(-1);
	}
	
	args_t args;
	args_init(&args);
	args_parse(argc, argv, &args);

	printf("mode:%d\n",args.mode);
	printf("type:%d\n",args.type);
	printf("begin:%d\n",args.begin);
	printf("end:%d\n",args.end);		
	return 0;
}
