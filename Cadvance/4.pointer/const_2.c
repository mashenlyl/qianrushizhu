#include <stdio.h>

int main (void)
{
	//const��ָ��֮��Ĺ�ϵ��һ��������
	//���䷽����const��*��ǰ�棬p���Ǳ�����ָ����
	//const��*�ź��棬p�ǳ�����ָ����Ǳ���
	//��һ�֣�ָ���Ǹ�����������ָ����Ǹ���������
	const int *p1;
	//�ڶ��֣��͵�һ����һ����
	int const *p2;
	//�����֣�ָ���ǳ���������ָ����Ǹ���������
	int * const p3;
	//�����֣�ָ���ǳ���������ָ����Ǹ���������
	const int * const p4;
	
	*p1 = 4;			//error: assignment of read-only location ��*p1��
	
	*p2 = 4;			//error: assignment of read-only location ��*p2��
	
	p3 = 0;				// error: assignment of read-only variable ��p3��
	*p3 = 4;
	
	p4 = 0;
	*p4 = 4;			//error: assignment of read-only location ��*p4��
	
	return 0;
}
























