//ö��enum���÷������ǿ����ú궨��ķ��������� 
#include <stdio.h>

enum week
{
	SUN,          //SUN = 0
	MON,          //MON = 1
	TUE,
	WEN,          //WEN = 3       //ö������Ķ���һ�������ģ��ͺ�����д�� 
	THR,                           //���ԾͿ�����switch����ʼ�Ҿͻ�����ô���� ��switch�ģ���ô����һ�λ� 
	FRI,                           //ԭ����һ�������� 
	SAT,               //���һ��û�Ӷ��Ų������Ŷ            
}; 

int main (void) 
{
	enum week day;
	day = SUN;
	
	printf("day = %d.\n", day);
	
	switch(day)         //Ҳ�������day��ʵ����0���ģ��������ַ��������Կ�����switch 
	{
		case SUN:
			printf("SUNDAY!\n"); 
			break;
		case MON:
			printf("MONDAY!\n"); 
			break;
		case TUE:
			printf("TUESDAY!\n"); 
			break;
		case WEN:
			printf("WENESDAY!\n"); 
			break;
		case THR:
			printf("THRSDAY!\n"); 
			break;
		case FRI:
			printf("FRIDAY!\n"); 
			break;
		case SAT:
			printf("SATADAY!\n"); 
			break;
		default:
			printf("bu ke neng"); 
	} 
	
	return 0;
} 
