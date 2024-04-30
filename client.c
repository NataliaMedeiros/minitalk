/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/30 15:25:28 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/30 16:48:02 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	error_exit(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	bit_read(int pid_server, int nb)
{
	int	count;
	int	n;
	int	i;

	count = 0;
	i = 0;
	while (count < 8)
	{
		n = nb >> count & 1;
		if (n == 1)
			kill(pid_server, SIGUSR1);
		else
			kill(pid_server, SIGUSR2);
		usleep(1000);
		count++;
	}
}

int	main(int argc, char **argv)
{
	int	pid_server;
	int	i;

	if (argc != 3)
		error_exit("Missing PID and/or string, please insert following this structure:\n \
./client <PID> <message>\n");
	pid_server = ft_adapted_atoi(argv[1]);
	if (pid_server < 0)
		error_exit("Invalid PID:\nThe PID should be a positive integer\n");
	i = 0;
	while (argv[2][i] != '\0')
	{
		bit_read(pid_server, argv[2][i]);
		i++;
	}
	bit_read(pid_server, '\0');
	return (0);
}
