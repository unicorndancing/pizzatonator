; void    void ft_list_sort(t_list **begin_list, int (*cmp)());
; rdi holds list_start
; rsi hold function to compare


section .text
    global ft_list_sort

ft_list_sort:
    test rdi, rdi
    je .done
    test rsi, rsi
    je .done

    push rbx
    push r12
    push r13
    push r14

    mov r14, [rdi]          ; head
    test r14, r14
    je .restore

    mov r12, rsi            ; cmp()

.outer:
    xor ecx, ecx            ; swapped = 0
    mov rbx, r14            ; current = head

.inner:
    mov r13, [rbx + 8]  ; next
    test r13, r13
    je .check

    mov rdi, [rbx]          ; current->content
    mov rsi, [r13]          ;next->content
    call r12

    test rax, rax
    jle .advance

    ; swap contents
    mov rax, [rbx]
    mov rdx, [r13]
    mov [rbx], rdx
    mov [r13], rax

    mov ecx, 1                 ; swapped = 1

.advance:
    mov rbx, r13
    jmp .inner

.check:
    test ecx, ecx
    jnz .outer

.restore:
    pop r14
    pop r13
    pop r12
    pop rbx

.done:
    ret