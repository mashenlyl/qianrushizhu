#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[] = "linuxquanju";			//�ڶ��֣���ȫ�ֱ����ķ������ͱ����浽�����ݶ�����
char str1;							//������û�г�ʼ����ȫ�ֱ������Ƿ���bss�ε�

//�����ö���һ������ַ����ı�����˵�����ڴ����һ������
int main (void)
{
	char a[] = "linuxjubu";		//��һ�֣��þֲ������ķ������ͱ����浽��ջ����ȥ��
	
	char *p = (char *)malloc(10);
	//���Ǽ����ˣ��Ƿ�ѵ�ַ������
	if(NULL == P)
	{
		printf("malloc error!\n");
		return -1;
	}
	memset(p, 0, 10);			//memset�����������
	strcpy(p, "linuxheap");		//strcpy��������ֵ��
	
	printf("%s.\n", a);
	printf("%s.\n", p);
	printf("%s.\n", str);
	
	//��ַ֮�䶼���ɺܴ�Ĳ��ģ�˵����Щ���ݶ��Ƿ��ڲ�ͬ�Ķε�
	printf("%p.\n", a);
	printf("%p.\n", p);
	printf("%p.\n", str);

	
	return 0;
}



































