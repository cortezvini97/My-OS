ASSEMBLER = nasm
ASFLAGS = -f elf32
LINKER = ld
LDFLAGS = -m elf_i386 -T src/link.ld

COMPILER = gcc
CFLAGS = -m32 -c -I src/kernel/drivers/inc -I src/kernel/arch/x86/inc -I src/libs/inc -I src/kernel/inc -ffreestanding

OBJS = build/boot.o build/kernel.o build/kmain.o build/video.o build/system.o build/stdio.o build/memory.o build/string.o build/keyboard.o build/shell.o build/time.o
OUTPUT = lyricos/boot/kernel.bin

all:$(OBJS)
	mkdir lyricos/ -p
	mkdir lyricos/boot/ -p
	${LINKER} ${LDFLAGS} -o ${OUTPUT} $(OBJS)

build/boot.o:src/boot/boot.asm
	mkdir -p build
	$(ASSEMBLER) $(ASFLAGS) -o build/boot.o src/boot/boot.asm

build/kernel.o:src/kernel/arch/x86/kernel.asm
	$(ASSEMBLER) $(ASFLAGS) -o build/kernel.o src/kernel/arch/x86/kernel.asm

build/kmain.o:src/kernel/arch/x86/kernel.c
	$(COMPILER) $(CFLAGS) src/kernel/arch/x86/kernel.c -o build/kmain.o

build/video.o:src/kernel/drivers/video.c
	$(COMPILER) $(CFLAGS) src/kernel/drivers/video.c -o build/video.o

build/system.o:src/libs/system.c
	$(COMPILER) $(CFLAGS) src/libs/system.c -o build/system.o

build/stdio.o:src/libs/stdio.c
	$(COMPILER) $(CFLAGS) src/libs/stdio.c -o build/stdio.o

build/string.o:src/libs/string.c
	$(COMPILER) $(CFLAGS) src/libs/string.c -o build/string.o

build/memory.o:src/libs/memory.c
	$(COMPILER) $(CFLAGS) src/libs/memory.c -o build/memory.o

build/keyboard.o:src/kernel/drivers/keyboard.c
	$(COMPILER) $(CFLAGS) src/kernel/drivers/keyboard.c -o build/keyboard.o

build/shell.o:src/kernel/shell.c
	$(COMPILER) $(CFLAGS) src/kernel/shell.c -o build/shell.o

build/time.o:src/libs/time.c
	$(COMPILER) $(CFLAGS) src/libs/time.c -o build/time.o

build:all
	rm build/ -r -f
	rm dist/ -r -f
	rm lyricos/boot/grub/ -r -f
	mkdir lyricos/boot/grub/
	echo "menuentry \"Lyric OS\" {" >> lyricos/boot/grub/grub.cfg
	echo "    multiboot /boot/kernel.bin" >> lyricos/boot/grub/grub.cfg
	echo "	boot" >> lyricos/boot/grub/grub.cfg
	echo "}" >> lyricos/boot/grub/grub.cfg
	mkdir -p dist
	grub-mkrescue -o dist/lyricos.iso lyricos/

clean:
	rm build/ -r -f
	rm dist/ -r -f
	rm lyricos/ -r -f
run:
	qemu-system-x86_64 -cdrom dist/lyricos.iso

runbuild:build
	qemu-system-x86_64 -cdrom dist/lyricos.iso