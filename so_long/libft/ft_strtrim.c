/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:32:37 by mansanch          #+#    #+#             */
/*   Updated: 2022/10/04 12:47:50 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	char	*trimstr;

	if (!s1 || !set)
	{
		return (0);
	}
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
	}
	size = ft_strlen(s1);
	while (size && ft_strchr(set, s1[size]))
	{
		size--;
	}
	trimstr = ft_substr((char *)s1, 0, size + 1);
	return (trimstr);
}
