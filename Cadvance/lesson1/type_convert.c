#include <stdio.h>
int main (void)
{
	int a = 3;
	float b = 3.5;
	int c;
	
	c = a + b;
	
	printf("c = %d.\n", c);		//c = 6
	printf("a + b = %d.\n", a + b);  //0 float类型，int类型转换不了
	printf("a + b = %f.\n", a + b);		// 6.50000
	printf("a + b = %d.\n", a + (int)b); //强制类型转换是放在变量的左边的，如果放在右边是错误的
	//printf("a + b = %d.\n", a + b(int)); //错误的
	printf("a = %d.\n", a);
	
	return 0;
}