#include <inttypes.h>

void kmain(void){
    const char *str = "geos kernel";
    uint8_t *vidPtr = (uint8_t*) 0xb8000; // Start of video memory
    uint16_t i = 0;
    uint16_t j = 0;
    while(j < 8*25*2){
        vidPtr[j] = ' ';
        vidPtr[j+1] = 0x07;
        j += 2;
    }
    j = 0;
    while (str[j] != '\0'){
        vidPtr[i] = str[j];
        vidPtr[i+1] = 0x07;
        j++;
        i += 2;
    }
    return;
}