/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:23:51 by mansanch          #+#    #+#             */
/*   Updated: 2022/10/04 12:47:45 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		length;

	length = ft_strlen(str);
	while (length >= 0)
	{
		if ((unsigned char) str[length] == (unsigned char)c)
			return ((char *)&str[length]);
		length--;
	}
	return (0);
}
