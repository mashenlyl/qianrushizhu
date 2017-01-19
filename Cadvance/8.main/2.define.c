#include <stdio.h>

#define DEBUG_S3C_MEM


//这个fmt的定义是：const char *fmt,所以第一个要传字符串的
#ifdef DEBUG_S3C_MEM
#define DEBUG(fmt, args...) 	printf(fmt, ##args)
#else
#define DEBUG(fmt, args...) 	do {} while (0)
#endif

int main (void)
{
	DEBUG("This is DEBUG\n");
	
	return 0;
}