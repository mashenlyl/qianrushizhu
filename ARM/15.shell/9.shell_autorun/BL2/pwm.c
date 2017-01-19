
//�������Ӧ�ļĴ���
#define		GPD0CON		(0xE02000A0)
#define 	TCFG0		(0xE2500000)
#define		TCFG1		(0xE2500004)
#define		CON			(0xE2500008)
#define		TCNTB2		(0xE2500024)
#define		TCMPB2		(0xE2500028)

#define 	rGPD0CON	(*(volatile unsigned int *)GPD0CON)
#define 	rTCFG0		(*(volatile unsigned int *)TCFG0)
#define 	rTCFG1		(*(volatile unsigned int *)TCFG1)
#define 	rCON		(*(volatile unsigned int *)CON)
#define 	rTCNTB2		(*(volatile unsigned int *)TCNTB2)
#define 	rTCMPB2		(*(volatile unsigned int *)TCMPB2)

void pwm_init(void)
{
	//��ʵӲ���ϰ��������˺ܶ๤���ˣ�Ȼ�����ǾͲ���ʹ���жϾͿ������PWM������
	// ��ʼ��GPD0CON��8~11��,ѡ��TOUTģʽ���������㣬Ȼ��д2
	rGPD0CON &= ~(0xf<<8);
	rGPD0CON |= (2<<8);
	
	// ���üĴ���TCFG0(8~15)������rescaler 1Ϊ65���õ��˾���1MHz
	rTCFG0 &= ~(0xff<<8);
	rTCFG0 |= (65<<8);
	
	// ���üĴ���TCFG1(8~11),����MUX2��ѡ��1/2��0001�����õ�500kHz��0.2us��
	rTCFG1 &= ~(0xf<<8);
	rTCFG1 |= (1<<8);
	
	// ���üĴ���CON time2�ε�
	//�Զ�����
	rCON |= (1<<15);
	
	//���üĴ���TCNTB2����������Ƶ����2kHz��0.5ms���ģ�ռ������50%�����Եõ�ֵΪ500
	rTCNTB2 = 500;
	rTCMPB2 = 250;
	
	// �ֶ�ˢ�뵽TCNT���֮���ֹر��ֶ�ˢ��
	rCON |= (1<<13);
	rCON &= ~(1<<13);
	
	//���һ�����ǿ�����ʱ��
	rCON |= (1<<12);
	
}

void buzzer_off(void)
{
	rGPD0CON &= ~(0xf<<8);
	rGPD0CON |= (0<<8);
}

void buzzer_on(void)
{
	rGPD0CON &= ~(0xf<<8);
	rGPD0CON |= (2<<8);
}


























