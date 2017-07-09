#include <inttypes.h>
#define GRAPHICS_LOC 0xb8000



void init_graphics();
void putString(char*,uint16_t,uint16_t);

void putHex8(uint8_t i, uint16_t x, uint16_t y);
void putInt8(uint8_t i, uint16_t x, uint16_t y);