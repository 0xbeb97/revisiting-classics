# aleph1's paper on buffer overflows

The classic paper by aleph1 contains sample code for linux systems
on using buffer overflows to get a shell. Technology has since 
moved on, and the examples do not necessarily provide the intended
results on modern-day linux boxes.

This repository includes fixed examples and brief discussion as to 
the reasons for the required changes.

## System requirements

These samples have been developed and run on 4.4.0-38-generic #57-Ubuntu SMP system (Ubuntu Xenial release). Since this is a much more modern version of the operating than was available during the aleph1's paper publication time, features to mitigate against buffer overflow attacks have been implemented. These include non-executable stack, and address space layout randomization (ASLR).

The following commands can be used to modify the compiled binary stack eXecute bit and ASLR:
```
$ execstack -q shellcode     # ~~> check whether stack is executable?
- shellcode  
$ execstack -c shellcode     # ~~> the '-' indicated stack is not executable, so change this
X shellcode

```
The ASLR can also be annoying, in particular when getting up to speed. This can be disabled conveniently with the following command which will open a new shell with ASLR disabled:
```
$ cat /proc/sys/kernel/randomize_va_space     # check if ASLR is enabled?
2
$ setarch `uname -m` -R /bin/bash             # 2 == full randomization; launch new shell with no ASLR
```
Alternativey you can just run the program (without shell) with disabled ASLR:
```
$ setarch `uname -m` -R shellcode
```
### Note on using gdb
If you're running your executables within gdb, you will see that stack addresses will remain constant between runs. This is because gdb ensures a consistent evironment to aid debugging. This may throw you off, but making you think that since the pointers you see are constant no ASLR is in use. Wrong!

## Examples
