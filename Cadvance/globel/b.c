//������a.c���ã������ﶨ��
#include <stdio.h>			//д������ʱ��Ͳ��ᱨ����

extern int g_a;				//���������߱��������ڲ��Ǳ��ļ�������ͬһ������һ��ȫ�ֱ���
							//extern���ⲿ����˼
int bb(void)
{
	printf("This is main in c.c\n");
	printf("This is g_a= %d.\n", g_a);
	
	return 0;
}





































