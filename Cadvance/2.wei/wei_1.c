#include <stdio.h>

int main (void)
{
	int a = 0x1223ffad;				//����ʹ�õ���λ��������
	int b = 0x0000ff00;				//��ȡ���Ļ�����1��򣬲��������0
	int c;
	
	c = a ^ b;						//λ���
	
	printf("c = %x.\n", c);			//122300ad.
	
	/*
	int a = 0x1223ffad;				//����ʹ�õ���λ�������������
	int b = 0xff000000;				//�������1�Ļ�����1λ������Ļ������������Ϳ�����
	int c;
	
	c = a | b;						//λ��
	
	printf("c = %x.\n", c);			//ff23ffad.	
	*/
	
	/*
	int a = 0x1223ffad;				//���������λ�������������
	int b = 0xffff00ff;				//���������0�Ļ�����0λ�룬����Ļ�����1��
	int c;
	
	c = a & b;						//λ��
	
	printf("c = %x.\n", c);			//122300ad
	*/
	return 0;
}




















