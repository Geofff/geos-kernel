//
// Created by geoff on 9/07/17.
//

#include <inttypes.h>

struct gdt_entry {
	uint16_t limit_lo;
	uint16_t base_lo;
	uint8_t base_mid;
	uint8_t access;
	uint8_t limit_flags;
	uint8_t base_hi;
} __attribute__ ((packed));

struct gdt_ptr {
	uint16_t limit;
	uint32_t base;
} __attribute__((packed));

struct gdt_entry gdt[3];
struct gdt_ptr _gp;

extern void _gdt_flush();

void gdt_set_gate(int num, uint32_t base, uint32_t limit, uint8_t access, uint8_t flags) {
	gdt[num].base_lo = base & 0xFFFF;
	gdt[num].base_mid = (base >> 16) & 0xFF;
	gdt[num].base_hi = (base >> 24) & 0xFF;

	gdt[num].access = access;
	gdt[num].limit_lo = limit & 0xFFFF;
	gdt[num].limit_flags = (limit >> 16) & 0x0F;
	gdt[num].limit_flags |= (flags & 0xF0);
}

void gdt_install() {
	_gp.limit = (sizeof(struct gdt_entry) * 3) - 1;
	_gp.base = &gdt;

	// Null Descriptor
	gdt_set_gate(0, 0, 0, 0, 0);

	// Code segment
	gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
	// Data segment
	gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

	_gdt_flush();
}