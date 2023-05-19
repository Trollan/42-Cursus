/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:48:11 by mansanch          #+#    #+#             */
/*   Updated: 2022/10/13 12:48:11 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*next;

	if (lst != NULL)
	{
		next = lst;
		while (1)
		{
			(*f)(next->content);
			next = next->next;
			if (next == NULL)
				return ;
		}
	}
}
