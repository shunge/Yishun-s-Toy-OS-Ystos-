#include "string.h"

inline void memcpy(uint8_t *dest, const uint8_t *src, uint32_t len)
{
    for (; len != 0; len--){
        *dest++ = *src++;
    }
}

inline void memset(void *dest, uint8_t val, uint32_t len)
{
    uint8_t *dst = (uint8_t *)dest;

    for ( ; len != 0; len--){
        *dst++ = val;
    }

}

inline void bzero(void *dest, uint32_t len)
{
    memset(dest, 0, len);
}

inline int strcmp(const char *str1, const char *str2)
{
    while (*str1 && *str2 && (*str1++ == *str2++)) 
        ;

    if (*str1 == '\0' && *str2 == '\0') return 0;

    if (*str1 > *str2) return 1;

    else return 0;
}

inline char *strcpy(char *dest, const char *src)
{
    char *tmp = dest;

    while (*src) {
        *tmp++ = *src++;
    }

    *tmp = '\0';

    return dest;
}

inline char *strcat(char *dest, const char *src){
    
    char *tmp = dest;

    while (*tmp) {
        tmp++;
    }

    while (*src) {
        *tmp++ = *src++;
    }

    return dest;
}

inline int strlen(const char *src)
{
    const char *end = src;

    while (*end++)
        ;

    return (end - src - 1);
}
