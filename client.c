#include "libft/libft.h"
#include <signal.h>
#include <time.h>

double total_time = 0;

void	error_exit(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void check_time(clock_t start)
{
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
	total_time += time_taken;
    // printf("Execution time: %f seconds\n", time_taken);
}

void	bit_read(int pid_server, int nb)
{
	int	count;
	int	n;
	clock_t start = clock();

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
	check_time(start);
}

int	main(int argc, char **argv)
{
	int	pid_server;
	int	i;

	if (argc != 3)
		error_exit("Missing PID and/or string, please insert following this structure:\n \
./client <PID> <message>\n");
	pid_server = ft_atoi(argv[1]);
	if (pid_server < 0)
		return (ft_putstr_nl("Invalid PID"), EXIT_FAILURE);
	i = 0;
	while (argv[2][i] != '\0')
	{
		bit_read(pid_server, argv[2][i]);
		i++;
	}
	bit_read(pid_server, '\0');
	printf("Execution time: %f seconds\n", total_time);
	return (0);
}
