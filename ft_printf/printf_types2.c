/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:49:38 by mansanch          #+#    #+#             */
/*   Updated: 2022/11/01 13:00:46 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr_mem(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += ft_printstr("0x");
	len += ft_print_ptr(ptr);
	return (len);
}

int	ft_printstr_exa(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += ft_print_ptr(ptr);
	return (len);
}

int	ft_print_ptr2(unsigned int ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		len += ft_putchar('0');
	else if (ptr > 0)
	{
		if (ptr >= 16)
			len += ft_print_ptr2(ptr / 16);
		if ((ptr % 16) >= 10)
			len += ft_putchar('7' + (ptr % 16));
		else
			len += ft_putchar('0' + ptr % 16);
	}
	return (len);
}

int	ft_printstr_exa2(unsigned int ptr)
{
	int	len;

	len = 0;
	len += ft_print_ptr2(ptr);
	return (len);
}
