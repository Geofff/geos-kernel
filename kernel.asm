bits 32
section .text
    align 4
    dd 0x1BADB002
    dd 0x00
    dd - (0x1BADB002 + 0x00)
global start
extern kmain

start:
    cli
    mov esp, stack_space
    push ebx
    call kmain
    hlt

global _gdt_flush
extern _gp
_gdt_flush:
    lgdt [_gp]
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:flush2
flush2:
    ret

global _idt_load
extern _idtp
_idt_load:
    lidt [_idtp]
    ret

section .bss
resb 8192
stack_space:
