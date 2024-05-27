NAME = libft.a

FILES =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_memchr.c \
		ft_memcmp.c\
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_puthex.c \
		ft_putnbr_nl.c \
		ft_putnbr.c \
		ft_putstr_fd.c \
		ft_putstr_nl.c \
		ft_putstr.c \
		ft_strcat.c \
		ft_strcharcat.c \
		ft_strcharjoin.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strjoin.c \
		ft_strcat.c \
		ft_strlen_nl.c \
		ft_strlen.c \
		get_next_line_utils.c \
		get_next_line.c \
		intlen_base.c \

OFILES = $(FILES:%.c=%.o)

CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OFILES)
	@ar -rc $(NAME) $(OFILES)
	@echo "Compiled ✅ $^"

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)
	@echo
	@echo "Cleaned my_library ✅"

re: fclean all

.PHONY: all, clean, fclean, re
