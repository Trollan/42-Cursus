/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:39:55 by mansanch          #+#    #+#             */
/*   Updated: 2023/06/06 15:46:41 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_numbers(t_stack *box_a, int *numbers, int lenght)
{
	int	i;

	i = 0;
	while (i < lenght)
	{
		box_a[i].valor = numbers[i];
		i++;
	}
}

void	sort_numbers(int *numbers, int lenght)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < lenght - 1)
	{
		j = 0;
		while (j < lenght - i - 1)
		{
			if (numbers[j] > numbers[j + 1])
			{
				temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	add_index(t_stack *box_a, int *numbers, int lenght)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 1;
	while (i < lenght)
	{
		j = 0;
		while (j < lenght)
		{
			if (numbers[i] == box_a[j].valor)
			{
				box_a[j].index = x;
				x++;
			}
			j++;
		}
		i++;
	}
	i = 0;
}
