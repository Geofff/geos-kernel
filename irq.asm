global _irq0
global _irq1

_irq0:
    cli
    push byte 0
    push byte 32
    jmp irq_common_stub
_irq1:
    cli
     push byte 0
    push byte 33
    jmp irq_common_stub

extern _irq_handler
irq_common_stub:
    pusha
    push ds
    push es
    push fs
    push gs
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov eax, esp
    push eax
    mov eax, _irq_handler
    call eax
    pop eax
    pop gs
    pop fs
    pop es
    pop ds
    popa
    add esp, 8
    iret