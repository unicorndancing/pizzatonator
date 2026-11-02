default rel

extern fopen
extern fclose
extern fprintf
extern sprintf
extern system

global main

section .data

x       dq 50

mode    db "w",0
fname   db "Sully_%d.s",0
cmd1fmt db "nasm -felf64 Sully_%d.s -o Sully_%d.o",0
cmd2fmt db "ld Sully_%d.o -o Sully_%d",0
cmd3fmt db "./Sully_%d",0

SOURCE db "... very long format string ...",0

section .bss

file    resb 64
cmd1    resb 128
cmd2    resb 128
cmd3    resb 64
fp      resq 1