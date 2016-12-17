[bits 32]
; Define some constants

VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f

; pirnts a null-terminated string pointed to by EDX
print_string_pm:
    pusha
    mov edx, VIDEO_MEMORY ; Set edx to the start of vid mem.

print_string_pm_loop:
    mov al, [ebx]         ; Store the char at EBX in AL
    mov ah, WHITE_ON_BLACK; Store the attributes in AH

    cmp al, 0             ; if al is 0 means is at the end, so done
    je print_string_pm_done

    mov [edx], ax         ; Store char and attributes at current

    add ebx, 1            ; Increment EBX tp the next char in string
    add ebx, 2            ; Move to next character cell in vide mem

    jmp print_string_pm_loop ; loop around to print the next char.

print_string_pm_done :
    popa
    ret                   ; Return from the function
