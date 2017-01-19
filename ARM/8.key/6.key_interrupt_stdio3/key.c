#include "stdio.h"
#include "main.h"
#include "inter.h"

//EXT_CON��EXT_PEND��EXT_MASK�Ĵ���
#define EXT_INT_0_CON  0xE0200E00
#define EXT_INT_2_CON  0xE0200E08
#define EXT_INT_0_PEND 0xE0200F40
#define EXT_INT_2_PEND 0xE0200F48
#define EXT_INT_0_MASK 0xE0200F00
#define EXT_INT_2_MASK 0xE0200F08

//����EXT_CON��EXT_PEND��EXT_MASK�Ĵ���
#define rEXT_INT_0_CON		(*(volatile unsigned int *)EXT_INT_0_CON)
#define rEXT_INT_2_CON		(*(volatile unsigned int *)EXT_INT_2_CON)
#define rEXT_INT_0_PEND		(*(volatile unsigned int *)EXT_INT_0_PEND)
#define rEXT_INT_2_PEND		(*(volatile unsigned int *)EXT_INT_2_PEND)
#define rEXT_INT_0_MASK		(*(volatile unsigned int *)EXT_INT_0_MASK)
#define rEXT_INT_2_MASK		(*(volatile unsigned int *)EXT_INT_2_MASK)


//GPH0�Ĵ���
#define GPH0CON		0xE0200C00
#define GPH0DAT		0xE0200C04
#define GPH2CON		0xE0200C40
#define GPH2DAT		0xE0200C44

//����GPH0�Ĵ���
#define rGPH0CON		(*(volatile unsigned int *)GPH0CON)
#define rGPH0DAT		(*(volatile unsigned int *)GPH0DAT)
#define rGPH2CON		(*(volatile unsigned int *)GPH2CON)
#define rGPH2DAT		(*(volatile unsigned int *)GPH2DAT)


//--------------------��ѯ��ʽ-------------------
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

//-------------------------�жϷ�ʽ--------------

// ��һ�����ⲿ�ж϶�Ӧ��GPIOģʽ����
// ��Ӧ�Ľӿ��ǣ�EINT2��EINT3��EINT16��EINT17��EINT18��EINT19
void key_inter_init(void)
{
	//GPH0�������ⲿ�ж�ģʽ
	rGPH0CON |= (0xff<<8);
	rGPH2CON |= (0xffff<<0);
	
	//����EXT_CON�Ĵ���������������ʲô����״̬���е�ƽ��������Ե����������һ�����ý��ͱ�Ե����
	//rEXT_INT_0_CON &= ~(0xFF<<8);
	rEXT_INT_0_CON |= ((2<<8)|(2<<12));
	//rEXT_INT_2_CON &= ~(0xFFFF<<0);
	rEXT_INT_2_CON |= ((2<<0)|(2<<4)|(2<<8)|(2<<12));
	
	//EXT_PEND�Ĵ���,Ҫ�Ȱ������㣬����Ҫд1����������
	rEXT_INT_0_PEND |= (3<<2);
	rEXT_INT_2_PEND |= (0xf<<0);
	
	//EXT_MASK�Ĵ�����ʹ���жϵģ�0����ʹ��
	rEXT_INT_0_MASK &= ~(3<<2);
	rEXT_INT_2_MASK &= ~(0xf<<0);
}

void isr_eint2(void)
{
	printf("key_eint2_left.\n");
	
	//֮��Ҫ����
	rEXT_INT_0_PEND |= (1<<2);
	//������ж���ϵҲҪ����
	intc_clearvectaddr();
}

void isr_eint3(void)
{
	printf("key_eint3_down.\n");
	
	//֮��Ҫ����
	rEXT_INT_0_PEND |= (1<<3);
	//������ж���ϵҲҪ����
	intc_clearvectaddr();
}

void isr_eint16171819(void)
{
	
	if(rEXT_INT_2_PEND &= 1<<0)
	{
		printf("key_eint16");
		rEXT_INT_2_PEND |= (1<<0);
	}
	else if(rEXT_INT_2_PEND &= 1<<1)
	{
		printf("key_eint17");
		rEXT_INT_2_PEND |= (1<<1);
	}
	else if(rEXT_INT_2_PEND &= 1<<2)
	{
		printf("key_eint18");
		rEXT_INT_2_PEND |= (1<<2);
	}
	else if(rEXT_INT_2_PEND &= 1<<3)
	{
		printf("key_eint19");
		rEXT_INT_2_PEND |= (1<<3);
	}
	
	
	//������ж���ϵҲҪ����
	intc_clearvectaddr();
}



















