os.iso: iso/boot/kernel.elf
	genisoimage -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -A os -input-charset utf8 -quiet -boot-info-table -o os.iso iso

iso/boot/kernel.elf: kc.o kasm.o link.ld graphics/graphics.o idt.o libc/memset.o
	ld -m elf_i386 -T link.ld -o iso/boot/kernel.elf kasm.o kc.o graphics/graphics.o idt.o libc/memset.o
kasm.o: kernel.asm
	nasm -f elf32 kernel.asm -o kasm.o
kc.o: kernel.c
	gcc -std=c99 -m32 -c kernel.c -o kc.o
graphics/graphics.o: graphics/graphics.c
	gcc -std=c99 -m32 -c graphics/graphics.c -o graphics/graphics.o
idt.o: idt.c
	gcc -std=c99 -m32 -c idt.c -o idt.o
libc/memset.o: libc/memset.c
	gcc -std=c99 -m32 -c libc/memset.c -o libc/memset.o
run: os.iso
	qemu-system-i386 -cdrom os.iso
