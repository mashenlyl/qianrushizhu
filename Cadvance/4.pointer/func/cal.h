#ifndef __CAL_H_				// ���û�ж���ꡣ�����������Щ��䣬if not define 
#define __CAL_H_				// ����꣬�����´��ٴα���

typedef int (*pFunc)(int, int);


struct cal_t
{
	int a;
	int b;
	pFunc p;
};

int caculator(const struct cal_t *p1);			// ������ԭ��






#endif						// ����������






































