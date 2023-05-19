/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:07:09 by mansanch          #+#    #+#             */
/*   Updated: 2022/10/04 12:47:18 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joinstr;
	size_t	i;
	size_t	x;
	size_t	z;

	if (s1 && s2)
	{
		x = ft_strlen(s1);
		z = ft_strlen(s2);
		joinstr = (char *)malloc(sizeof(char) * (x + z + 1));
		if (!joinstr)
			return (0);
		i = -1;
		while (s1[++i])
		{
			joinstr[i] = s1[i];
		}
		i = -1;
		while (s2[++i])
			joinstr[x++] = s2[i];
		joinstr[x] = '\0';
		return (joinstr);
	}
	return (0);
}
