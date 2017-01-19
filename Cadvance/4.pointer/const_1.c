# include <stdio.h> 

int main (void)
{
	const int a = 5;			//const类型只能在gcc 的环境才可以改，在其他的环境是改不了的
	int *p = &a;				//这里说明了const类型的变量也是可以被修改的。
	
	*p = 6;
	
	printf("a = %d.\n", a); 
	
	return 0;
} 














