#include <stdio.h>

int func(int a, int *p);
int func3(char *p);

int main (void)
{
	//char *charStr = "hello";				//�����ǳ������ģ��ǲ����Ա��ı��
	char str[] = "hello";					//��������飬���Ա��ı䣬���Բ������
	
	func3(str);
	printf("%s.\n", str);
	
	/*
	//������Ǳ�׼�ļ�麯���Ƿ����ġ�
	int a, b = 0 , reset = -1;
	
	a = 21;
	
	reset = func(a, &b);
	
	if(reset == -1)
	{
		printf("error!\n");
	}
	else
	{
		printf("b = %d.\n", b);
	}
	*/
	
	return 0;
}

int func(int a, int *p)
{
	*p = a * 5;
	if(*p > 100)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int func3(char *p)
{
	*p = 'a';
}































