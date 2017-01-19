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
	printf("in func4,a->b = %d.\n", a->b);				//ָ���еĽṹ���Ԫ�صı�﷽ʽ
}

void func4(struct A a)
{
	printf("&a = %p.\n", &a);
	printf("sizeof(a) = %d.\n", sizeof(a));		//Ҳ�Ǹ�ֵ��
	printf("in func4,a.b = %d.\n", a.b);
}

void func3(int *a)
{
	printf("a = %p.\n", a);						//a�ʹ�������ֵ��*a�ʹ�������ָ��ı�����&a�������ĵ�ַ
	printf("*a = %d.\n", *a);
}

void func2(int a[])
{
	printf("sizeof(a) = %d.\n", sizeof(a));			
	printf("&a = %p.\n", &a);						//˫��ָ�룬ָ��ĵ�ַ��ָ��Ҳ�Ǹ�����
	printf("a = %p.\n", a);							//һ���ģ����Դ��˸�ָ�����
}

void func1(int a)
{
	printf("in func1,a = %d.\n", a);
	printf("in func2,a = %p.\n", &a);				//��ַ�ǲ�һ���ģ��������������Ƕ�����
}

int main (void)
{
	//ָ��Ľṹ�������Ϊ�����β�
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
	//�ṹ�������Ϊ�����β�
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
	//ָ����Ϊ�����β�
	int a = 4;
	printf("&a = %p.\n", &a);
	func3(&a);
	*/
	
	/*
	//ָ����Ϊ�����β�
	int a[5] = {1, 2, 3, 4, 5};
	printf("a = %p.\n", a);
	func2(a);
	*/

/*
	//��ͨ������Ϊ�����β�
	int a = 5;
	printf("a = %d.\n", a);
	printf("a = %p.\n", &a);
	func1(a);
*/
	
	return 0;
}





































