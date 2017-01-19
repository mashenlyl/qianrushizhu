#include <stdio.h>

int main (int argc, char **argv)
{
	int *a = NULL;
	
	switch(argc)
	{
		case 0:
			printf("argc == 0\n");
			break;
		case 1:
			printf("argc == 1\n");
			printf("argv = %s\n", *argv);
			break;
		case 2:
			printf("argc == 2\n");
			printf("argv = %s\n", *argv);
			break;
		case 3:
			printf("argc == 3\n");
			printf("argv = %s\n", *argv);
			break;
		case 4:
			printf("argc == 4\n");
			printf("argv = %s\n", *argv);
			break;
		case 5:
			printf("argc == 5\n");
			break;
		default:
			printf("argc == other\n");
			break;
	}
	
	return 0;
}