/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:03:16 by mansanch          #+#    #+#             */
/*   Updated: 2022/10/05 18:26:34 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *)str;
	i = 0;
	while ((*(ptr + i) != (char)c) && (*(ptr + i) != '\0'))
		i++;
	if (*(ptr + i) == (char)c)
		return (ptr + i);
	else
		return (0);
}
