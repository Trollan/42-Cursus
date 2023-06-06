/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:12:52 by mansanch          #+#    #+#             */
/*   Updated: 2023/06/06 15:52:44 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*numbers;
	int		lenght;
	t_stack	*box_a;

	numbers = 0;
	if (argc < 2)
	{
		printf("No se recibieron argumentos.\n");
		return (0);
	}
	else if (argc == 2)
	{
		argv = parce_an_argument(argv);
		lenght = lenght_argument(argv);
		ft_parcechars(argv);
		checkmax(argc, argv);
		numbers = ft_parceints2(lenght, argv, numbers); // Tamaño incorrecto
		ft_check_double_number2(numbers, lenght);
		box_a = ft_calloc(lenght, sizeof(t_stack));
		add_numbers(box_a, numbers, lenght);
		sort_numbers(numbers, lenght);
		add_index(box_a, numbers, lenght);
		return (0);
	}
	else if (argc > 2)
	{
		ft_parcechars(argv);
		checkmax(argc, argv);
		numbers = ft_parceints(argc, argv, numbers);
		ft_check_double_number(numbers, argc - 1);
		box_a = ft_calloc(lenght, sizeof(t_stack));
		add_numbers(box_a, numbers, lenght);
		sort_numbers(numbers, lenght);
		add_index(box_a, numbers, lenght);
	}
	return (0);
}
