; A boot sector that boots a C kernel in 32-bit protected mode
[org 0x7c00]            ; Where to load the code
KERNEL_OFFSET equ 0x1000; This is the memory offset to which we will load out kernel

    mov [BOOT_DRIVE], dl ; BIOS stores out boot drive in DL
                         ; it is best to remember this for later
    mov bp, 0x9000       ; Set-up the stack
    mov sp, bp

    mov si, MSG_REAL_MODE; A string that print we are starting

    call print_string

    call load_kernel     ; Load out kernel

    call switch_to_pm    ; Swtich to protected mode, from which
                         ; we will not return

    jmp $

; Included routines
%include "util/print_string.asm"
%include "util/disk_load.asm"
%include "util/gdt.asm"
%include "util/print_string_pm.asm"
%include "util/switch_to_pm.asm"

[bits 16]

; load_kernel

load_kernel:
    mov si, MSG_LOAD_KERNEL     ; Print a message to say we are loading kernel
    call print_string

    mov bx, KERNEL_OFFSET       ; Set up params for disk_loading
    mov dh, 15                  ; load up frist 15 sectors (excluding boot sector)
    mov dl, [BOOT_DRIVE]        ; from the boot disk (i.e. out kernel code)
    call disk_load              ; to address KERNEL_OFFSET

    ret

[bits 32]
; This is where we arrive after switching to 32 bits mode and intialising protected mode.

BEGIN_PM:

    mov ebx, MSG_PROT_MODE  ; Use out 32 bit print to print we are in protected mode
    call print_string_pm    ; Print the string out

    call KERNEL_OFFSET      ; Now junp to the address of our loaded kernel code
                            ; And let all the fun begins

    jmp $                   ; Hang

; Global variables

BOOT_DRIVE      db 0 
MSG_REAL_MODE   db "Started in 16-bit Real Mode!", 0
MSG_PROT_MODE   db "Successfully lnaded in 32-bit Protected Mode!", 0
MSG_LOAD_KERNEL db "Loading kernel into memory.", 0

; Bootsector padding
times 510-($-$$) db 0
dw 0xaa55
