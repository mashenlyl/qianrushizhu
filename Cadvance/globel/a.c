//c�����ж���ļ���ʱ��ֻ������һ��main����������ж��main�����ͻ�����
//Ϊ����֯�ϵı�������c�ļ��ֳɶ���ļ������ֶ���ļ���
#include <stdio.h>

int g_a = 5;

void func2(void);

int bb(void);				//������b.c�ж���ĺ�����������a.c������
							//�����ʱ��������д�ģ�gcc a.c b.c -o ab,�Ͱ������ļ��ϳ�һ����
							//ִ�е�ʱ���ǣ�./ab
int main (void)				
{
	int i, j;
	
	i = 18;
	j = 11;
										//float���͵Ĳ����Խ���ȡ��
	printf("i %% j = %d.\n", i%j);		//������Ҫ���ֳ�%�Ļ�����Ҫд%%�ſ���
	printf("This is main in a.c\n");
	bb();					//�������������
	func2();
	
	return 0;
}

void func2(void)			//�����ں������涨�庯��
{
	int i = 2;
	
	printf("i = %d.\n", i);
}





















