global ft_write

extern __errno_location ;je suis con

section .text

ft_write:
    mov rax, 1
    syscall

    cmp rax, 0
    jge .done

    neg rax
    push    rax

    call    __errno_location
    pop     rdx

    mov     [rax], edx

    mov     rax, -1
    ret

.done:
    ret