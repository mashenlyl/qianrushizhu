#include <stdio.h>

int var = 10;

//��������ͬ���ֵĻ������ǿ�������Ǹ������ˣ�Ʃ��main���������������var����������if�����var����
//����if�����ʹ��if���涨���var������
int main (void)
{
	//����extern�ͱ���ʹ��ȫ�ֱ����������ϣ�var����һ���ֲ���������
	//extern int var;
	//�����var�����������main����������
	int var = 5;
	
	if(1)
	{
		//����var�����������if���������������
		int var = 3;
		printf("var = %d.\n", var);
	}
	
	printf("var = %d.\n", var);
	
	return 0;
}