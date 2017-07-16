//
// Created by geoff on 9/07/17.
//

#ifndef GEOS_GUI_H
#define GEOS_GUI_H

#include <inttypes.h>

struct menu_item {
	char *entry;
	uint8_t colour;
};

void init_gui(void);

void render_menu(void);

void add_item(struct menu_item item);

#endif //GEOS_GUI_H
