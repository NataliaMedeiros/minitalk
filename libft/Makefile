NAME = libft.a

FILES = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_itoa.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_nl.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putstr.c \
		ft_putstr_nl.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strlen.c \
		ft_strlen_nl.c \
		get_next_line_utils.c \
		get_next_line.c \
		ft_printf.c \
		ft_printf_utils.c \
		ft_puthex.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_adapted_atoi.c \
		ft_strcharjoin.c \
		ft_strcharcat.c \


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
