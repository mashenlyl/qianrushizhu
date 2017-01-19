
#define SD_START_BLOCK	45
#define SD_ALL_BLOCK	(3072*2)
#define SD_COPY_ADDR	0x23E00000

//这里需要输入五个参数
//第一个是：选哪个SD卡的通道，有0或者2，我们的0通道已经被内部的inand占领了
//第二个是：开始扇区号：45
//第三个是：总共的扇区号：32
//第四个是：地址，要copy到哪个地址，我们是0x23E00000
//第五个是：0，要不要返回什么，我们选择不要
typedef int (* pCopySDMMCtoMem)(int, unsigned int, unsigned short, unsigned int*, int);
typedef void(*pFunc)(void);

void copy_bl2_to_ddr(void)
{
	//第一步：首先，就是要把bl2中的内容复制到ddr上，就运用了上面的那个函数
	//定义一个函数指针,然后访问这个地址,这个地址上有这个copy函数的地址,找到它就可以访问这个函数
	pCopySDMMCtoMem p1 = (*(unsigned int *)0xD0037F98);
	
	//运用它，就可以了
	p1(2, SD_START_BLOCK, SD_ALL_BLOCK, SD_COPY_ADDR, 0);
	
	//第二步：然后，直接上，直接去ddr上执行函数
	pFunc p2 = SD_COPY_ADDR;
	p2();
	
}






























