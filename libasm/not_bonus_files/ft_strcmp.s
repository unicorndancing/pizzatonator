global ft_strcmp
section .text

ft_strcmp:
    xor rcx, rcx

.loop:
    movzx eax, byte [rdi + rcx]
    movzx edx, byte [rsi + rcx]

    cmp eax, edx
    jne .done

    test eax, eax
    je .equal

    inc rcx
    jmp .loop

.done:
    sub eax, edx
    ret

.equal:
    xor eax, eax
    ret
