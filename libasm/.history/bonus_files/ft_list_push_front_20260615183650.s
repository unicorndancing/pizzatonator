global ft_list_push_front


extern malloc
section .text

ft_list_push_front:
    ; rdi = t_list **begin_list
    ; rsi = void *data

    push rbx                ; preserve callee-saved register

    mov rbx, rdi            ; save begin_list
    mov rdx, rsi            ; save data

    mov rdi, 16             ; sizeof(t_list)
    call malloc

    test rax, rax
    jz .done                ; malloc failed

    mov [rax], rdx          ; new_node->data = data

    mov rcx, [rbx]          ; *begin_list
    mov [rax + 8], rcx      ; new_node->next = *begin_list

    mov [rbx], rax          ; *begin_list = new_node

.done:
    pop rbx
    ret