#include <stdio.h>
#include <string.h>

// ��������ĳ���
#define MAX_LINE_LENGTH 			256

int main(void)
{
	//������ȡ����
	char str[MAX_LINE_LENGTH];

	
	while(1)
	{
		// shell����
		printf("LYL#");
		
		//���str�����ڵ������Դ�ȡ�µ�����
		memset(str, 0, sizeof(str));
		// ��һ������ȡ����
		scanf("%s", str);
		
		// �ڶ�������������
		
		//��������ִ������
		printf("%s\n", str);
	}
	
	return 0;
}



































