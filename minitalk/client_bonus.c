/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:16:46 by msv               #+#    #+#             */
/*   Updated: 2023/05/26 15:53:32 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendsignal2(char *character, int pid)
{
	int	bit;
	int	bin;
	int	i;

	i = 0;
	while (character[i])
	{
		bit = 7;
		while (bit >= 0)
		{
			bin = (character[i] >> bit) & 1;
			if (bin == 1)
				kill(pid, SIGUSR2);
			if (bin == 0)
				kill(pid, SIGUSR1);
			bit--;
			usleep(150);
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_confirm(int sig)
{
	static int	i = 0;

	if (sig == SIGUSR1)
		i++;
	ft_printf("%s", "Word Recived: ");
	ft_printf("%i", i);
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	signal(SIGUSR1, ft_confirm);
	if (argc != 2 && argc != 3)
	{
		printf("client: invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	if (argv[2] != NULL)
	{
		sendsignal2(argv[2], atoi(argv[1]));
	}
	usleep(150);
	return (0);
}
