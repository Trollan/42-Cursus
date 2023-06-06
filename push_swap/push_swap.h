/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:04:06 by mansanch          #+#    #+#             */
/*   Updated: 2023/05/31 18:34:21 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h" 

typedef struct s_stack
{
	int				valor;
	int				index;
	int				pos;
	int				obj;
	int				cost_a;
	int				cost_b;
}t_stack;

int		ft_parcechars(char *argv[]);
int		*ft_parceints(int argc, char *argv[], int *numbers);
int		checker(int argc, char *argv[]);
int		ft_check_double_number(int *numbers, int range);
char	**parce_an_argument(char *argv[]);
int		*ft_parceints2(int argc, char *argv[], int *numbers);
int		lenght_argument(char *string[]);
int		ft_check_double_number2(int *numbers, int range);
int		checkmax(int argc, char *argv[]);
void	add_numbers(t_stack *box_a, int *numbers, int lenght);
void	free_tokens(char **tokens);
void	sort_numbers(int *numbers, int lenght);
void	add_index(t_stack *box_a, int *numbers, int lenght);

#endif