#define GPJ0CON  0xE0200240			
#define GPJ0DAT  0xE0200244

#define rGPJ0CON	*((volatile unsigned int *)GPJ0CON)	 //������൱��������������������
#define rGPJ0DAT	*((volatile unsigned int *)GPJ0DAT)		     //*p

void delay(void);

//�������������ʵ��һ��һ���Ĺ���
void led_blink(void)
{
	//unsigned int *p = (unsigned int *)GPJ0CON;		//ǿ������ת��
	//unsigned int *p1 = (unsigned int *)GPJ0DAT;
	
	//*p = 0x11111111;				//���Ǹ��ӿڵ�ģʽ��Ϊ���ģʽ
	rGPJ0CON = 0x11111111;
	
	while(1)			//��ѭ��
	{
		//����
		rGPJ0DAT = (0<<3)|(0<<4)|(0<<5);		
	
		//�ӳ�
		delay();
	
		//Ϩ��
		rGPJ0DAT = (1<<3)|(1<<4)|(1<<5);		//����д�����Ǹ�*p = (1<<3)|(1<<4)|(1<<5),������
												//���ǰѽӿڹر��ˣ����Ժ���Ͳ�����
		//�ӳ�
		delay();
	}

}

void led1(void)
{
	//��ʼ��
	rGPJ0CON = 0x11111111;
	//һ����
	rGPJ0DAT = (0<<3)|(1<<4)|(1<<5);
}

void led2(void)
{
	//��ʼ��
	rGPJ0CON = 0x11111111;
	//������
	rGPJ0DAT = (0<<3)|(0<<4)|(1<<5);
}

void led3(void)
{
	//��ʼ��
	rGPJ0CON = 0x11111111;
	//������
	rGPJ0DAT = (0<<3)|(0<<4)|(0<<5);
}

void led_off(void)
{
	rGPJ0CON = 0x11111111;
	//ȫ����
	rGPJ0DAT = (1<<3)|(1<<4)|(1<<5);
}


void delay(void)
{
	volatile unsigned int i = 900000;		//volatile����˼�����ñ���������������Ǹ��Ż���
											//����������Ż����Ϳ����𲻵��ӳٵĹ�����
	while(i--);								//����ÿ�ζ�Ҫ���Ǹ�����i�ĵ�ַ�����iȡ����������ȡ�ϴε�ֵ
}											//��Щ�����Ǹ���������ֵ�Ǻ����õģ�����Ĵ����������ַ

//�򵥵�˵ʹ��volatile��Ŀ�ľ���:
//�ö�volatile �����Ĵ�ȡ���ܻ��浽�Ĵ�����ÿ��ʹ��ʱ��Ҫ���´�ȡ��




//����#if 0 ...#endif �����ú��Ǹ�/**/��ע�͵�������һ���ģ������أ������и����ܾ��ǲü�ϵͳ������
//����������ã����ղص��ĵ���������ϸ��˵������Ҫ��ͨ��һ���궨���������õģ����ǰ��Ǹ�0��һ���궨��
//���滻��1��ʱ���ǲ��ִ�����������ˣ�0��ʱ���ǲ��ִ���Ͳ��������ˣ�Ҳ���Ǳ��ü����˵���˼

#if 0				
	//����ģʽ������Ķ��ǹ��ܴ���
	ldr r0, =GPJ0CON
	ldr r2, =GPD0CON
	ldr r3, =0x00000010
	ldr r1, =0x11111111
	str r1, [r0]
	str r3, [r2]
	
	//��Ϩ����ĸ��ƣ���Ϊһ��ʼĬ����0��,���Ծ�Ҫ�Ȱ���Ϩ�����Ϊʲô����ĵƲ���Ϩ���أ��Ǿ��ǳ���
	//ִ�еĺܿ죬�����û��������ִ����ȥ��
	ldr r0, =GPD0DAT
	ldr r1, =0xf				//ע�⣺�����Ǻ����װ���д��0x1�ģ�f����ȫ������1�������ĸ�1
	str r1, [r0]
	
flash:
	//������һ��
	ldr r0, =GPJ0DAT
	ldr r1, =(0<<3)|(1<<4)|(1<<5)
	str r1, [r0]
	
	//�ӳ�
	bl delay
	
	//�����ڶ���
	ldr r0, =GPJ0DAT
	ldr r1, =(1<<3)|(0<<4)|(1<<5)
	str r1, [r0]
	
	//�ӳ�
	bl delay
	
	//����������
	ldr r0, =GPJ0DAT
	ldr r1, =(1<<3)|(1<<4)|(0<<5)
	str r1, [r0]
	
	//�ӳ�
	bl delay
	
	//֮ǰ����ȫ��Ϩ��
	ldr r0, =GPJ0DAT
	ldr r1, =(1<<3)|(1<<4)|(1<<5)
	str r1, [r0]
	
	//�������ĸ�
	ldr r0, =GPD0DAT
	ldr r1, =0<<1
	str r1, [r0]
	
	//�ӳ�
	bl delay
	
	//Ϩ����ĸ�
	ldr r0, =GPD0DAT
	ldr r1, =1<<1
	str r1, [r0]
	
	//����������
	ldr r0, =GPJ0DAT
	ldr r1, =(1<<3)|(1<<4)|(0<<5)
	str r1, [r0]
	
	//�ӳ�
	bl delay
	
	//�����ڶ���
	ldr r0, =GPJ0DAT
	ldr r1, =(1<<3)|(0<<4)|(1<<5)
	str r1, [r0]
	
	//�ӳ�
	bl delay
	
	//������һ��
	ldr r0, =GPJ0DAT
	ldr r1, =(0<<3)|(1<<4)|(1<<5)
	str r1, [r0]
	
	b flash						
					
delay:
	ldr r2, =9000000
	ldr r3, =0x0
	
delay_loop:
	sub r2, r2, #1						 
	cmp r2, r3					
	bne delay_loop
	mov pc, lr		

#endif

/*
�ܽ᣺
1.��makefile�ϼ�ע�Ͳ�����//���������Ǵ���ģ�����ע�ͷ�ʽ��#����//��Ҫת�����\#,�������Ҽ���������ע�ͣ��ʹ��ˡ�
2.����volatile�������ˣ����������
*/

















