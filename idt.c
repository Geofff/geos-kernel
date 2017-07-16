#include <inttypes.h>
#include "libc/stdc.h"

struct idt_entry {
	uint16_t offset_lo;
	uint16_t select;
	uint8_t zero;
	uint8_t type;
	uint16_t offset_hi;
} __attribute__((packed));

struct idt_ptr {
	uint16_t limit;
	uint32_t base;
} __attribute__((packed));

struct idt_entry idt[256];
struct idt_ptr _idtp;

extern void _idt_load();

void idt_set_gate(uint8_t num, uint32_t base, uint16_t select, uint8_t type) {
	struct idt_entry entry = idt[num];
	entry.offset_lo = base & 0xFFFF;
	entry.offset_hi = (base >> 16) & 0xFFFF;
	entry.select = select;
	entry.type = type;
	entry.zero = 0;
	idt[num] = entry;
}

void idt_install(){
	_idtp.limit = (sizeof(struct idt_entry) * 256) - 1;
	_idtp.base = &idt;
	memset(&idt,0, sizeof(struct idt_entry) * 256);

	_idt_load();
}
