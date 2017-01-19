#include <stdio.h>

int main (int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Usage: %s <source file> <destination file>\n", argv[0]);
		return -1;
	}
}