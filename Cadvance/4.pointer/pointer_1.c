#include <stdio.h>

int main (void)
{
	//ָ���ʹ��������������ָ�����������ָ�������������
	int a = 23;
	int *p;				//����ָ�����
	
	p = &a;				//����ָ�����
	
	printf("*p = %d.\n", *p);		//������
	
	return 0;
}