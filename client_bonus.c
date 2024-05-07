/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/30 16:39:48 by natalia       #+#    #+#                 */
/*   Updated: 2024/05/07 12:41:59 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

int	g_checksignal = 0;

void	error_exit(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	sig_confirm(int sig)
{
	if (sig == SIGUSR1)
		g_checksignal = 1;
}

void	bit_read(int pid_server, int nb)
{
	int	count;
	int	n;
	int	i;
	int	kr;

	count = 0;
	while (count < 8)
	{
		g_checksignal = 0;
		i = 0;
		n = nb >> count & 1;
		if (n == 1)
			kr = kill(pid_server, SIGUSR1);
		else
			kr = kill(pid_server, SIGUSR2);
		if (kr < 0)
			error_exit("Invalid PID:");
		count++;
		while (i++ < 100000 && g_checksignal == 0)
			usleep(10);
		if (i == 100000)
			error_exit("Error: Server did not respond.\n");
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
	if (pid_server <= 0)
		error_exit("Invalid PID:\nThe PID should be a positive integer\n");
	signal(SIGUSR1, sig_confirm);
	i = 0;
	while (argv[2][i] != '\0')
	{
		bit_read(pid_server, argv[2][i]);
		i++;
	}
	bit_read(pid_server, '\0');
	if (g_checksignal == 1)
		ft_printf("Signal received back from server.\n");
	return (0);
}
