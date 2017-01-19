/*
 *
 *	名字：led_6.S
 *	作用：实现流水灯的效果，流水灯也叫走马灯,走过来又走过去
 *
 */
 
#define GPJ0CON  0xE0200240			
#define GPJ0DAT  0xE0200244

.global _start				
 _start:						
	ldr r0, =GPJ0CON			
	ldr r1, =0x11111111
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


 
 
 
 
 
 
 
 
 
 
 