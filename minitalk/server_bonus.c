/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:42:37 by msv               #+#    #+#             */
/*   Updated: 2023/05/26 15:51:41 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_sigusr2(int signum, siginfo_t *info, void *context)
{
	int static	bits = 0;
	char static	character = 0;

	context = 0;
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
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = &handler_sigusr2;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	printf("PID: %d\n", pid);
	while (1)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		pause();
	}
}
