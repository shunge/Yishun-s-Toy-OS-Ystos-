; load dh SECTORS TO ES:BX from drive DL
disk_load:
    
        push dx     ; Store DX on stack so later we can recall
                    ; how many sectors were request to be read,
                    ; even if it is altered in the meantime

        mov ah, 0x02; BIOS read sector function
        mov al, dh  ; Read DH sectros
        mov ch, 0x00; Select cylinder 0
        mov dh, 0x00; Select head 
        mov cl, 0x02; Start reading from second sector
                    ; (i.e. sfter the boot sector)

        int 0x13    ; BIOS interrupt

        jc disk_error; Jump if error(i.e. carry flag set)

        pop dx      ; Restore DX from the stack
        cmp dh, al  ; if AL(sectors read) is not equal to DH (sectors expected)
        jne disk_error; Display error message

        mov si, DISK_LOADED ; We pass the error.
        call print_string

        ret

disk_error:
    
    mov si, DISK_ERROR_MSG
    call print_string
    jmp $

; Variables
DISK_ERROR_MSG      db "Disk read error!", 0
DISK_LOADED         db "Disk load passed!", 0

