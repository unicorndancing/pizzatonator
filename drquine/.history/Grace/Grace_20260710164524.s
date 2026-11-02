;Grace
%define PRINTFSTR ";Grace%1$c%%define PRINTFSTR %2$c%3$s%2$c%1$c%%define DECLAREMAIN global main%1$c%%define MAIN main:%1$csection .text%1$cextern dprintf%1$cextern printf%1$cextern open%1$cDECLAREMAIN%1$cMAIN%1$cpush    rbx%1$clea     rdi, [rel filename]%1$cmov     rsi, 0x202%1$cmov     rax, 0x2000005%1$cmov     rdx, 644o%1$csyscall%1$clea     rsi, [rel filecontent]%1$cmov     rdi, rax%1$cmov     rdx, 10%1$cmov     rcx, 34%1$clea     r8, [rel filecontent]%1$ccall    dprintf%1$cpop     rbx%1$cret%1$c%1$csection .data%1$cfilename:%1$cdb %2$cGracekid.s%2$c, 0%1$cfilecontent:%1$cdb PRINTFSTR, 0"
%define DECLAREMAIN global main
%define MAIN main:
section .text
extern dprintf
extern printf
extern open
DECLAREMAIN
MAIN
push    rbx
lea     rdi, [rel filename]
mov     rsi, 0x202
mov     rax, 2
mov     rdx, 644o
syscall
lea     rsi, [rel filecontent]
mov     rdi, rax
mov     rdx, 10
mov     rcx, 34
lea     r8, [rel filecontent]
call    dprintf
pop     rbx
ret

section .data
filename:
db "Gracekid.s", 0
filecontent:
db PRINTFSTR, 0