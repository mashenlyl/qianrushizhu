#include <stdio.h>

//�����������õ���ͬһ���ڴ�����
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
	
	u1.c = 0.0;		//����������ڴ����������
	u1.a = 10;
	printf("a = %d.\n", *((int *)&b));		//1123477881�����Ǻ�ǿ������ת���Ĺ��ܲ��
	
	printf("u1.a = %d.\n", u1.a);
	printf("u1.b = %d.\n", u1.b);
	printf("u1.c = %f.\n", u1.c);
	
	
	return 0;
}

































