/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:32:46 by mansanch          #+#    #+#             */
/*   Updated: 2022/11/01 12:42:06 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(int c);
int		ft_printstr(char *str);
int		ft_printf(char const *str, ...);
int		ft_putnbr(long n);
int		ft_print_ptr(unsigned long long ptr);
int		ft_printstr_mem(unsigned long long ptr);
int		ft_printstr_exa(unsigned long long ptr);
int		ft_print_ptr2(unsigned int ptr);
int		ft_printstr_exa2(unsigned int ptr);

#endif
