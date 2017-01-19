#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[] = "linuxquanju";			//第二种：用全局变量的方法，就被保存到了数据段上了
char str1;							//像这种没有初始化的全局变量就是放在bss段的

//可以用定义一个存放字符串的变量来说明掉内存的那一点事情
int main (void)
{
	char a[] = "linuxjubu";		//第一种：用局部变量的方法，就被保存到了栈上面去了
	
	char *p = (char *)malloc(10);
	//忘记检验了，是否把地址给了它
	if(NULL == P)
	{
		printf("malloc error!\n");
		return -1;
	}
	memset(p, 0, 10);			//memset是用来清零的
	strcpy(p, "linuxheap");		//strcpy是用来赋值的
	
	printf("%s.\n", a);
	printf("%s.\n", p);
	printf("%s.\n", str);
	
	//地址之间都是由很大的差别的，说明这些数据都是放在不同的段的
	printf("%p.\n", a);
	printf("%p.\n", p);
	printf("%p.\n", str);

	
	return 0;
}



































