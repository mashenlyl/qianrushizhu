#include <stdio.h>

#define offsetof(TYPE,MEMBER)	(int)(&((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({			\
	const typeof(((type *)0)->member) * __mptr = (ptr);	\
	(type *)((char *)__mptr - offsetof(type, member)); })

struct Mystruct
{
	short a;
	int b;
	short c;
};

int main (void)
{
	struct Mystruct s1;
	struct Mystruct *pS;
	
	int *p = &(s1.b);
	pS = container_of(p,struct Mystruct,b);
	
	printf("p = %p.\n", p);
	printf("pS = %p.\n", pS);
	
	/*
	struct Mystruct s1;
	
	s1.a = 10;
	s1.b = 20;
	s1.c = 30;
	
	printf("struct Mystruct(a) = %d.\n", offsetof(struct Mystruct,a));		//0
	printf("struct Mystruct(b) = %d.\n", offsetof(struct Mystruct,b));		//4
	printf("struct Mystruct(c) = %d.\n", offsetof(struct Mystruct,c));		//8
	*/
	
	return 0;
}

































