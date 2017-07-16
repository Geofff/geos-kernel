#include <inttypes.h>
#include "graphics/graphics.h"
#include "system.h"
#include "graphics/gui.h"
#include "common/multiboot.h"
#include "libc/time.h"

typedef struct multiboot_memory_map {
    uint32_t size;
    uint32_t base_addr_low, base_addr_high;
    uint32_t len_low, len_high;
    uint32_t type;
} multiboot_memory_map_t;

void kmain(struct multiboot_info *mbt, unsigned int magic) {
    gdt_install();
    idt_install();
    isr_install();
    irq_install();
    kb_install();
    __asm__ volatile("sti");
    const char *str = "geos kernel";
    init_graphics();

    //init_gui();
    struct menu_item root;
    root.entry = "root";
    add_item(root);
    root.entry = "2nd";
    add_item(root);
    root.entry = "3nd";
    add_item(root);
    root.entry = "4rd";
    add_item(root);
    uint8_t *vidPtr = (uint8_t*) 0xb8000; // Start of video memory
    putString("geos kernel", 0, 11);
    putStringColoured("geos kernel", 0, 12, COLOUR_CYAN);

    // Display all interface items
    int i = 0;
    multiboot_memory_map_t *mmap = mbt->mmap_addr;
    while (mmap < mbt->mmap_addr + mbt->mmap_length) {
        putString("Length: ", 0, i);
        putHex32(mmap->len_high, 8, i);
        putHex32(mmap->len_low, 16, i++);
        mmap = (multiboot_memory_map_t *) ((uint32_t) mmap + mmap->size + sizeof(mmap->size));
    }
    rtc_time_t time = getRTCTime();
    //putInt8(time., 0, i++);
    putString("Time: ", 0, i);
    putInt8(time.hours, 6, i);
    putChar(':', 9, i);
    putInt8(time.minutes, 10, i);
    putChar(':', 13, i);
    putInt8(time.seconds, 14, i++);
    putString(DAY_STRINGS[time.weekday], 0, i++);
    for (; ;);
    return;
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
}
