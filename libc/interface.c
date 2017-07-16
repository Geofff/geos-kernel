//
// Created by geoff on 16/07/17.
//

#include "interface.h"
#include "../system.h"

uint8_t getCMOSRegister(uint8_t port) {
	// Disable interrupts temporarily
	outb("cli", 0x0);

	// Set port to read
	outb(0x70, port);
	// Read in value
	uint8_t in = inb(0x71);
	// Renable interrupts
	outb("sti", 0x0);
	return in;
}