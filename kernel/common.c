#include "common.h"

// port writing 1 byte
inline void outb(uint16_t port, uint8_t value)
{
    asm volatile ("outb %1, %0" : : "dN"(port), "a" (value));
}

// port reading 1 byte
inline uint8_t inb(uint16_t port)
{
    uint8_t ret;

    asm volatile("inb %1, %0 ": "=a"(ret): "dN" (port));

    return ret;
}

// port reading 1 word
inline uint16_t inw(uint16_t port)
{
    uint16_t ret;

    asm volatile ("inw %1, %0":"=a" (ret): "dN" (port));

    return ret;

}
