#include "console.h"
#include "string.h"
#include "vargs.h"
#include "debug.h"

#include "types.h"

void vsprintf(char *buff, const char *format, va_list args);

void printk(const char *format, ...)
{
	char buff[256];
	va_list args;
	/*int i;

	va_start(args, format);
	i = vsprintf(buff, format, args);
	va_end(args);

	buff[i] = '\0';*/
    bzero(buff, sizeof(buff));
    va_start(args, format);
    vsprintf(buff, format, args);
    va_end(args);

	console_write(buff);
    //memset(buff, 0, sizeof(buff));
}

/*void printk_color(real_color_t back, real_color_t fore, const char *format, ...)
{
	static char buff[1024];
	va_list args;
	int i;

	va_start(args, format);
	i = vsprintf(buff, format, args);
	va_end(args);

	buff[i] = '\0';

	console_write_color(buff, back, fore);
}*/


char* itoa(int value, char *str, int radix){
    char reverse[36];   
    char *p = reverse;
    int sign = (value >= 0)? 1:0;

    value = (value >= 0)?value:-value;
    *p++ = '\0';
    while (value >= 0){
        *p++ = "0123456789abcdef"[value%radix];
        value /= radix;
        if (value == 0) break;
    }

    if (!sign) {
        *p = '-';
    }
    else {
        p--;
    }

    while (p >= reverse){
        *str++ = *p--;
    }

    return str;
}

char* uitoa(uint32_t value, char *str, int radix){
    char reverse[36];   
    char *p = reverse;

    *p++ = '\0';
    while (value != 0){
        *p++ = "0123456789abcdef"[value%radix];
        value /= radix;
        if (value == 0) break;
    }
    p--;

    while (p >= reverse){
        *str++ = *p--;
    }

    return str;
}

/* NOT WORK TODO */
char* gcvt(double value, int ndigit, char *buf){
    char tmpbuf[72];
    int int_part = (int)value;

    double folat_part = value - int_part;

    if (folat_part < 0) folat_part = -folat_part;
    itoa(int_part, tmpbuf, 10);

    char *p = tmpbuf;

     while (*p != '\0') p++;

    *p++ = '.';

    while (ndigit > 0 && folat_part > 0.00000001){
        *p++ = (int)(folat_part*10) + '0';
        folat_part = (folat_part * 10) - (int)(folat_part * 10);
        ndigit--;
    }

    *p = '\0';
    strcpy(buf, tmpbuf);
    return buf;
}

void vsprintf(char *buf, const char *fmt, va_list args){
    char *p;
    va_list p_next_arg = args;

    for (p = buf; *fmt; fmt++){
        if (*fmt != '%'){
            *p++ = *fmt;
            continue;
        }
        fmt++;  // *fmt = '%'
        switch (*fmt){
            case 'd':
                itoa(va_arg(p_next_arg, int),p,10);
                p += strlen(p);
                break;
            case 'x':
                uitoa(va_arg(p_next_arg, unsigned int),p,16);
                p += strlen(p);
                break;
            case 'c':
                *p++ = va_arg(p_next_arg, char);
                break;
            case 's':
                *p = '\0';
                strcat(p, va_arg(p_next_arg, char *));
                p += strlen(p);
                break;

            default:
                break;
        }
    }
    *p = '\0';

    //return (p - buf);
}
