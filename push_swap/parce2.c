/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:09:38 by mansanch          #+#    #+#             */
/*   Updated: 2023/05/31 19:00:04 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parce_an_argument(char *argv[])
{
	argv = ft_split(argv[1], ' ');
	return (argv);
}

int	checkmax(int argc, char *argv[])
{
	long		*token;
	int			i;

	token = ft_calloc(argc - 2, sizeof(long));
	if (token == NULL)
	{
		printf("Error al asignar memoria.\n");
		return (0);
	}
	i = 0;
	while (argv[i] != NULL)
	{
		token[i] = ft_atoi(argv[i]);
		if (token[i] <= 2147483647 && token[i] >= -2147483648)
			i++;
		else
		{	
			ft_printf("Sale de los limited del int");
			exit(0);
		}
	}
	free(token);
	return (1);
}

int	*ft_parceints2(int length, char *argv[], int *numbers)
{
	int	i;

	numbers = ft_calloc(length, sizeof(int));
	if (numbers == NULL)
	{
		printf("Error al asignar memoria.\n");
		return (0);
	}
	i = 0;
	while (argv[i] != NULL)
	{
		numbers[i] = ft_atoi(argv[i]);
		i++;
	}
	i = 0;
	return (numbers);
}

int	lenght_argument(char *string[])
{
	int	i;
	int	x;

	i = 0;
	while (string[i])
	{
		x = 0;
		while (string[i][x])
		{
			x++;
		}
		i++;
	}
	return (i);
}

int	ft_check_double_number2(int *numbers, int range)
{
	int	i;
	int	z;

	i = 0;
	while (i < range)
	{
		z = 0;
		while (z < range)
		{
			if (i != z && numbers[i] == numbers[z])
			{
				printf("Error numero repetido");
				free(numbers);
				exit(0);
			}
			z++;
		}
		i++;
	}
	return (1);
}
