#include <stdio.h>

int main (void)
{
	int *p = NULL;			//���ȸ�ֵ��NULL
	int a = 10;
	
	p = &a;					//������֮ǰ����ָ����ֵ
	
	if(NULL != p)			//֮���ж�
	{
		*p = 4;
	}
	
	printf("p = %d.\n", *p);
	p = NULL;				//�����¸�ֵ����
	
	/*
	int *p;
	
	printf("p = %p.\n", (int *)0);		//�ϴ�ջʹ��ʱ����������ֵ
	
	*p = 4;						//Segmentation fault (core dumped)�����δ���
	
	printf("p = %p.\n", NULL);	//(void *)0 = NULL
	*/
	
	return 0;
}