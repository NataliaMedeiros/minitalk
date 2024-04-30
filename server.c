/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/29 13:11:59 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/30 14:10:45 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <time.h>

void	signal_handler(int signum)
{
	static unsigned char	buff;
	static int				i;


	buff |= (signum == SIGUSR1) << i;
	i++;
	if (i == 8)
	{
		ft_putchar(buff);
		i = 0;
		buff = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
