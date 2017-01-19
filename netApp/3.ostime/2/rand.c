#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
	int num = 0, i = 0;
	
#if 0
	if(argc != 2)
	{
		printf("usage: %s num\n", argv[0]);
		return -1;
	}
#endif
	
	// 使用时间作为种子
	//srand(atoi(argv[1]));
	srand(time(NULL));
	
	for(i=0; i<5; i++)
	{
		num = rand();
		printf("num = %d\n", (num % 6));
	}
	
	return 0;
}




























