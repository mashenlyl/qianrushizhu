#include <stdio.h>

//这就是带参数的宏，每个宏体都必须要那个括号括着
#define MAX(a,b)	(((a)>(b))?(a):(b))

//只可以这样子做强制类型转换
#define SEC_PER_YEAR	(365*24*60*60UL)

#define DEBUG
#undef DEBUG		//如果定义了DEBUG，就擦除它，如果没有，那就不需要理会它了

int main (void)
{
	#ifdef DEBUG
	printf("DEBUG.\n");
	#else
	printf("NODEBUG.\n");
	#endif
	
	int a = 5, b = 10;
	unsigned int c = SEC_PER_YEAR;
	
	printf("MAX(A,B) = %d.\n", MAX(a,b));
	printf("c = %d.\n", c);
	
	
	return 0;
}




























