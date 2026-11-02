global ft_strdup


extern ft_strlen
extern malloc

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
    mov dl, [rsi + rcx]

    mov [rdi + rcx], dl

    cmp dl, 0
    je .done
    inc rcx
    jmp .copy

.done:
    ret

.fail:
    pop rdi
    xor rax, rax
    ret