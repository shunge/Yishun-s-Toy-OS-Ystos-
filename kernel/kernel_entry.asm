[bits 32]
[extern main]

call main   ; invoke main() in our C kernel
jmp $       ; Hang forever when we return from the kernel

