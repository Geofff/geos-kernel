//
// Created by geoff on 9/07/17.
//

#ifndef GEOS_KB_H
#define GEOS_KB_H

#include <inttypes.h>
#include "../system.h"

uint8_t kb_map[128] = {
		0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'0', '-', '=', '\b', '\t', 'q', 'w', 'e', 'r', 't'
};

void kb_handler(struct regs *r);

#endif //GEOS_KB_H
