global ft_strdup


extern ft_strlen
extern malloc
extern ft_strcpy

section .text

ft_strdup:
    push rdi
    call ft_strlen
    xor rcx, rcx


.loop:
    cmp byte [rdi + rcx], 0
    je .lenght
    inc rcx
    jmp .loop


.lenght:
    inc rcx
    mov rdi, rcx
    call malloc

    test rax, rax
    je .fail

    pop rsi

    mov rdi, rax
    xor rcx, rcx

.copy:
    call ft_strcpy

.done:
    ret

.fail:
    pop rdi
    xor rax, rax 
    ret