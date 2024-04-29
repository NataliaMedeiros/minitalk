#include "libft/libft.h"
#include <signal.h>

void	bit_read(int pid_server, int nb)
{
	int	count;
	int	n;

	count = 0;
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
		return (ft_putstr_nl("Missing imput"), EXIT_FAILURE);
	pid_server = ft_atoi(argv[1]);
	if (pid_server <= 0)
		return (ft_putstr_nl("Wrong PID"), EXIT_FAILURE);
	i = 0;
	while (argv[2][i] != '\0')
	{
		bit_read(pid_server, argv[2][i]);
		i++;
	}
	return (0);
}
