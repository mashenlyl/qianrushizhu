#include <stdio.h>

int main (void)
{
	char *p = "linux\\0xxx";		//\\0这样就可以打印'\0'了
	
	printf("p = %s.\n", p);			//最终打印的结果是linux.这就说明了字符串是遇\0就打印完毕
									//用%c来打印*p就是可以的，我觉得是%s的实现机制
	return 0;
}
























