
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -m32")
add_library(c memset.c kb.c kb.h interface.c interface.h time.c time.h)