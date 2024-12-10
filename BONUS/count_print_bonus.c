/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_print_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:15:12 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/14 20:33:35 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	count_print_var(va_list arg_var, char format)
{
	if (format == 'c')
		return (count_char());
	if (format == 's')
		return (count_string(va_arg(arg_var, char *)));
	if (format == 'p')
		return (count_pointer(va_arg(arg_var, void *)));
	if (format == 'd')
		return (count_decimal_or_integer(va_arg(arg_var, int)));
	if (format == 'i')
		return (count_decimal_or_integer(va_arg(arg_var, int)));
	if (format == 'u')
		return (count_unsigned_decimal(va_arg(arg_var, unsigned int)));
	if (format == 'x')
		return (count_hex(va_arg(arg_var, int)));
	if (format == 'X')
		return (count_hex(va_arg(arg_var, int)));
	if (format == '%')
		return (count_mod());
	return (0);
}

int	count_unsigned_decimal(unsigned int n)
{
	int	count_print;

	count_print = 0;
	if (n > 9)
		count_print += count_unsigned_decimal(n / 10);
	count_print += 1;
	return (count_print);
}

int	count_decimal_or_integer(int n)
{
	int		count_print;
	long	nbr;
	int		singe;

	singe = 1;
	nbr = n;
	count_print = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		count_print += 1;
	}
	if (nbr > 9)
		count_print += count_decimal_or_integer(nbr / 10);
	count_print += 1;
	return (count_print);
}

int	count_n_char(int n)
{
	int	i;
	int	count_print;

	count_print = 0;
	i = 0;
	while (i < n)
	{
		count_print += 1;
		i++;
	}
	return (count_print);
}

int	count_putnstr(char *str, int n)
{
	int	i;
	int	count_print;

	i = 0;
	if (str == NULL)
		str = "(null)";
	count_print = 0;
	while (str[i] && i < n)
	{
		count_print += 1;
		i++;
	}
	return (count_print);
}
