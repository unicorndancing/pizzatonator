; void    void ft_list_sort(t_list **begin_list, int (*cmp)());
; rdi holds list_start
; rsi hold function to compare


global ft_list_sort

section .text

ft_list_sort:
    

.done:
    ret