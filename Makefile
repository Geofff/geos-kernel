os.iso: iso/boot/kernel.elf
	genisoimage -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -A os -input-charset utf8 -quiet -boot-info-table -o os.iso iso

iso/boot/kernel.elf: kc.o kasm.o link.ld
	ld -m elf_i386 -T link.ld -o iso/boot/kernel.elf kasm.o kc.o
kasm.o: kernel.asm
	nasm -f elf32 kernel.asm -o kasm.o
kc.o: kernel.c
	gcc -m32 -c kernel.c -o kc.o

