#include <stdio.h>

int main (void)
{
	char *p = "linux\\0xxx";		//\\0�����Ϳ��Դ�ӡ'\0'��
	
	printf("p = %s.\n", p);			//���մ�ӡ�Ľ����linux.���˵�����ַ�������\0�ʹ�ӡ���
									//��%c����ӡ*p���ǿ��Եģ��Ҿ�����%s��ʵ�ֻ���
	return 0;
}
























