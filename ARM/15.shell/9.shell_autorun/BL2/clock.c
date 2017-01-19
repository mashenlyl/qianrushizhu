// ʱ�ӿ���������ַ
#define ELFIN_CLOCK_POWER_BASE		0xE0100000	

// ʱ����صļĴ������ʱ�ӿ���������ַ��ƫ��ֵ
#define APLL_LOCK_OFFSET		0x00		
#define MPLL_LOCK_OFFSET		0x08

#define APLL_CON0_OFFSET		0x100
#define APLL_CON1_OFFSET		0x104
#define MPLL_CON_OFFSET			0x108

#define CLK_SRC0_OFFSET			0x200
#define CLK_SRC1_OFFSET			0x204
#define CLK_SRC2_OFFSET			0x208
#define CLK_SRC3_OFFSET			0x20c
#define CLK_SRC4_OFFSET			0x210
#define CLK_SRC5_OFFSET			0x214
#define CLK_SRC6_OFFSET			0x218
#define CLK_SRC_MASK0_OFFSET	0x280
#define CLK_SRC_MASK1_OFFSET	0x284

#define CLK_DIV0_OFFSET			0x300
#define CLK_DIV1_OFFSET			0x304
#define CLK_DIV2_OFFSET			0x308
#define CLK_DIV3_OFFSET			0x30c
#define CLK_DIV4_OFFSET			0x310
#define CLK_DIV5_OFFSET			0x314
#define CLK_DIV6_OFFSET			0x318
#define CLK_DIV7_OFFSET			0x31c

#define CLK_DIV0_MASK			0x7fffffff

// ��ЩM��P��S������ֵ���ǲ������ֲ��е���ʱ������ֵ���Ƽ����õ����ġ�
// ��Щ����ֵ�������Ƽ��ģ���˹������ȶ���������Լ����Ϲƴ�ճ������Ǿ�Ҫ
// �����ϸ���ԣ����ܱ�֤һ���ԡ�
#define APLL_MDIV      	 		0x7d		// 125
#define APLL_PDIV       		0x3
#define APLL_SDIV       		0x1

#define MPLL_MDIV				0x29b		// 667
#define MPLL_PDIV				0xc
#define MPLL_SDIV				0x1

#define set_pll(mdiv, pdiv, sdiv)	(1<<31 | mdiv<<16 | pdiv<<8 | sdiv)
#define APLL_VAL			set_pll(APLL_MDIV,APLL_PDIV,APLL_SDIV)
#define MPLL_VAL			set_pll(MPLL_MDIV,MPLL_PDIV,MPLL_SDIV)



#define RGE_CLK_SRC0	(ELFIN_CLOCK_POWER_BASE + CLK_SRC0_OFFSET)
#define RGE_APLL_CLK	(ELFIN_CLOCK_POWER_BASE + APLL_LOCK_OFFSET)
#define RGE_MPLL_CLK	(ELFIN_CLOCK_POWER_BASE + MPLL_LOCK_OFFSET)
#define RGE_CLK_DIV0	(ELFIN_CLOCK_POWER_BASE + CLK_DIV0_OFFSET)
#define RGE_APLL_CON0	(ELFIN_CLOCK_POWER_BASE + APLL_CON0_OFFSET)
#define RGE_MPLL_CON0	(ELFIN_CLOCK_POWER_BASE + MPLL_CON_OFFSET)


#define rRGE_CLK_SRC0	(*(volatile unsigned int *)RGE_CLK_SRC0)
#define rRGE_APLL_CLK	(*(volatile unsigned int *)RGE_APLL_CLK)
#define rRGE_MPLL_CLK	(*(volatile unsigned int *)RGE_MPLL_CLK)
#define rRGE_CLK_DIV0	(*(volatile unsigned int *)RGE_CLK_DIV0)
#define rRGE_APLL_CON0	(*(volatile unsigned int *)RGE_APLL_CON0)
#define rRGE_MPLL_CON0	(*(volatile unsigned int *)RGE_MPLL_CON0)

void clock_init(void)
{
	// 1 ���ø���ʱ�ӿ��أ���ʱ��ʹ��PLL
	rRGE_CLK_SRC0 = 0x0;
	
	// 2 ��������ʱ�䣬ʹ��Ĭ��ֵ����
	// ����PLL��ʱ�Ӵ�Fin������Ŀ��Ƶ��ʱ����Ҫһ����ʱ�䣬������ʱ��
	rRGE_APLL_CLK = 0x0000FFFF;
	rRGE_MPLL_CLK = 0x0000FFFF;
	
	// 3 ���÷�Ƶ
	rRGE_CLK_DIV0 = 0x14131440;
	
	// 4 ����PLL
	// FOUT = MDIV*FIN/(PDIV*2^(SDIV-1))=0x7d*24/(0x3*2^(1-1))=1000 MHz
	rRGE_APLL_CON0 = APLL_VAL;
	rRGE_MPLL_CON0 = MPLL_VAL;
	
	// 5 ���ø���ʱ�ӿ���,ʹ��PLL
	rRGE_CLK_SRC0 = 0x10001111;
}






































