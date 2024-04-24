# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: natalia <natalia@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2023/10/24 17:19:02 by natalia       #+#    #+#                  #
#    Updated: 2024/04/24 18:26:21 by nmedeiro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
FILES = client.c \
		server.c \

OFILES = $(FILES:%.c=%.o)
NAME = minitalk

LIBFTDIR = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

${NAME}: server client

$(LIBFT):
	@echo "Compiling ..."
	@make -C $(LIBFTDIR)
	@echo "Compiled ✅ $(LIBFT)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFTDIR)

server: server.o $(LIBFT)
	${CC} ${CFLAGS} server.o $(LIBFT) -o server

client: client.o $(LIBFT)
	${CC} ${CFLAGS} client.o $(LIBFT) -o client

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
