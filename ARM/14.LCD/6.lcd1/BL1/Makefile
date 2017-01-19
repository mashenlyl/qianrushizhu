bootload1.bin: start.o sdram_init.o sd_relocate.o
	arm-linux-ld -Tlink.lds -o bootload1.elf $^
	arm-linux-objcopy -O binary bootload1.elf bootload1.bin
	arm-linux-objdump -D bootload1.elf > bootload1_elf.dis
	gcc mkv210_image.c -o mkx210
	./mkx210 bootload1.bin BL1.bin
	
%.o : %.S
	arm-linux-gcc -o $@ $< -c -nostdlib

%.o : %.c
	arm-linux-gcc -o $@ $< -c -nostdlib

clean:
	rm *.o *.elf *.bin *.dis mkx210 -f

	
	