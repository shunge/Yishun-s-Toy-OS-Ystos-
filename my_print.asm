;
; A boot sector that prints a string using function
;
[org 0x7c00]    ; Tell the assembler where this code will be loaded

    mov si, HELLO_MSG
    call print_string

    mov si, GOODBYE_MSG
    call print_string

    jmp $       ; Hang

%include "print_string.asm"

; Data
HELLO_MSG:
    db 'HI!Hello, World!', 0;

GOODBYE_MSG:
    db 'Hey,Goodbye!', 0

; Padding
    times 510-($-$$) db 0
    dw 0xaa55
