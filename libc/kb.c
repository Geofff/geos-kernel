//
// Created by geoff on 9/07/17.
//

#include "kb.h"
#include "../graphics/graphics.h"

void kb_handler(struct regs *r) {
	uint8_t scancode = inb(0x60);

	if (scancode & 0x80) {
		// Key release
	} else {
		// Key press
		putChar(kb_map[scancode], 0, 7);
		putHex8(scancode, 0, 8);
	}
}

void kb_install() {
	irq_install_handler(1, &kb_handler);
}