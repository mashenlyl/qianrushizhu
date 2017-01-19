#include "stdio.h"
#define GPH0CON		0xE0200C00
#define GPH0DAT		0xE0200C04
#define GPH2CON		0xE0200C40
#define GPH2DAT		0xE0200C44

#define rGPH0CON		(*(volatile unsigned int *)GPH0CON)
#define rGPH0DAT		(*(volatile unsigned int *)GPH0DAT)
#define rGPH2CON		(*(volatile unsigned int *)GPH2CON)
#define rGPH2DAT		(*(volatile unsigned int *)GPH2DAT)


void key_init(void)
{
	//置为0的时候IO口就是input模式
	// bit 8~15位置为0
	rGPH0CON &= (~(0xff<<8));
	// bit 0~15位置为0
	rGPH2CON &= (~(0xffff<<0));
}

void key_polling(void)
{
	while(1)
	{
		if(rGPH0DAT & (1<<2))
		{
			led_off();
			//这里是1，就是按键弹开的时候，全部led都熄灭
		}
		else
		{
			led1();
			//这里是0，就是按键按下的时候,然后就亮一个led
			printf("This is left key.\n");
		}

	

		if(rGPH0DAT & (1<<3))
		{
			led_off();
			//这里是1，就是按键弹开的时候，全部led都熄灭
		}
		else
		{
			led2();
			//这里是0，就是按键按下的时候,然后就亮一个led
			printf("This is another key.\n");
		}
	}
}

























