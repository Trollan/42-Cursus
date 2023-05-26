/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:16:46 by msv               #+#    #+#             */
/*   Updated: 2023/05/26 15:56:42 by mansanch         ###   ########.fr       */
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
	i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 2 && argc != 3)
	{
		printf("client: invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	if (argv[2] != NULL)
	{
		sendsignal2(argv[2], atoi(argv[1]));
	}
	return (0);
}
