#include <stdio.h>

int main (void)
{
	int *p;
	char *p1;
	int a[5] = {256, 16, 23, 22, 34};
	
	p = a;
	p1 = (char *)p;
	
	printf("*(p+1) = %d.\n", *(p+1));
	printf("*(p1+1) = %d.\n", *(p1+1));			//������൱�����ƶ���һ���ֽڶ��ѣ������ƶ�8λ
	printf("*((char *)p+1) = %d.\n", *((char *)p+1));		//���������һ��
	//��������͸����ˣ�Ӧ�������Ȱ���ת����int���͵ģ�Ȼ���1��֮��ת��ָ�����͵ģ����ָ�����ڴ�ĵ�ַ
	printf("*(int *)((unsigned int)p+1) = %d.\n", *(int *)((unsigned int)p+1));
	
	/*
	int *p;
	int a[5] = {10, 11, 23, 22, 34};
	
	p = a;										//a����ֵ��ʱ�򣬾ͱ�ʾ��Ԫ�صĵ�ַ
	
	printf("a[3] = %d.\n", a[3]);
	printf("*(a+3) = %d.\n", *(a+3));
	printf("*(p+3) = %d.\n", *(p+3));			//��Щ���ǵ�ͬ�ġ�
	*/
	
	return 0;
}















