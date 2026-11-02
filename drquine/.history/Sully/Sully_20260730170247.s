default rel

extern fopen
extern fclose
extern fprintf
extern sprintf
extern system

global main

section .data

x       dq 9

mode    db "w",0
fname   db "Sully_%d.s",0
cmd1fmt db "nasm -felf64 Sully_%d.s -o Sully_%d.o",0
cmd2fmt db "ld Sully_%d.o -o Sully_%d",0
cmd3fmt db "./Sully_%d",0

SOURCE db "default rel%1$c%1$cextern fopen%1$cextern fclose%1$cextern fprintf%1$cextern sprintf%1$cextern system%1$c%1$cglobal main%1$c%1$csection .data%1$c%1$cx        dq 50%1$c%1$cmode    db %2$cw%2$c,0%1$cfname    db %2$cSully_%%d.s%2$c,0%1$ccmd1fmt db %2$cnasm -felf64 Sully_%%d.s -o Sully_%d.o%2$c,0%1$ccmd2fmt db %2$cld Sully_%d.o -o Sully_%d%2$c,0%1$ccmd3fmt  db %2$c./Sully_%d%2$c,0%1$c%1$cSOURCE db %2$c%3$s%2$c%1$c%1$csection .bss%1$c%1$cfile    resb 64%1$ccmd1    resb 128%1$ccmd2    resb 128%1$ccmd3    resb 64%1$cfp      resq 1%1$c%1$csection .text%1$cmain:%1$cmov rcx, %3$c%1$c"

section .bss

file    resb 64
cmd1    resb 128
cmd2    resb 128
cmd3    resb 64
fp      resq 1

section .text
main:
sub x
mov rsi, SOURCE
mov rdi, fname
call fprintf 
