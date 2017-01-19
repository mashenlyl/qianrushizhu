
# 内核源码树的路径
KERN_DIR = /home/lyl/driver/kernel

# obj-m表示编译为模块的模式
obj-m += chardev_app.o

all:
	make -C $(KERN_DIR) M=`pwd` modules
	arm-linux-gcc app.c -o app

cp:
	cp ./*.ko /home/lyl/rootfs/rootfs/drivers/
	cp ./app /home/lyl/rootfs/rootfs/drivers/

.PHONY: clean	
clean:
	make -C $(KERN_DIR) M=`pwd` modules clean
	rm -rf app

























