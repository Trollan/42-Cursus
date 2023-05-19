/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:33:54 by mansanch          #+#    #+#             */
/*   Updated: 2022/11/01 12:39:12 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (format == 's')
		length += ft_printstr(va_arg(args, char *));
	else if (format == 'd')
		length += ft_putnbr(va_arg(args, int));
	else if (format == 'i')
		length += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		length += ft_putnbr(va_arg(args, unsigned int));
	else if (format == '%')
		length += ft_putchar('%');
	else if (format == 'p')
		length += ft_printstr_mem(va_arg(args, unsigned long long));
	else if (format == 'x')
		length += ft_printstr_exa(va_arg(args, unsigned int));
	else if (format == 'X')
		length += ft_printstr_exa2(va_arg(args, unsigned int));
	return (length);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		len;
	va_list	argument;

	i = 0;
	len = 0;
	va_start(argument, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_formats(argument, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(argument);
	return (len);
}
