//ע�⣺������˴���ͨ�Ų��а������ǼĴ����ĵ�ַд���ˣ�����ճ����ʱ������ˣ���GPA0�ĵ�ַ���ƹ�ȥ��
//�����˴��󣬲������a

#define	GPA0CON		0xE0200000
#define ULCON0 		0xE2900000
#define UCON0 		0xE2900004
#define UFCON0 		0xE2900008
#define UMCON0 		0xE290000C
#define UBRDIV0 	0xE2900028
#define UDIVSLOT0	0xE290002C
#define UTRSTAT0	0xE2900010
#define UTXH0		0xE2900020
#define URXH0		0xE2900024


#define rGPAOCON		(*(volatile unsigned int *)GPA0CON)
#define rULCON0			(*(volatile unsigned int *)ULCON0)
#define rUCON0			(*(volatile unsigned int *)UCON0)
#define rUFCON0			(*(volatile unsigned int *)UFCON0)
#define rUMCON0			(*(volatile unsigned int *)UMCON0)
#define rUBRDIV0		(*(volatile unsigned int *)UBRDIV0)
#define rUDIVSLOT0		(*(volatile unsigned int *)UDIVSLOT0)
#define rUTRSTAT0		(*(volatile unsigned int *)UTRSTAT0)
#define rUTXH0			(*(volatile unsigned int *)UTXH0)
#define rURXH0			(*(volatile unsigned int *)URXH0)



void uart_init(void)
{
	//��һ�������Ⱦ�������GPA0������������Ϊ�˴򿪶˿ڣ�ֻ�д򿪶˿ڣ���Ϣ�Żᷢ�ͳ�ȥ��
	//д�����ƻ��ǱȽϺõģ���Ȼ���ֻ�ǵ�һλ��ʼ��0~7
	//λ���������Ȱ��Ǽ�λ���㣬Ȼ��ֵ��ok��
	rGPAOCON &= (~(0xff<<0));			//��������һ���ֺţ�������30�г��˴���
	rGPAOCON |= 0x00000022;			//���ﲻ����д������:0b00100010bit[3:0] = 0b0010 bit[7:4] = 0b0010
	
	//�ڶ��������ùؼ��ļĴ���,��Щ�����������ֲ��п��ģ��ڱʼ����С�
	//�����ǳ�ʼ��UART������
	rULCON0 = 0x3;
	rUCON0 = 0x5;
	rUFCON0 = 0;
	rUMCON0 = 0;
	
	//�����������ò����ʣ����㲨����
	//������Ǹ�Ƶ�ʿ���ȡ66.7MHz��Ҳ�ǿ���ȡ66MHz
	//DIV_VAL = (PCLK / (bps x 16)) ?1
	//DIV_VAL = (66000000 / (115200 x 16)) - 1			�������34��������0.80729
	//rUBRDIV0 = 34;
	//(num of 1's in UDIVSLOTn)/16 = 0.7			0.8 ���������12.8
	//rUDIVSLOT0 = 0xdfdd;
	//����66700000ʱ�����������35.1870			0.2�������3��֮�����������Ϳ�����Ӧ��ֵ��
	//�����ͳ�ʼ��������
	rUBRDIV0 = 34;
	rUDIVSLOT0 = 0xdfdd;
	
}


//����һ���ֽ�
void uart_putc(char c)
{
	//�����ַ���ʱ��Ҫע��CPU�ȷ��ͻ��������ٶ�Ҫ��ܶ�ģ���������Ҫ�����ͻ������Ƿ��Ѿ�������������
	//֮���ٸ�������
	//��������0���Ƿǿգ�1���ǿ��ˣ�����Ҫ��1��ʱ�������ѭ������Ҫ����ѭ����Ҫ��0��ʱ��ſ��ԣ�����
	//�����ˣ�
	while(!(rUTRSTAT0 & (1<<1)));			//�����߼��������������棨��0���ͱ�Ϊ�٣�0��
	rUTXH0 = c;
	
}

int g_getc(void)
{
	if((rUTRSTAT0 & (1<<0)))
	{
		return 1;
	}
	else
		return 0;
}

//����һ���ֽ�
char uart_getc(void)
{
	//ֻ�ǽ���һ���ֽ�
	while(!(rUTRSTAT0 & (1<<0)));
	
	return (rURXH0 & 0xff);		//���ռĴ�����ֻ�а�λ����Ч�ģ������Ķ�����Ч�ģ�����������λ������
									
}

inline void putc(char c)
{
	uart_putc(c);
}

inline char getc(void)
{
	uart_getc();
}



























