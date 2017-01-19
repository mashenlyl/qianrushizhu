#include "main.h"

#define ADC_REGISTER_BASE	0xE1700000

#define rTSADCCON0			(*(volatile unsigned int *)(ADC_REGISTER_BASE + 0x0))
#define rTSDATX0			(*(volatile unsigned int *)(ADC_REGISTER_BASE + 0xC))
#define rTSDATY0			(*(volatile unsigned int *)(ADC_REGISTER_BASE + 0x10))
#define rCLRINTADC0			(*(volatile unsigned int *)(ADC_REGISTER_BASE + 0x18))
#define rADCMUX				(*(volatile unsigned int *)(ADC_REGISTER_BASE + 0x1C))

void adc_init(void)
{
	//ѡ��12λ���ȵ�ADC���
	rTSADCCON0 |= (1<<16);
	//14λѡ���Ƶ
	rTSADCCON0 |= (1<<14);
	//13~6λѡ��ֶ��ٵģ�����ѡ��66/(65+1)=1MHz,�����㣬��дֵ
	//������������������󣬵������������
	rTSADCCON0 &= ~(0xFF<<6);
	rTSADCCON0 |= (65<<6);
	//��2λѡ������ģʽ��
	rTSADCCON0 &= ~(1<<2);
	//��1λҲ��ѡ������ģʽ
	rTSADCCON0 &= ~(1<<1);
	
	//���ѡ�����ĸ�ͨ���ģ�������ͨ��0
	rADCMUX &= ~(1<<0);
	
}

//static˵�������ڲ�ʹ�õĺ���
static void delay(void)
{
	volatile int i, j;
	for(i=0; i<4000; i++)
		for(j=0; j<1000; j++);
}

void adc_use(void)
{
	//���ȣ���ʼ��adc
	adc_init();
	
	unsigned int val = 0;
	
	while(1)
	{
		//��һ������ADC
		rTSADCCON0 |= (1<<0);
		//�ڶ������ȴ�ADCת�����,�жϵ�15λ�Ƿ���1����1�ͱ���ת�������
		while(!(rTSADCCON0 & (1<<15)));
		
		//����������ȡADC�е����ݣ�����������
		//��ȡ��������TSDATX0�Ĵ�����TSDATY0�Ĵ����ϵģ�
		val = rTSDATX0;
		printf("The rTSDATX0 bit14 = %d.\n", (val & (1<<14)));
		printf("ADC rTSDATX0 data = %d.\n", (val & (0xFFF<<0)));
		
		val = rTSDATY0;
		printf("The rTSDATY0 bit14 = %d.\n", (val & (1<<14)));
		printf("ADC rTSDATY0 data = %d.\n", (val & (0xFFF<<0)));
		
		//���Ĳ�����ʱһ��
		delay();
	}
	
	
}






















