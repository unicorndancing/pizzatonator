NASM = nasm -f elf64
AR = ar rcs
RM = rm -f

NAME = libasm.a

SRCS =	not_bonus_files/ft_read.s \
		not_bonus_files/ft_write.s \
		not_bonus_files/ft_strcmp.s \
		not_bonus_files/ft_strdup.s \
		not_bonus_files/ft_strlen.s \
		not_bonus_files/ft_strcpy.s \
		bonus_files/ft_list_push_front.s \
		bonus_files/ft_list_size.s  \
		bonus_files/ft_atoi_base.s  \
		bonus_files/ft_list_sort.s	\
		bonus_files/ft_remove_if.s	\

OBJS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.s
	$(NASM) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re