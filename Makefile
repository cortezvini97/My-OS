ASSEMBLER = nasm
ASFLAGS = -f elf32
LINKER = ld
LDFLAGS = -m elf_i386 -T src/link.ld

OBJS = build/boot.o build/kernel.o
OUTPUT = lyricos/boot/kernel.bin

all:$(OBJS)
	mkdir lyricos/ -p
	mkdir lyricos/boot/ -p
	${LINKER} ${LDFLAGS} -o ${OUTPUT} $(OBJS)

build/boot.o:src/boot/boot.asm
	mkdir -p build
	$(ASSEMBLER) $(ASFLAGS) -o build/boot.o src/boot/boot.asm

build/kernel.o:src/kernel/arch/x86/kernel.asm
	mkdir -p build
	$(ASSEMBLER) $(ASFLAGS) -o build/kernel.o src/kernel/arch/x86/kernel.asm

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