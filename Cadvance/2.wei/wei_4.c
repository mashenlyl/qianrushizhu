#include <stdio.h>

//�������Ҫ������x�ĵ�nλ��bit��n-1��λ����Ϊ1
//1U�ͱ�ʾ�����޷��ŵ�1���궨����Դ��ε�
#define SET_BIT(x,n)	(x | 1U<<(n-1))

//�������Ҫ������x�ĵ�nλ��bit��n-1��λ������
#define CLEAR_BIT(x,n)	(x & ~(1U<<(n-1)))

//�������Ҫ������x�ĵ�n��mλ��Ϊ1(n�ǵ�λ��m�Ǹ�λ)
//�����Ȱ�0ȡ���Ϳ��Եõ��ܶ��1��Ȼ�����ƾ͵õ���ô���0����ȡ���Ϳ��Եõ�����Ҫ��1�ĸ�����
//�������λ��Ϳ�����1��
#define SET_BITS(x,n,m)	(x | ~(~0U<<(m-n+1))<<(n-1))

//��ȡ�����Ĳ�������λ��(����ȡ������˼)
//��ʵ�����������ǲ��ģ�������һ�󲿷ֶ���Ϊ��ȷ����Ҫ���ٸ�1
//���ǵ����ƣ�Ϊ�˵ó��Ǹ�����
#define GET_BIT(x,n,m)	(x & ~(~0U<<(m-n+1))<<(n-1)) >>(n-1)

int main (void)
{
	unsigned int a = 0xfffffabf;
	unsigned int b;
	
	b = GET_BIT(a,5,12);				//�����������ab
	
	printf("b = 0x%x.\n", b);			//b = 0xab.
	
	/*
	unsigned int a = 0x0;
	unsigned int b;
	
	b = SET_BITS(a,5,8);
	
	printf("b = 0x%x.\n", b);			//b = 0xf0.
	*/
	
	/*
	unsigned int a = 0xf;
	unsigned int b = 0;
	
	b = CLEAR_BIT(a,4);
	
	printf("b = 0x%x.\n", b);			//b = 0x7.
	*/
	
	/*
	unsigned int a = 0;
	unsigned int b = 0;
	
	b = SET_BIT(a,4);
	
	printf("b = 0x%x.\n", b);			//b = 0x8.
	*/
	
	return 0;
}























