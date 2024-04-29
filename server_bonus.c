/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/29 14:53:07 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/29 15:29:43 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	buff;
	static int				i;

	(void) context;
	(void) info;
	// printf("%d\n", info->si_pid);
	buff |= (signum == SIGUSR1) << i;
	i++;
	if (i == 8)
	{
		ft_putchar(buff);
		i = 0;
		buff = 0;
	}
	// if (signum == SIGUSR1)
	// 	kill(info->si_pid, SIGUSR1);
	// else if (signum == SIGUSR2)
	// 	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
