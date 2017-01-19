#include <stdio.h>
#include <stdlib.h>


int main(void)
{
#if 0
	// 注意：需要在这里声明他是外部的变量，不然就报段错误了；
	extern char ** environ;
	int i = 0;
	
	while(NULL != environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
#endif

	printf("%s\n", getenv("PATH"));
	return 0;
}
