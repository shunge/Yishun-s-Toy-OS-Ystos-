print_string:
    mov ah, 0Eh

.repeat:
    lodsb
    cmp al, 0
    je .done
    int 10h
    jmp .repeat

.done:
    ret
    
    
    
    
    
    
    ;pusha        Push all register values to the stack
    ;mov bx, 10
    ;add bx, 20
    ;mov ah, 0x0e
    ;int 0x10
    ;popa
    ;ret
