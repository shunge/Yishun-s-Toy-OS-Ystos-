#include "console.h"
#include "debug.h"

int main(){
    console_clear();

    console_write_color("Hello!And welcome to YstOS!\n", rc_black, rc_green);

    //panic("Testing");
    return 0;
}
