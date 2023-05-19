/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:31:55 by mansanch          #+#    #+#             */
/*   Updated: 2022/10/04 12:47:42 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t	c;

	if (*to_find == 0 || str == to_find)
		return ((char *)str);
	c = ft_strlen(to_find);
	while (*str && c <= len--)
	{
		if (!(ft_strncmp((char *)str, (char *)to_find, c)))
			return ((char *)str);
		str++;
	}
	return (NULL);
}
