; comment 1

extern printf
global main

section .data
    theprogram db "; comment 1",10,10, "extern printf",10, "global main",10,10, "section .data",10, "    theprogram db 34, %s, 34",10,10, "section .text",10, "main:",10, "    call print_source",10, "    ret",10,10, "print_source:",10, "    ; comment 2",10, "    mov rdi, theprogram",10, "    mov rsi, theprogram",10, "    xor eax, eax",10, "    call printf",10, "    ret",10,0

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