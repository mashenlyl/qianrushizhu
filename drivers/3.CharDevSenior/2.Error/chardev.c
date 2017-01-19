#include <linux/kernel.h>		// printk
#include <linux/init.h>			// __exit __init
#include <linux/module.h>      // module_init module_exit
#include <linux/fs.h>			// file_operations
#include <linux/uaccess.h>		// copy_from_user copy_to_user
#include <linux/string.h>
#include <mach/gpio-bank.h>		// S5PV210_GPJ0CON S5PV210_GPJ0DAT
#include <mach/regs-gpio.h>		// S5PV210_GPJ0_BASE
#include <linux/ioport.h>		// request_mem_region release_mem_region
#include <asm/io.h>				// ioremap iounmap
#include <linux/cdev.h>			// cdev_xxx函数

#define	 NAME				"Test"
#define  TEST_MAJOR 		200
#define  TEST_NUM_MINORS	1

// 先使用指针的方式来操控寄存器，内核中是使用专门的IO函数来读写寄存器的
// 我们这里使用的是虚拟地址来操控的，相应寄存器地址的宏定义在gpio-bank.h文件中
#define GPJ0CON		S5PV210_GPJ0CON
#define GPJ0DAT		S5PV210_GPJ0DAT

#define rGPJ0CON	*((volatile unsigned int *)GPJ0CON)
#define rGPJ0DAT	*((volatile unsigned int *)GPJ0DAT)

#define GPJ0CON_PA		0xE0200240
#define GPJ0DAT_PA		0xE0200244

volatile unsigned int * rpGPJ0CON;
volatile unsigned int * rpGPJ0DAT;

//int major = -1;
dev_t major = -1;
char kbuf[100];
static struct cdev test_cdev;

// 定义file_operations结构体中的元素相对应的函数
// 打开文件的函数
int test_chrdev_open (struct inode *inode, struct file *file)
{
	// 在打开文件的同时，打开LED
	rGPJ0CON = 0x11111111;
	rGPJ0DAT = ((0<<3) | (0<<4) | (0<<5));
	
	printk(KERN_INFO "test_chrdev_open open\n");
	return 0;
}

// 关闭文件的函数
int test_chrdev_close(struct inode *inode, struct file *file)
{
	// 在关闭文件的同时，关闭LED
	rGPJ0DAT = ((1<<3) | (1<<4) | (1<<5));
	
	printk(KERN_INFO "test_chrdev_close close\n");
	return 0;
}

// 读文件的函数，驱动和应用层之间是不可以直接进行数据交互的，因为他们在不同的虚拟地址空间上
// 所以，首先要把数据传给内核，然后再写硬件，可以使用函数copy_from_user和copy_to_user来传数据
ssize_t test_chrdev_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
	int ret = -1;
	
	// memcpy(buf, kbuf, size);

	ret = copy_to_user(buf, kbuf, size);
	// 成功则返回0，不成功则返回有多少没有成功传输过来的
	if (ret)
	{
		printk(KERN_ERR "copy_to_user error\n");
	}
	
	printk(KERN_INFO "test_chrdev_read\n");
	return 0;
}

// 写文件的函数
static ssize_t test_chrdev_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
	int ret = -1;

	//memcpy(kbuf, buf, count);
	
	ret = copy_from_user(kbuf, buf, count);
	// 成功则返回0，不成功则返回有多少没有成功传输过来的
	if (ret)
	{
		printk(KERN_ERR "copy_from_user error\n");
	}
	
	// 这里写错了，使用strcmp来作比较，然后就打印出一大段好奇怪的东西，发生了段错误
	// 0就是灭，1就是亮
	if (kbuf[0] == '1')
	{
		rGPJ0CON = 0x11111111;
		rGPJ0DAT = ((0<<3) | (0<<4) | (0<<5));
	}
	else if(kbuf[0] == '0')
	{
		rGPJ0DAT = ((1<<3) | (1<<4) | (1<<5));
	}
	
#if 0
	// on就是亮，off就是灭
	if (!strcmp(kbuf, "on"))
	{
		rGPJ0CON = 0x11111111;
		rGPJ0DAT = ((0<<3) | (0<<4) | (0<<5));
	}
	else if(!strcmp(kbuf, "off"))
	{
		rGPJ0DAT = ((1<<3) | (1<<4) | (1<<5));
	}
#endif
	
	printk(KERN_INFO "test_chrdev_write\n");
	return 0;
}

// 定义一个file_operations类型的结构体变量，可以直接在内核源代码中copy出来
static const struct file_operations test_fops = {
	.owner		= THIS_MODULE,					// 这个是照搬的，不需要变动的
	
	.open		= test_chrdev_open,
	.release	= test_chrdev_close,
	.read 		= test_chrdev_read,
	.write		= test_chrdev_write,
};

// insmod的安装模块的函数
static int __init test_init(void)
{
	int retval;
	
/*
	// 注册驱动程序，使用函数register_chrdev()
	// 如果给major传0的话，内核就会自动分配主设备号，返回值是主设备号
	major = register_chrdev(0, NAME, &test_fops);
	if (major < 0)
	{
		// 使用errno（在errno_base.h），出错的时候会返回出错详情；
		return -EINVAL;
	}
*/
	major = MKDEV(TEST_MAJOR, 0);
	// 第一步：分配主设备号，MKDEV宏是得到一个主设备号加次设备号
	retval = register_chrdev_region(major, TEST_NUM_MINORS, NAME);
	if (retval)
		goto flag1;
	
	// 第二步：cdev结构体初始化，把cdev结构体赋值，还有和file_operations结构体绑定在一起
	cdev_init(&test_cdev, &test_fops);
	
	// 第三步：注册驱动
	retval = cdev_add(&test_cdev, major, TEST_NUM_MINORS);
	if (retval)
		goto flag2;
	
	// printk(KERN_INFO "GPJ0CON = %x\n", rGPJ0CON);


	// 动态映射
	// 第一步：申请内存资源，需要放物理地址进去
	if (!request_mem_region(GPJ0CON_PA, 4, "GPJ0CON_PA"))
		goto flag3;
	if (!request_mem_region(GPJ0DAT_PA, 4, "GPJ0DAT_PA"))
		goto flag3;
	
	// 第二步：建立映射，传的是物理地址，得到虚拟地址
	rpGPJ0CON = ioremap(GPJ0CON_PA, 4);
	if (rpGPJ0CON == NULL)
		goto flag4;
	rpGPJ0DAT = ioremap(GPJ0DAT_PA, 4);
	if (rpGPJ0DAT == NULL)
		goto flag4;
	
	// 第三步，使用虚拟地址，打开LED灯
	*rpGPJ0CON = 0x11111111;
	*rpGPJ0DAT = ((0<<3) | (0<<4) | (0<<5));
	
	printk(KERN_INFO "test_init install\n");
	goto flag0;
	
	// 错误处理机制，中途出错的倒影式错误处理方法；为啥需要错误处理机制，譬如，我们的注册驱动的程序
	// 出错了，然后我们就退出了程序，导致我们注册的主设备号没办法释放掉，这样就容易导致内核崩溃了；
	// 所以，我们就需要在它退出程序之前去把我们已经注册了的主设备号释放掉；这里就使用了goto进行跳转
	// 它这里没有break，所以是按顺序执行下去的；
flag4:
	release_mem_region(GPJ0CON_PA, 4);
	release_mem_region(GPJ0DAT_PA, 4);
flag3:
	cdev_del(&test_cdev);
flag2:
	unregister_chrdev_region(major, TEST_NUM_MINORS);
flag1:
	return -1;
flag0:
	return 0;
}

// rmmod的卸载模块的函数
static void __exit test_exit(void)
{
/*
	// 卸载驱动程序
	unregister_chrdev(major, NAME);
*/
	
	// 第一步：注销驱动
	cdev_del(&test_cdev);
	
	// 第二步：注销主设备号
	unregister_chrdev_region(major, TEST_NUM_MINORS);

	// 第四步，关灯
	*rpGPJ0DAT = ((1<<3) | (1<<4) | (1<<5));
	
	// 第五步，解除映射关系，这里传的是虚拟地址
	iounmap(rpGPJ0CON);
	iounmap(rpGPJ0DAT);
	
	// 第六步，释放内存资源，也是放物理内存地址进去
	release_mem_region(GPJ0CON_PA, 4);
	release_mem_region(GPJ0DAT_PA, 4);

	
/*
	// 在卸载模块的同时，关闭LED
	rGPJ0DAT = ((1<<3) | (1<<4) | (1<<5));
*/
	
	printk(KERN_INFO "test_exit exit\n");
}

// 把安装模块的函数和insmod命令绑定起来
// 把卸载模块的函数和rmmod命令绑定起来
module_init(test_init);
module_exit(test_exit);

// 下面的宏是modinfo命令的时候显示的信息
// 许可证信息
MODULE_LICENSE("GPL");
// 作者
MODULE_AUTHOR("lyl");
// 模块的介绍
MODULE_DESCRIPTION("lyl test module");




