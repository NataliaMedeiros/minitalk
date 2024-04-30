/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/29 14:53:07 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/30 14:09:10 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* SA_SIGINFO - This flag indicates that the signal handler should receive    */
/*				addtional information when a signal is received. When this    */
/*				information is defined, it includes a pointer to a siginfo_t  */
/*				structure. This structure contains detailed information about */
/*				the signal, such as the process's PID                         */
/* SA_NODEFER - This flag explicitly indicates that signals won't be bloqued. */
/*				This allows the same signal to be received and processed      */
/*				again while a signal handler is running.                      */
/* ************************************************************************** */


#include "libft/libft.h"
#include <signal.h>

void	error_exit(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	buff;
	static int				i;

	(void) context;
	buff |= (signum == SIGUSR1) << i;
	i++;
	if (i == 8)
	{
		ft_putchar(buff);
		i = 0;
		buff = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		error_exit("Error: fail to send the signal to client\n");
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO | SA_NODEFER;
	sa.sa_sigaction = &signal_handler;
	if (sigemptyset(&sa.sa_mask) == -1)
		error_exit("Error: function sigemptyset failled\n");
	ft_printf("PID: %d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		error_exit("Error: fail on setting up signal handler");
	while (1)
		pause();
	return (0);
}
