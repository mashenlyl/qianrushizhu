#define GPJ0CON  0xE0200240			
#define GPJ0DAT  0xE0200244

#define rGPJ0CON	*((volatile unsigned int *)GPJ0CON)	 //这里就相当于下面那两句代码的作用
#define rGPJ0DAT	*((volatile unsigned int *)GPJ0DAT)		     //*p

void delay(void);

//这个函数就用来实现一闪一闪的功能
void led_blink(void)
{
	//unsigned int *p = (unsigned int *)GPJ0CON;		//强制类型转换
	//unsigned int *p1 = (unsigned int *)GPJ0DAT;
	
	//*p = 0x11111111;				//把那个接口的模式调为输出模式
	rGPJ0CON = 0x11111111;
	
	while(1)			//死循环
	{
		//点亮
		rGPJ0DAT = (0<<3)|(0<<4)|(0<<5);		
	
		//延迟
		delay();
	
		//熄灭
		rGPJ0DAT = (1<<3)|(1<<4)|(1<<5);		//这里写成了那个*p = (1<<3)|(1<<4)|(1<<5),出错了
												//就是把接口关闭了，所以后面就不亮了
		//延迟
		delay();
	}

}


void delay(void)
{
	volatile unsigned int i = 900000;		//volatile的意思就是让编译器不对这进行那个优化了
											//如果进行了优化，就可能起不到延迟的功能了
	while(i--);								//就是每次都要在那个储存i的地址那里把i取出来而不是取上次的值
}											//这些对于那个经常会变的值是很有用的，比如寄存器，特殊地址

//简单的说使用volatile的目的就是:
//让对volatile 变量的存取不能缓存到寄存器，每次使用时需要重新存取。




//这里#if 0 ...#endif 的作用和那个/**/的注释的作用是一样的，但是呢，它还有个功能就是裁剪系统的作用
//关于这个作用，在收藏的文档里面又详细的说明，主要是通过一个宏定义来起作用的，就是把那个0用一个宏定义
//来替换，1的时候，那部分代码就起作用了，0的时候那部分代码就不起作用了，也就是被裁剪掉了的意思

#if 0				
	//设置模式，下面的都是功能代码
	ldr r0, =GPJ0CON
	ldr r2, =GPD0CON
	ldr r3, =0x00000010
	ldr r1, =0x11111111
	str r1, [r0]
	str r3, [r2]
	
	//先熄灭第四个灯，因为一开始默认是0的,所以就要先把它熄灭掉，为什么下面的灯不用熄灭呢，那就是程序
	//执行的很快，你根本没发现它就执行下去了
	ldr r0, =GPD0DAT
	ldr r1, =0xf				//注意：这里是很容易把它写成0x1的，f才是全部都是1，就是四个1
	str r1, [r0]
	
flash:
	//点亮第一个
	ldr r0, =GPJ0DAT
	ldr r1, =(0<<3)|(1<<4)|(1<<5)
	str r1, [r0]
	
	//延迟
	bl delay
	
	//点亮第二个
	ldr r0, =GPJ0DAT
	ldr r1, =(1<<3)|(0<<4)|(1<<5)
	str r1, [r0]
	
	//延迟
	bl delay
	
	//点亮第三个
	ldr r0, =GPJ0DAT
	ldr r1, =(1<<3)|(1<<4)|(0<<5)
	str r1, [r0]
	
	//延迟
	bl delay
	
	//之前三个全部熄灭
	ldr r0, =GPJ0DAT
	ldr r1, =(1<<3)|(1<<4)|(1<<5)
	str r1, [r0]
	
	//点亮第四个
	ldr r0, =GPD0DAT
	ldr r1, =0<<1
	str r1, [r0]
	
	//延迟
	bl delay
	
	//熄灭第四个
	ldr r0, =GPD0DAT
	ldr r1, =1<<1
	str r1, [r0]
	
	//点亮第三个
	ldr r0, =GPJ0DAT
	ldr r1, =(1<<3)|(1<<4)|(0<<5)
	str r1, [r0]
	
	//延迟
	bl delay
	
	//点亮第二个
	ldr r0, =GPJ0DAT
	ldr r1, =(1<<3)|(0<<4)|(1<<5)
	str r1, [r0]
	
	//延迟
	bl delay
	
	//点亮第一个
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
总结：
1.在makefile上加注释不能用//，这样做是错误的，它的注释方式是#不是//，要转义就是\#,在这里我加了那样的注释，就错了。
2.就是volatile的作用了，上面又详解
*/


















