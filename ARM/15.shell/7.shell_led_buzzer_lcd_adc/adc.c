#include "stdio.h"

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


void adc_on(void)
{
	unsigned int val = 0;
	
	//��һ������ADC
	rTSADCCON0 |= (1<<0);
	//�ڶ������ȴ�ADCת�����,�жϵ�15λ�Ƿ���1����1�ͱ���ת�������
	while(!(rTSADCCON0 & (1<<15)));
	
	//����������ȡADC�е����ݣ�����������
	//��ȡ��������TSDATX0�Ĵ�����TSDATY0�Ĵ����ϵģ�
	val = rTSDATX0;
	printf("ADC rTSDATX0 data = %d.\n", (val & (0xFFF<<0)));
}






















