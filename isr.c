//
// Created by geoff on 9/07/17.
//

#include "system.h"
#include <inttypes.h>
#include "graphics/graphics.h"

extern void _isr0();

void isr_install() {
	idt_set_gate(0, (unsigned) _isr0, 0x08, 0x8E);
}

unsigned char *exception_messages[] = {"Division by Zero"};

void _fault_handler(struct regs *r) {
	if (r->int_no < 32) {
		putString(exception_messages[r->int_no], 0, 0);
		putString("System Fault", 0, 1);
		for (; ;);
	}
}