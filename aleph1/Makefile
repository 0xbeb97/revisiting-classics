all: overflow1 shellcode_exec

overflow1: overflow1.c
	gcc -m32 -fno-stack-protector -Wl,-z,norelro $< -o $@
	execstack -s $@

shellcode_exec: shellcode_exec.c 
	gcc -m32 -fno-stack-protector -Wl,-z,norelro $< -o $@
	execstack -s $@

execve_do2.o: execve_do2.s
	nasm -f elf $<

.PHONY: clean
clean:
	rm -f *.o overflow1 shellcode_exec
