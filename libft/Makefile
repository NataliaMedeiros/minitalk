# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: natalia <natalia@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2023/10/24 17:19:02 by natalia       #+#    #+#                  #
#    Updated: 2024/04/24 16:33:22 by nmedeiro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

Library = libft
Files = ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_strchr \
		ft_strlcat \
		ft_strlcpy \
		ft_strrchr \
		ft_strlen \
		ft_memset \
		ft_bzero \
		ft_atoi \
		ft_isalnum \
		ft_strdup \
		ft_tolower \
		ft_toupper \
		ft_memchr \
		ft_memcmp \
		ft_strncmp \
		ft_strnstr \
		ft_memcpy \
		ft_memmove \
		ft_calloc \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_striteri \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_printf_utils \
		ft_printf \
		ft_puthex \
		ft_lstnew \
		ft_lstadd_front \
		ft_lstsize \
		ft_lstlast \
		ft_lstadd_back \
		ft_lstdelone \
		ft_lstclear \
		ft_lstiter \
		ft_lstmap \

CFILES = $(Files:%=%.c)
OFILES = $(CFILES:%.c=%.o)
NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	@ar -rc $(NAME) $(OFILES)

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
