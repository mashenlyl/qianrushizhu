#include <stdio.h>

//利用共用体来进行大小端模式的测试
//小端模式的情况下：a是1，1就放在了低地址上，然后char类型的b也在低地址上，所以得到的b就是1
//大端模式下：a是1，1就放在了高地址上，共用体的变量都是从低地址上读起的，所以得到b是0
//根据这个不同，就可以判断芯片存取数据是大端模式还是小端模式了
//共用体的变量都是用同一个内存空间的
union Myunion
{
	int a;
	char b;
};

int is_little(void)
{
	union Myunion u1;
	u1.a = 1;
	return u1.b;
}

int main (void)
{
	
	//这种就是指针方式来测试大小端模式的方法
	//因为强制类型转换的时候，int转char类型的时候是取低地址的内存的，所以，就可以判断出大小端模式了。
	int a = 1;
	
	if(*((char *)(&a)))
	{
		printf("小端模式.\n");
	}
	else
	{
		printf("大端模式.\n");
	}
	
/*
	if(is_little())
	{
		printf("小端模式.\n");
	}
	else
	{
		printf("大端模式.\n");
	}
*/	
	
	return 0;
}

































