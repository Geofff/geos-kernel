//
// Created by geoff on 9/07/17.
//

#include "gui.h"
#include <inttypes.h>
#include "graphics.h"
#include "../system.h"


int numItems;
struct menu_item menu[32];
int index = 0;

void gui_handler(struct regs *r) {
	uint8_t scancode = inb(0x60);

	if (scancode & 0x80) {
		// Key release
	} else {
		// Key press
		switch (scancode) {
			case 0x4B:
				// Left
				break;
			case 0x4D:
				// Right
				break;
			case 0x48:
				// Up
				if (index > 0) {
					index--;
					render_menu();
				} else {
					// Sound noise
				}
				break;
			case 0x50:
				// Down
				if (index < numItems - 1) {
					index++;
					render_menu();
				} else {
					// sound noise
				}
				break;

			case 0x1C:
				// Enter
				break;
		}
	}
}

void init_gui() {
	irq_uninstall_handler(1);
	irq_install_handler(1, &gui_handler);
	numItems = 0;
	clear_graphics();
}

void add_item(struct menu_item item) {
	if (numItems < 31) {
		menu[numItems++] = item;
	}
	render_menu();
}

void render_menu() {
	clear_graphics();
	for (int i = 0; i < numItems; i++) {
		if (i == index) {
			putStringColoured(menu[i].entry, 1, i, COLOUR_LIGHT_BROWN);
		} else {
			putString(menu[i].entry, 1, i);
		}
	}
	putCharColoured('>', 0, index, COLOUR_LIGHT_BROWN);
}


