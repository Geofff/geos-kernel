#include <inttypes.h>
#define GRAPHICS_LOC 0xb8000

enum colour_t {
	COLOUR_BLACK = 0,
	COLOUR_BLUE = 1,
	COLOUR_GREEN = 2,
	COLOUR_CYAN = 3,
	COLOUR_RED = 4,
	COLOUR_MAGENTA = 5,
	COLOUR_BROWN = 6,
	COLOUR_LIGHT_GREY = 7,
	COLOUR_DARK_GREY = 8,
	COLOUR_LIGHT_BLUE = 9,
	COLOUR_LIGHT_GREEN = 10,
	COLOUR_LIGHT_CYAN = 11,
	COLOUR_LIGHT_RED = 12,
	COLOUR_LIGHT_MAGENTA = 13,
	COLOUR_LIGHT_BROWN = 14,
	COLOUR_WHITE = 15,
};
typedef enum colour_t colour_t;
void init_graphics();
void putString(char*,uint16_t,uint16_t);

void putStringColoured(char *, uint16_t, uint16_t, colour_t);

void putChar(char c, uint16_t x, uint16_t y);

void putCharColoured(char c, uint16_t x, uint16_t y, colour_t);

void clear_graphics();

void putHex8(uint8_t i, uint16_t x, uint16_t y);

void putHex16(uint16_t i, uint16_t x, uint16_t y);

void putHex32(uint32_t i, uint16_t x, uint16_t y);
void putInt8(uint8_t i, uint16_t x, uint16_t y);