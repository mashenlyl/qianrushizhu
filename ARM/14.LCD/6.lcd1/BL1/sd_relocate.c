
#define SD_START_BLOCK	45
#define SD_ALL_BLOCK	(3072*2)
#define SD_COPY_ADDR	0x23E00000

//������Ҫ�����������
//��һ���ǣ�ѡ�ĸ�SD����ͨ������0����2�����ǵ�0ͨ���Ѿ����ڲ���inandռ����
//�ڶ����ǣ���ʼ�����ţ�45
//�������ǣ��ܹ��������ţ�32
//���ĸ��ǣ���ַ��Ҫcopy���ĸ���ַ��������0x23E00000
//������ǣ�0��Ҫ��Ҫ����ʲô������ѡ��Ҫ
typedef int (* pCopySDMMCtoMem)(int, unsigned int, unsigned short, unsigned int*, int);
typedef void(*pFunc)(void);

void copy_bl2_to_ddr(void)
{
	//��һ�������ȣ�����Ҫ��bl2�е����ݸ��Ƶ�ddr�ϣ���������������Ǹ�����
	//����һ������ָ��,Ȼ����������ַ,�����ַ�������copy�����ĵ�ַ,�ҵ����Ϳ��Է����������
	pCopySDMMCtoMem p1 = (*(unsigned int *)0xD0037F98);
	
	//���������Ϳ�����
	p1(2, SD_START_BLOCK, SD_ALL_BLOCK, SD_COPY_ADDR, 0);
	
	//�ڶ�����Ȼ��ֱ���ϣ�ֱ��ȥddr��ִ�к���
	pFunc p2 = SD_COPY_ADDR;
	p2();
	
}






























