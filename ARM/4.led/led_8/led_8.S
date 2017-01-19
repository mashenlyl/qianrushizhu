/*
 *
 *	名字：led_6.S
 *	作用：实现流水灯的效果，流水灯也叫走马灯,走过来又走过去
 *
 */
 
#define GPJ0CON  0xE0200240			
#define GPJ0DAT  0xE0200244
#define GPD0CON  0xE02000A0
#define GPD0DAT  0xE02000A4

.global _start				
 _start:
	ldr r0, =0xE010E81C
	ldr r1, =0x301
	str r1, [r0]
	
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


 
 
 
 
 
 
 
 
 
 
 