#ifndef __CAL_H_				// 如果没有定义宏。则编译下面这些语句，if not define 
#define __CAL_H_				// 定义宏，避免下次再次编译

typedef int (*pFunc)(int, int);


struct cal_t
{
	int a;
	int b;
	pFunc p;
};

int caculator(const struct cal_t *p1);			// 函数的原型






#endif						// 编译宏结束符






































