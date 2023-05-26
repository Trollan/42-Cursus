/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 10:32:21 by mansanch          #+#    #+#             */
/*   Updated: 2022/10/04 12:46:44 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str1, int c, size_t n)
{
	size_t			i;
	unsigned char	*str2;
	unsigned char	character;

	str2 = (unsigned char *)str1;
	character = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*str2 == character)
		{
			return (str2);
		}
		str2++;
		i++;
	}
	return (0);
}
