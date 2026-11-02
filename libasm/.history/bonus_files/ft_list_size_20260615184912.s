global ft_list_size

section .text

ft_list_size:
    xor rcx, rcx

.loop:
    test rdi, rd
    je .done

    inc rcx
    mov rdi, [rdi + 8]
    jmp .loop

.done:
    ret