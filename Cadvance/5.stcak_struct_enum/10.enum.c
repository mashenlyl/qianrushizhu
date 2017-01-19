#include <stdio.h>

enum value
{
	//没有赋值的就默认是0和1，一直下去
	ERROR,
	RIGHT,
};

enum weekday
{
	//这下面的名字可以任意赋值，没有赋值的，就根据上面已经赋值的加1就是自己的值了
	MONDAY = 1,
	TUESDAY,
	WENESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY,
};

//可以不需要名字
enum
{
	NAME,
};

enum value return_value(void)
{
	return ERROR;
}

int main (void)
{
	int a = NAME;
	enum weekday today;
	
	if(return_value() == RIGHT)
	{
		printf("函数执行正确\n");
	}
	else
	{
		printf("函数执行错误\n");
	}
	
	if(a)
	{
		printf("函数执行正确\n");
	}
	else
	{
		printf("函数执行错误\n");
	}
	
	return 0;
}



























