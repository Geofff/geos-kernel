#include <inttypes.h>
#include "graphics/graphics.h"
#include "common/common.h"


char getScanCode(){
    char c = 0;
    do {
        if (inb(0x60) != c){
            c = inb(0x60);
            if (c>0){
                return c;
            }
        }
    } while (1);
}

void kmain(void){
    const char *str = "geos kernel";
    init_graphics();
    uint8_t *vidPtr = (uint8_t*) 0xb8000; // Start of video memory
    putString("geos kernel", 0, 0);
    putString("multilining", 0, 1);
    putString("offsetting", 1, 2);
    putString("and on and on and on and on and on and on and on and on and on and on and on and on and on and on and on and on and on and on and on and on and on and on ", 1, 2);
    char c = 0;
    if (c == 0x10){
        putString("Q pressed", 0,4);
    } else {
        putString("!Q pressed", 0,4);
    }
    putHex8(0xDE,0,5);
    putHex8(0xAD,4,5);
    putInt8(c, 0,6);
	//int a = 3/0;
    putString("Testing\nNewlines", 0, 8);
    return;
}
