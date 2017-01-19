//枚举enum的用法，还是可以用宏定义的方法来做的 
#include <stdio.h>

enum week
{
	SUN,          //SUN = 0
	MON,          //MON = 1
	TUE,
	WEN,          //WEN = 3       //枚举这里的都是一个数来的，就好像我写的 
	THR,                           //所以就可以用switch，开始我就怀疑怎么可以 用switch的，辣么长的一段话 
	FRI,                           //原来是一个数来的 
	SAT,               //最后一个没加逗号不报错的哦            
}; 

int main (void) 
{
	enum week day;
	day = SUN;
	
	printf("day = %d.\n", day);
	
	switch(day)         //也就是这个day其实就是0来的，并不是字符串，所以可以用switch 
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
