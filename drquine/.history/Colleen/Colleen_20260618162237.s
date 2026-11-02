;colleen
global main
extern printf

section .text

main:
    push rbx
    lea rdi, [rel format]
    lea rsi, [rel format]
    mov rdx, 10
    mov rcx, 34
    xor rax, rax
    call printf
    pop rsi
    ret ;ret

format:
db ";colleen%2$cglobal main%2$cextern printf%2$c%2$csection .text%2$c%2$cmain:%2$c    push rbx%2$c    lea rdi, [rel format]%2$c    lea rsi, [rel format]%2$c    mov rdx, 10%2$c    mov rcx, 34%2$c    xor rax, rax%2$c    call printf%2$c    pop rsi%2$c    ret ;ret%2$c    %2$c    format:%2$c    db %3$c%1$s%3$c, 0", 0