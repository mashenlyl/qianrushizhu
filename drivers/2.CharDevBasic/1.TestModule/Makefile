
# 内核源码树的路径
KERN_DIR = /home/lyl/driver/kernel

# obj-m表示编译为模块的模式
obj-m += Test_Module.o

all:
	make -C $(KERN_DIR) M=`pwd` modules

cp:
	cp ./*.ko /home/lyl/rootfs/rootfs/drivers/

.PHONY: clean	
clean:
	make -C $(KERN_DIR) M=`pwd` modules clean


























