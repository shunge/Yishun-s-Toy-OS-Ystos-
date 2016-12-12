	BITS 16
start:

	mov ax, 07C0h	; Set up 4k stack
    add ax, 288     ; (4096 + 512) / 16 bytes per paragraph
    mov ss, ax
    mov sp, 4096

    mov ax, 07C0h   ; Set data segment to where we're loaded
    mov ds, ax

    mov si, test_string     ; Put string position into SI
    call print_string       ; call the print_string routine

    jmp $           ; infinite loop here

    test_string db 'Do you think I am easier to be played on than a pipe?', 0

print_string:       ; Routine: output string in SI to screen
    mov ah, 0Eh     ; int 10 h 'print char' function

.repeat:
    lodsb           ; Get character from string
    cmp al, 0  
    je .done        ; If char is zero, end of string
    int 10h
    jmp .repeat

.done:
    ret

    times 510-($-$$) db 0; Pad the boot sector with 0s
    dw 0xAA55   ; Standard PC boot signature


