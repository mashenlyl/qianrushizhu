#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mutiply(int a, int b);
int divide(int a, int b);

typedef int (*pFunc)(int, int);

int main (void)
{
	int a = 0, b = 0, result = 0;
	char c = 0;
	pFunc p1 = NULL;				//注意指针初始化的时候要写成这样，避免野指针
	
	printf("请输入两个数字：\n");
	scanf("%d%d", &a, &b);
	printf("请输入要做的运算(+ | - | * | /)\n");
	//也就是判断的时候那个\n已经去掉了，这样做可以去掉一整行的无用信息，直到遇到\n就结束。
	//一行结束的标志就是\n
	while(getchar() != '\n')
		continue;
	//getchar();				//这里用来去掉那个\n
	scanf("%c", &c);
	
	switch(c)
	{
		case '+':
			p1 = add; break;
		case '-':
			p1 = sub; break;
		case '*':
			p1 = mutiply; break;
		case '/':
			p1 = divide; break;
		default:
			p1 = NULL; break;
	}
	
	//两种方法都是一样可以调用函数的，其实还是用这种比较好，你就可以发现它是函数指针了
	result = (*p1)(a, b);
	printf("%d %c %d = %d.\n", a, c, b, result);
	
	
	return 0;
}

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mutiply(int a, int b)
{
	return a * b;
}

int divide(int a, int b)
{
	return a / b;
}


























