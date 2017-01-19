#include <stdio.h>

struct A
{
	char a;
	int b;
};

void func5(struct A *a)
{
	printf("&a = %p.\n", &a);
	printf("a = %p.\n", a);
	printf("sizeof(a) = %d.\n", sizeof(a));	
	printf("in func4,a->b = %d.\n", a->b);				//指针中的结构体的元素的表达方式
}

void func4(struct A a)
{
	printf("&a = %p.\n", &a);
	printf("sizeof(a) = %d.\n", sizeof(a));		//也是赋值的
	printf("in func4,a.b = %d.\n", a.b);
}

void func3(int *a)
{
	printf("a = %p.\n", a);						//a就代表它的值，*a就代表它所指向的变量，&a代表他的地址
	printf("*a = %d.\n", *a);
}

void func2(int a[])
{
	printf("sizeof(a) = %d.\n", sizeof(a));			
	printf("&a = %p.\n", &a);						//双重指针，指针的地址，指针也是个变量
	printf("a = %p.\n", a);							//一样的，所以传了个指针过来
}

void func1(int a)
{
	printf("in func1,a = %d.\n", a);
	printf("in func2,a = %p.\n", &a);				//地址是不一样的，所以两个变量是独立的
}

int main (void)
{
	//指针的结构体变量作为函数形参
	struct A a = 
	{
		.a = 2,
		.b = 4,
	};
	printf("&a = %p.\n", &a);
	printf("sizeof(a) = %d.\n", sizeof(a));
	printf("a.b = %d.\n", a.b);
	func5(&a);
	
	
	/*
	//结构体变量作为函数形参
	struct A a = 
	{
		.a = 2,
		.b = 4,
	};
	printf("&a = %p.\n", &a);
	printf("sizeof(a) = %d.\n", sizeof(a));
	printf("a.b = %d.\n", a.b);
	func4(a);
	*/
	
	/*
	//指针作为函数形参
	int a = 4;
	printf("&a = %p.\n", &a);
	func3(&a);
	*/
	
	/*
	//指针作为函数形参
	int a[5] = {1, 2, 3, 4, 5};
	printf("a = %p.\n", a);
	func2(a);
	*/

/*
	//普通变量作为函数形参
	int a = 5;
	printf("a = %d.\n", a);
	printf("a = %p.\n", &a);
	func1(a);
*/
	
	return 0;
}





































