global ft_list_push_front
extern malloc
%include "../libasm.inc"

section .text

.ft_list_push_front:
    push rdi
    push rsi
    test rdi + NEXT, rdi + DATA
    je .only_element



.only_element:
    mov rdi + DATA, rsi
    mov rdi + NEXT, 0
    mov rax, rdi
    ret