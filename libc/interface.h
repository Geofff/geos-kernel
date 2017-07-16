//
// Created by geoff on 16/07/17.
//

#ifndef GEOS_INTERFACE_H
#define GEOS_INTERFACE_H

#include <inttypes.h>

struct interface_t {
	char *name;
	uint8_t enabled;
};
typedef struct interface_t interface_t;


uint8_t getCMOSRegister(uint8_t port);

#endif //GEOS_INTERFACE_H
