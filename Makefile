# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: natalia <natalia@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2023/10/24 17:19:02 by natalia       #+#    #+#                  #
#    Updated: 2024/04/30 16:19:48 by natalia       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
NAME = minitalk

SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_CLIENT_BONUS = client_bonus.c
SRC_SERVER_BONUS = server_bonus.c

O_CLIENT = $(SRC_CLIENT:%.c=%.o)
O_SERVER = $(SRC_SERVER:%.c=%.o)
O_CLIENT_BONUS = $(SRC_CLIENT_BONUS:%.c=%.o)
O_SERVER_BONUS = $(SRC_SERVER_BONUS:%.c=%.o)

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

LIBFTDIR = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: client server $(LIBFT)

bonus: client_bonus server_bonus $(LIBFT)

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

server_bonus: $(LIBFT) $(O_SERVER_BONUS)
	${CC} ${CFLAGS} $(O_SERVER_BONUS) $(LIBFT) -o $(SERVER_BONUS)

client_bonus: $(LIBFT) $(O_CLIENT_BONUS)
	${CC} ${CFLAGS} $(O_CLIENT_BONUS) $(LIBFT) -o $(CLIENT_BONUS)

clean:
	@cd libft && $(MAKE) clean 1> /dev/null
	@rm -f $(O_CLIENT)
	@rm -f $(O_SERVER)
	@rm -f $(O_CLIENT_BONUS)
	@rm -f $(O_SERVER_BONUS)

fclean: clean
	@cd libft && $(MAKE) fclean 1> /dev/null
	@rm -f $(CLIENT)
	@rm -f $(SERVER)
	@rm -f $(CLIENT_BONUS)
	@rm -f $(SERVER_BONUS)

re: fclean all

.PHONY: all, clean, fclean, re
