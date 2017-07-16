#include "graphics.h"

uint8_t *vidPtr;
char hexString[17] = "0123456789ABCDEF";
void init_graphics(){

    // Start by clearing out all graphics
    vidPtr = (uint8_t*) GRAPHICS_LOC; // Start of video memory

}

void clear_graphics() {
    for(int i = 0; i < 80*25; i++){
        vidPtr[i*2] = 0x00;
        vidPtr[i*2+1] = 0x07;
    }
}

void putChar(char c, uint16_t x, uint16_t y){
    if (x > 79){
        x -= 80;
        y++;
    }
    switch(c){
        case '\n':
            y++;
            x = 0;
            break;
        case '\r':
            x = 0;
            break;
        default:
            vidPtr[x*2+y*2*80] = c;
            vidPtr[x*2+y*2*80+1] = 0x07;
            break;
    }
}

void putCharColoured(char c, uint16_t x, uint16_t y, colour_t colour) {
    if (x > 79) {
        x -= 80;
        y++;
    }
    switch (c) {
        case '\n':
            y++;
            x = 0;
            break;
        case '\r':
            x = 0;
            break;
        default:
            vidPtr[x * 2 + y * 2 * 80] = c;
            vidPtr[x * 2 + y * 2 * 80 + 1] = colour;
            break;
    }
}

void putString(char* str, uint16_t x, uint16_t y){
    putStringColoured(str, x, y, COLOUR_LIGHT_GREY);

}


void putStringColoured(char *str, uint16_t x, uint16_t y, colour_t colour) {
    while (*str != '\0'){
        putCharColoured(*str++, x, y, colour);
        if (x == 79){
            x = 0;
            y++;
        } else {
            x++;
        }
    }
}


void scrollWindow(){
    for(int i = 0; i < 80*24*2; i++){
        vidPtr[i] = vidPtr[i+80*2];
    }
}

void putInt8(uint8_t i, uint16_t x, uint16_t y){
    vidPtr[x*2+y*2*80] = '0'+(i/100);
    vidPtr[x*2+y*2*80+1] = 0x07;
    vidPtr[x*2+y*2*80+2] = '0'+(i%100)/10;
    vidPtr[x*2+y*2*80+3] = 0x07;
    vidPtr[x*2+y*2*80+4] = '0'+i%10;
    vidPtr[x*2+y*2*80+5] = 0x07;
}


void putHex8(uint8_t i, uint16_t x, uint16_t y){
    putChar(hexString[i >> 4], x, y);
    putChar(hexString[i & 0xF], x + 1, y);
}

void putHex16(uint16_t i, uint16_t x, uint16_t y) {
    putHex8(i & 0xFF, x, y);
    putHex8(i >> 8, x + 2, y);
}

void putHex32(uint32_t i, uint16_t x, uint16_t y) {
    putHex16(i & 0xFFFF, x, y);
    putHex16(i >> 16, x + 4, y);
}