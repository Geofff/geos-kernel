//
// Created by geoff on 9/07/17.
//

#ifndef GEOS_SYSTEM_H
#define GEOS_SYSTEM_H

#include <inttypes.h>

struct regs {
	uint32_t gs, fs, es, ds;
	uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint32_t int_no, err_code;
	uint32_t eip, cs, eflags, useresp, ss;
};


void gdt_install();

void idt_set_gate(uint8_t num, uint32_t base, uint16_t select, uint8_t type);

void idt_install();

void isr_install();

void irq_install();

void irq_install_handler(int irq, void (*handler)(struct regs *r));

void irq_uninstall_handler(int irq);

void kb_install();

static inline void outb(uint16_t port, uint8_t val) {
	__asm__ volatile ( "outb %0, %1" : : "a"(val), "Nd"(port));
}

static inline uint8_t inb(uint16_t port) {
	uint8_t ret;
	__asm__ volatile ( "inb %1, %0" : "=a"(ret) : "Nd"(port));
	return ret;
}

#endif //GEOS_SYSTEM_H
