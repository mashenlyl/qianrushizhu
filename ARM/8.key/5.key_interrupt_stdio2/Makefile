CC	= arm-linux-gcc
LD	= arm-linux-ld
OBJCOPY		= arm-linux-objcopy
OBJDUMP		= arm-linux-objdump
AR		= arm-linux-ar

# 这里拿的是它的全路径
INCDIR	:= $(shell pwd)
#这个是C中的预处理器，flag是它的可选择的选项
CPPFLAGS	:= -nostdlib -nostdinc -I$(INCDIR)/include
#这个是C中的编译器
CFLAGS		:= -Wall -O2 -fno-builtin
#把它们搞成全局变量，供其他的子文件夹的使用
export	CC LD OBJCOPY OBJDUMP AR CPPFLAGS CFLAGS

#这里在下面会直接展开，下面就不用写那么长了，而且想改就改
objs	:= start.o led.o clock.o uart.o main.o inter.o
#这里就把主的makefile和子文件夹的makefile连接在一起
objs	+= lib/libc.a


uart.bin: $(objs)
	$(LD) -Tlink.lds -o uart.elf $^
	$(OBJCOPY) -O binary uart.elf uart.bin
	$(OBJDUMP) -D uart.elf > uart_elf.dis
	gcc mkv210_image.c -o mkx210
	./mkx210 uart.bin 210.bin
	
lib/libc.a:
	cd lib; make; cd ..
	
%.o : %.S
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $< -c

%.o : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $< -c

clean:
	rm *.o *.elf *.bin *.dis mkx210 -f
	cd lib; make clean; cd ..
	
	