/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:42:37 by msv               #+#    #+#             */
/*   Updated: 2023/05/26 12:59:29 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_sigusr2(int signum)
{
	int static	bits = 0;
	char static	character = 0;

	if (signum == SIGUSR1)
	{
		character <<= 1;
	}
	if (signum == SIGUSR2)
	{
		character <<= 1;
		character |= 1;
	}
	++bits;
	if (bits == 8)
	{
		write(1, &character, 1);
		bits = 0;
		character = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, handler_sigusr2);
		signal(SIGUSR2, handler_sigusr2);
		pause();
	}
}
