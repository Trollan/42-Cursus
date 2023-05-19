/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:00:58 by mansanch          #+#    #+#             */
/*   Updated: 2022/10/04 12:47:13 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	char	*mal;
	int		i;

	size = ft_strlen(s);
	mal = malloc(sizeof(char) * size + 1);
	if (!mal)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		mal[i] = s[i];
		i++;
	}
	mal[i] = 0;
	return (mal);
}
