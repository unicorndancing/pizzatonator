; void    ft_list_push_front(t_list **begin_list, void *data);
; rdi holds list_start
; rsi hold data


global ft_list_push_front


extern malloc
section .text

ft_list_push_front:
    mov rbx, rdi      ; put list_start in rbx
    mov rdx, rsi      ; put data in rdx

    mov rdi, 16       ; rdi = 16

    call malloc       ; malloc rdi (16)
    test rax, rax     ; test for NULL
    je .done          ; jump to done if NULL

    mov [rax], rdx    ; move rdx in data
    mov rcx, [rbx]    ; dereference rbx to put it in rcx
    mov qword [rax + 8], rcx  ; put the deferenced in ->next
    mov [rbx], rax ; 

.done:
    ret