#include <stdio.h>

struct Male   //�����Ƕ���ṹ�� 
{
	int age;
	char name[20];
	int baskerball; 
}; 

struct Imale       //���ǽṹ��Ϳ����������ȫ�����÷�����s1.age 
{
	int age;
	char name[20];
	int play; 
};

union human       //�����ǹ�����Ķ����� 
{
	struct Male s;    //�ṹ�������������ģ������൱����һ���������ͣ�int��ʲô�� 
	struct Imale h;   //Ҳ����˵ֻ�õ���ô��������е�һ����ֻ��ѡ���еĻ�����Ů�ġ� 
}; 

int main (void)
{
	union human s1;    //s1�ͱ�ʾ��һ���������� 
	union human s2;     
	
	s1.s.age = 3;    //������ǹ�������÷��� ,s1�е�s��s�е�name 
	s2.h.age = 2;
	
	printf("s = %d, h = %d.\n", s1.s.age, s2.h.age);   //����Ľ����2��˵��������ľ���һ���������������������Ϊ�� 
	return 0;
} 






















