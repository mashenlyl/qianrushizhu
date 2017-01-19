#include "stdio.h"
#include "int.h"

#define		WTCON 		(0xE2700000)  
#define 	WTDAT 		(0xE2700004) 
#define		WTCNT 		(0xE2700008) 
#define 	WTCLRINT	(0xE270000C)

#define		rWTCON		(*(volatile unsigned int *)WTCON)
#define		rWTDAT		(*(volatile unsigned int *)WTDAT)
#define		rWTCNT		(*(volatile unsigned int *)WTCNT)
#define		rWTCLRINT	(*(volatile unsigned int *)WTCLRINT)

extern int g_bootdelay;
extern int g_isgo;

void wdt_init_interrupt(void)
{
	//���ȣ����Ǿ�����Ԥ��Ƶ��(8~15),�����㣬Ȼ��������ֵΪ66����Ϊʱ��Դ��PCLK��66MHz���õ�1MHz
	rWTCON &= ~(0xff<<8);
	rWTCON |= (65<<8);
	
	//Ȼ�����÷�Ƶ����3~4���������㣬Ȼ������ֵΪ128���õ�������128us
	rWTCON &= ~(0x3<<3);
	rWTCON |= (0x3<<3);
	
	//Ȼ���ѡ���ж�ģʽ�ˣ�2�����رո�λģʽ��0��
	rWTCON |= (1<<2);
	rWTCON &= ~(1<<0);
	
	//���ü���ֵ�ˣ�������Ϊ1.28s
	rWTDAT = 7813;				
	rWTCNT = 7813;
	
	//��󣬶����ú��ˣ��Ϳ������Ź���ʱ���ˣ�5��
	rWTCON |= (1<<5);
}

void isr_wdt(void)
{
	//������Ҫ������
	//һ��������������Ҫ��ִ�е�isr����
	//������ʵ�ּ�ʱ�Ĺ��ܣ��������������һ�֣��㿴����ʱ�Ļ�������԰���ȥ���ڶ��֣�����Բ���
	g_bootdelay--;
	
	//�㰴����������Ҿ����㿴��������ȥ��,
	putchar('\b');
	printf("%d", g_bootdelay);
	
	if(g_bootdelay == 0)
	{
		g_isgo = 1;
	}
	
	
	//�ڶ�������������
	//����ж�
	intc_clearvectaddr();
	rWTCLRINT = 1;					//�����������������Ϳ���������
}


void wd_timer_init(void)
{
	wdt_init_interrupt();
	// ���������Ҫʹ���жϣ���Ҫ�����жϳ�ʼ����������ʼ���жϿ�����
	system_init_exception();
	// ��isr���жϿ�����Ӳ��
	intc_setvectaddr(NUM_WDT, isr_wdt);
	// ʹ���ж�
	intc_enable(NUM_WDT);
}























