cmake_minimum_required(VERSION 3.5)
project(geos)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -m32 -nostdlib")
enable_language(ASM_NASM)
set(CMAKE_ASM_NASM_OBJECT_FORMAT "elf32")
set(CAN_USE_ASSEMBLER TRUE)
SET(CMAKE_LINKER "/usr/bin/ld")
SET(CMAKE_C_LINK_FLAGS "-m elf_i386 -T ${PROJECT_SOURCE_DIR}/link.ld")
SET(CMAKE_C_LINK_EXECUTABLE "${CMAKE_LINKER} ${CMAKE_C_LINK_FLAGS} <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
set(CMAKE_ASM_NASM_LINK_EXECUTABLE "/usr/bin/ld <FLAGS> <CMAKE_ASM_NASM_LINK_FLAGS> <LINK_FLAGS> <OBJECTS>  -o <TARGET> <LINK_LIBRARIES>")
set(CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> <FLAGS> -f ${CMAKE_ASM_NASM_OBJECT_FORMAT} -o <OBJECT> <SOURCE>")
SET(LINK)
set(SOURCE_FILES
    common/common.h
    graphics/graphics.c
    graphics/graphics.h
    iso/boot/grub/menu.lst
    iso/boot/grub/stage2_eltorito
    idt.c
    kernel.asm
        isr.asm
        irq.asm
    kernel.c
    link.ld
    Makefile
    menu.lst
    README.md
        stage2_eltorito gdt.c system.h isr.c irq.c graphics/gui.c graphics/gui.h)
include_directories("${PROJECT_SOURCE_DIR}/libc")
add_subdirectory(libc)
add_executable(geos ${SOURCE_FILES})
target_link_libraries(geos c)
ADD_CUSTOM_COMMAND(TARGET geos POST_BUILD COMMAND cp ${PROJECT_BINARY_DIR}/geos ${PROJECT_SOURCE_DIR}/iso/boot/kernel.elf COMMAND genisoimage -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -A os -input-charset utf8 -quiet -boot-info-table -o ${PROJECT_SOURCE_DIR}/os.iso ${PROJECT_SOURCE_DIR}/iso )
