#include <linux/kernel.h>		// printk
#include <linux/init.h>			// __exit __init
#include <linux/module.h>      // module_init module_exit
#include <linux/fs.h>			// file_operations

#define	 NAME		"Test"

int major = -1;

// ����file_operations�ṹ���е�Ԫ�����Ӧ�ĺ���
int test_chrdev_open (struct inode *inode, struct file *file)
{
	printk(KERN_INFO "test_chrdev_open open\n");
	return 0;
}

int test_chrdev_close(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "test_chrdev_close close\n");
	return 0;
}

// ����һ��file_operations���͵Ľṹ�����������ֱ�����ں�Դ������copy����
static const struct file_operations test_fops = {
	.owner		= THIS_MODULE,					// ������հ�ģ�����Ҫ�䶯��
	
	.open		= test_chrdev_open,
	.release	= test_chrdev_close,
};

// insmod�İ�װģ��ĺ���
static int __init test_init(void)
{
	// ע����������ʹ�ú���register_chrdev()
	// �����major��0�Ļ����ں˾ͻ��Զ��������豸�ţ�����ֵ�����豸��
	major = register_chrdev(0, NAME, &test_fops);
	if (major < 0)
	{
		// ʹ��errno����errno_base.h���������ʱ��᷵�س������飻
		return -EINVAL;
	}
				  			  
	printk(KERN_INFO "test_init install\n");
	return 0;
}

// rmmod��ж��ģ��ĺ���
static void __exit test_exit(void)
{
	// ж����������
	unregister_chrdev(major, NAME);
	
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




