#include <stdio.h>

//共用体这里用的是同一块内存来的
union Myunion
{
	char a;
	int b;
	float c;
};

int main (void)
{
	union Myunion u1;
	float b = 123.456;
	
	u1.c = 0.0;		//这里是清除内存里面的垃圾
	u1.a = 10;
	printf("a = %d.\n", *((int *)&b));		//1123477881，就是和强制类型转换的功能差不多
	
	printf("u1.a = %d.\n", u1.a);
	printf("u1.b = %d.\n", u1.b);
	printf("u1.c = %f.\n", u1.c);
	
	
	return 0;
}

































