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
#include <linux/cdev.h>			// cdev_xxx����

#define	 NAME				"Test"
#define  TEST_MAJOR 		200
#define  TEST_NUM_MINORS	1

// ��ʹ��ָ��ķ�ʽ���ٿؼĴ������ں�����ʹ��ר�ŵ�IO��������д�Ĵ�����
// ��������ʹ�õ��������ַ���ٿصģ���Ӧ�Ĵ�����ַ�ĺ궨����gpio-bank.h�ļ���
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

// ����file_operations�ṹ���е�Ԫ�����Ӧ�ĺ���
// ���ļ��ĺ���
int test_chrdev_open (struct inode *inode, struct file *file)
{
	// �ڴ��ļ���ͬʱ����LED
	rGPJ0CON = 0x11111111;
	rGPJ0DAT = ((0<<3) | (0<<4) | (0<<5));
	
	printk(KERN_INFO "test_chrdev_open open\n");
	return 0;
}

// �ر��ļ��ĺ���
int test_chrdev_close(struct inode *inode, struct file *file)
{
	// �ڹر��ļ���ͬʱ���ر�LED
	rGPJ0DAT = ((1<<3) | (1<<4) | (1<<5));
	
	printk(KERN_INFO "test_chrdev_close close\n");
	return 0;
}

// ���ļ��ĺ�����������Ӧ�ò�֮���ǲ�����ֱ�ӽ������ݽ����ģ���Ϊ�����ڲ�ͬ�������ַ�ռ���
// ���ԣ�����Ҫ�����ݴ����ںˣ�Ȼ����дӲ��������ʹ�ú���copy_from_user��copy_to_user��������
ssize_t test_chrdev_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
	int ret = -1;
	
	// memcpy(buf, kbuf, size);

	ret = copy_to_user(buf, kbuf, size);
	// �ɹ��򷵻�0�����ɹ��򷵻��ж���û�гɹ����������
	if (ret)
	{
		printk(KERN_ERR "copy_to_user error\n");
	}
	
	printk(KERN_INFO "test_chrdev_read\n");
	return 0;
}

// д�ļ��ĺ���
static ssize_t test_chrdev_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
	int ret = -1;

	//memcpy(kbuf, buf, count);
	
	ret = copy_from_user(kbuf, buf, count);
	// �ɹ��򷵻�0�����ɹ��򷵻��ж���û�гɹ����������
	if (ret)
	{
		printk(KERN_ERR "copy_from_user error\n");
	}
	
	// ����д���ˣ�ʹ��strcmp�����Ƚϣ�Ȼ��ʹ�ӡ��һ��κ���ֵĶ����������˶δ���
	// 0������1������
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
	// on��������off������
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

// ����һ��file_operations���͵Ľṹ�����������ֱ�����ں�Դ������copy����
static const struct file_operations test_fops = {
	.owner		= THIS_MODULE,					// ������հ�ģ�����Ҫ�䶯��
	
	.open		= test_chrdev_open,
	.release	= test_chrdev_close,
	.read 		= test_chrdev_read,
	.write		= test_chrdev_write,
};

// insmod�İ�װģ��ĺ���
static int __init test_init(void)
{
	int retval;
	
/*
	// ע����������ʹ�ú���register_chrdev()
	// �����major��0�Ļ����ں˾ͻ��Զ��������豸�ţ�����ֵ�����豸��
	major = register_chrdev(0, NAME, &test_fops);
	if (major < 0)
	{
		// ʹ��errno����errno_base.h���������ʱ��᷵�س������飻
		return -EINVAL;
	}
*/
	major = MKDEV(TEST_MAJOR, 0);
	// ��һ�����������豸�ţ�MKDEV���ǵõ�һ�����豸�żӴ��豸��
	retval = register_chrdev_region(major, TEST_NUM_MINORS, NAME);
	if (retval)
		goto flag1;
	
	// �ڶ�����cdev�ṹ���ʼ������cdev�ṹ�帳ֵ�����к�file_operations�ṹ�����һ��
	cdev_init(&test_cdev, &test_fops);
	
	// ��������ע������
	retval = cdev_add(&test_cdev, major, TEST_NUM_MINORS);
	if (retval)
		goto flag2;
	
	// printk(KERN_INFO "GPJ0CON = %x\n", rGPJ0CON);


	// ��̬ӳ��
	// ��һ���������ڴ���Դ����Ҫ�������ַ��ȥ
	if (!request_mem_region(GPJ0CON_PA, 4, "GPJ0CON_PA"))
		goto flag3;
	if (!request_mem_region(GPJ0DAT_PA, 4, "GPJ0DAT_PA"))
		goto flag3;
	
	// �ڶ���������ӳ�䣬�����������ַ���õ������ַ
	rpGPJ0CON = ioremap(GPJ0CON_PA, 4);
	if (rpGPJ0CON == NULL)
		goto flag4;
	rpGPJ0DAT = ioremap(GPJ0DAT_PA, 4);
	if (rpGPJ0DAT == NULL)
		goto flag4;
	
	// ��������ʹ�������ַ����LED��
	*rpGPJ0CON = 0x11111111;
	*rpGPJ0DAT = ((0<<3) | (0<<4) | (0<<5));
	
	printk(KERN_INFO "test_init install\n");
	goto flag0;
	
	// ��������ƣ���;����ĵ�Ӱʽ����������Ϊɶ��Ҫ��������ƣ�Ʃ�磬���ǵ�ע�������ĳ���
	// �����ˣ�Ȼ�����Ǿ��˳��˳��򣬵�������ע������豸��û�취�ͷŵ������������׵����ں˱����ˣ�
	// ���ԣ����Ǿ���Ҫ�����˳�����֮ǰȥ�������Ѿ�ע���˵����豸���ͷŵ��������ʹ����goto������ת
	// ������û��break�������ǰ�˳��ִ����ȥ�ģ�
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

// rmmod��ж��ģ��ĺ���
static void __exit test_exit(void)
{
/*
	// ж����������
	unregister_chrdev(major, NAME);
*/
	
	// ��һ����ע������
	cdev_del(&test_cdev);
	
	// �ڶ�����ע�����豸��
	unregister_chrdev_region(major, TEST_NUM_MINORS);

	// ���Ĳ����ص�
	*rpGPJ0DAT = ((1<<3) | (1<<4) | (1<<5));
	
	// ���岽�����ӳ���ϵ�����ﴫ���������ַ
	iounmap(rpGPJ0CON);
	iounmap(rpGPJ0DAT);
	
	// ���������ͷ��ڴ���Դ��Ҳ�Ƿ������ڴ��ַ��ȥ
	release_mem_region(GPJ0CON_PA, 4);
	release_mem_region(GPJ0DAT_PA, 4);

	
/*
	// ��ж��ģ���ͬʱ���ر�LED
	rGPJ0DAT = ((1<<3) | (1<<4) | (1<<5));
*/
	
	printk(KERN_INFO "test_exit exit\n");
}

// �Ѱ�װģ��ĺ�����insmod���������
// ��ж��ģ��ĺ�����rmmod���������
module_init(test_init);
module_exit(test_exit);

// ����ĺ���modinfo�����ʱ����ʾ����Ϣ
// ���֤��Ϣ
MODULE_LICENSE("GPL");
// ����
MODULE_AUTHOR("lyl");
// ģ��Ľ���
MODULE_DESCRIPTION("lyl test module");




