global ft_list_push_front


extern malloc
section .text

ft_list_push_front:
    mov rbx, rdi
    mov rdx, rsi

    mov rdi, 16

    call malloc
    test rax, rax
    je .done

    mov [rax], rdx
    mov rcx, [rbx]
    mov qword [rax + 8], rcx
    mov [rbx], rax

.done:
    pop rbx
    ret