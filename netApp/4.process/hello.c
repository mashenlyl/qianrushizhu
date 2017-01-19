#include <stdio.h>

int main(int argc, char **argv, char **env)
{
	int i = 0;
	
	for(i=0; i<argc; i++)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	
	for(i=0; env!=NULL; i++, env++)
	{
		printf("%s\n", env[i]);
	}
	
	return 0;
}