; comment 1

extern printf
global main

section .data
    theprogram db "; comment 1",10,10
        db "extern printf",10
        db "global main",10,10
        db "section .data",10
        db "    theprogram db 34, %s, 34",10,10
        db "section .text",10
        db "main:",10
        db "    call print_source",10
        db "    ret",10,10
        db "print_source:",10
        db "    ; comment 2",10
        db "    mov rdi, theprogram",10
        db "    mov rsi, theprogram",10
        db "    xor eax, eax",10
        db "    call printf",10
        db "    ret",10,0

section .text

main:
    call print_source
    ret

print_source:
    ; comment 2
    mov rdi, theprogram
    mov rsi, theprogram
    xor eax, eax
    call printf
    ret