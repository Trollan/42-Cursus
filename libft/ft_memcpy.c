/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:31:54 by mansanch          #+#    #+#             */
/*   Updated: 2022/10/04 12:46:52 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	size_t	i;

	if (!destination && !source)
		return (0);
	i = 0;
	while (i < num)
	{
		((unsigned char *)destination)[i] = ((unsigned char *)source)[i];
		i++;
	}
	return (destination);
}
