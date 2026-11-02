; comment 1
extern printf
global main

section .data

fmt db "%s% c%s% c%s", 0

prefix:
    db "; comment 1",10
    db "extern printf",10
    db "global main",10,10
    db "section .data",10
    db "fmt db 34, 37, 115, 37, 32, 99, 37, 115, 37, 32, 99, 37, 115, 34, 10, 0",10
    db 10
    db "prefix:",10
    db "    db 59,32,99,111,109,109,101,110,116,32,49,10",10
    db 0

middle db "; PROGRAM HERE",10,0

suffix:
    db 10
    db "section .text",10
    db "main:",10
    db "    call print_source",10
    db "    ret",10
    db 10
    db "print_source:",10
    db "    mov rdi, fmt",10
    db "    mov rsi, prefix",10
    db "    mov rdx, 10",10
    db "    mov rcx, middle",10
    db "    mov r8, 10",10
    db "    mov r9, suffix",10
    db "    xor eax, eax",10
    db "    call printf",10
    db "    ret",10,0

section .text

main:
    call print_source
    ret

print_source:
    mov rdi, fmt
    mov rsi, prefix
    mov rdx, 10
    mov rcx, middle
    mov r8, 10
    mov r9, suffix
    xor eax, eax
    call printf
    ret