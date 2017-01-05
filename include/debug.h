#ifndef INCLUDE_DEBUG_H_
#define INCLUDE_DEBUG_H_

#include "console.h"
#include "vargs.h"

#define assert(x,info)  \
    do {                \
        if (!(x)){      \
            panic(info);\
        }               \
    } while (0)

void panic(const char* msg);
void print_cur_status();
//void print_stack_trace();

void printk(const char *format, ...);

void printk_color(real_color_t back, real_color_t fore, const char *format, ...);

// something for bochs too?
void bochs_putc(char c);

#define bochs_break()    \
    outw(0x8A00, 0x8A00);\
    outw(0x8A00, 0x08AE0);

#endif
