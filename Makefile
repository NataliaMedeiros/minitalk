# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: natalia <natalia@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2023/10/24 17:19:02 by natalia       #+#    #+#                  #
#    Updated: 2024/05/07 13:30:59 by natalia       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
NAME = minitalk

SRC_CLIENT = client.c
SRC_SERVER = server.c

O_CLIENT = $(SRC_CLIENT:%.c=%.o)
O_SERVER = $(SRC_SERVER:%.c=%.o)

SERVER = server
CLIENT = client

LIBFTDIR = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: client server $(LIBFT)

$(LIBFT):
	@echo "Compiling ..."
	@make -C $(LIBFTDIR)
	@echo "Compiled ✅ $(LIBFT)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

server: $(LIBFT) $(O_SERVER)
	${CC} ${CFLAGS} $(O_SERVER) $(LIBFT) -o $(SERVER)

client: $(LIBFT) $(O_CLIENT)
	${CC} ${CFLAGS} $(O_CLIENT) $(LIBFT) -o $(CLIENT)

clean:
	@cd libft && $(MAKE) clean 1> /dev/null
	@rm -f $(O_CLIENT)
	@rm -f $(O_SERVER)

fclean: clean
	@cd libft && $(MAKE) fclean 1> /dev/null
	@rm -f $(CLIENT)
	@rm -f $(SERVER)

re: fclean all

.PHONY: all, clean, fclean, re
g