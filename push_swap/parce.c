/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:28:33 by mansanch          #+#    #+#             */
/*   Updated: 2023/05/31 17:48:01 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parcechars(char *argv[])
{
	int	i;
	int	z;

	i = 1;
	while (argv[i])
	{
		z = 0;
		while (argv[i][z])
		{
			if ((z == 0 && (argv[i][z] == '+' || argv[i][z] == '-')))
				write(1, "", 1);
			else if (ft_isdigit(argv[i][z]) == 1)
				write(1, "", 1);
			else
			{
				printf("error");
				exit(0);
			}
			z++;
		}
		i++;
	}
	return (1);
}

int	*ft_parceints(int argc, char *argv[], int *numbers)
{
	int			i;

	numbers = (int *)malloc((argc - 2) * sizeof(int));
	if (numbers == NULL)
	{
		printf("Error al asignar memoria.\n");
		return (0);
	}
	i = 1;
	while (argv[i] != NULL)
	{
		numbers[i - 1] = atoi(argv[i]);
		i++;
	}
	return (numbers);
}

int	checker(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("No se recibieron argumentos.\n");
		exit(0);
	}
	else if (argc == 2)
	{
		printf("Se recibio solo un argumento.\n");
		return (0);
	}
	else if (argc > 2)
	{
		ft_parcechars(argv);
	}
	return (0);
}

int	ft_check_double_number(int *numbers, int range)
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
		printf("%i", numbers[i]);
		i++;
	}
	return (1);
}

void	free_tokens(char **tokens)
{
	int	k;

	k = 0;
	while (tokens[k])
	{
		free(tokens[k]);
		k++;
	}
	free(tokens);
}
