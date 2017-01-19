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
	//��Ϊ0��ʱ��IO�ھ���inputģʽ
	// bit 8~15λ��Ϊ0
	rGPH0CON &= (~(0xff<<8));
	// bit 0~15λ��Ϊ0
	rGPH2CON &= (~(0xffff<<0));
}

void key_polling(void)
{
	while(1)
	{
		if(rGPH0DAT & (1<<2))
		{
			led_off();
			//������1�����ǰ���������ʱ��ȫ��led��Ϩ��
		}
		else
		{
			led1();
			//������0�����ǰ������µ�ʱ��,Ȼ�����һ��led
			printf("This is left key.\n");
		}

	

		if(rGPH0DAT & (1<<3))
		{
			led_off();
			//������1�����ǰ���������ʱ��ȫ��led��Ϩ��
		}
		else
		{
			led2();
			//������0�����ǰ������µ�ʱ��,Ȼ�����һ��led
			printf("This is another key.\n");
		}
	}
}

























