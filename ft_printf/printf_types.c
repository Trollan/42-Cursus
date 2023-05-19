/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:15:27 by mansanch          #+#    #+#             */
/*   Updated: 2022/10/13 15:15:27 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_printstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_numlen(long i)
{
	int	j;

	j = 0;
	if (i == -2147483648)
		return (11);
	if (i == 0)
		return (1);
	else if (i < 0)
	{
		j++;
		i = i * -1;
	}
	while (i > 0)
	{
		i = i / 10;
		j++;
	}
	return (j);
}

int	ft_putnbr(long n)
{
	if (n == -2147483648)
	{
		ft_putnbr(n / 10);
		ft_putchar('8');
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10);
		ft_putchar('0' + (n % 10));
	}
	return (ft_numlen(n));
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		len += ft_putchar('0');
	else if (ptr > 0)
	{
		if (ptr >= 16)
			len += ft_print_ptr(ptr / 16);
		if ((ptr % 16) >= 10)
			len += ft_putchar('W' + (ptr % 16));
		else
			len += ft_putchar('0' + ptr % 16);
	}
	return (len);
}
