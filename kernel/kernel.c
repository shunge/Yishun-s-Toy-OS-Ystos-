#include "console.h"

int main(){
    console_clear();

    console_write_color("Hello!And welcome to YstOS!\n", rc_black, rc_green);
    return 0;
}
