/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_and_vars.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:57:16 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/15 10:04:11 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	isformat(char c)
{
	char	*format;

	format = "cspdiuxX%";
	while (*format)
	{
		if (*format == c)
			return (1);
		format++;
	}
	return (0);
}

int	print_in_your_format(va_list arg_var, char c)
{
	if (c == 'c')
		return (print_char(va_arg(arg_var, int)));
	if (c == 's')
		return (print_string(va_arg(arg_var, char *)));
	if (c == 'p')
		return (print_pointer_in_hex(va_arg(arg_var, void *)));
	if (c == 'd')
		return (print_decimal_or_integer(va_arg(arg_var, int)));
	if (c == 'i')
		return (print_decimal_or_integer(va_arg(arg_var, int)));
	if (c == 'u')
		return (print_unsigned_decimal(va_arg(arg_var, unsigned int)));
	if (c == 'x')
		return (print_hex_lowercase(va_arg(arg_var, int)));
	if (c == 'X')
		return (print_hex_uppercase(va_arg(arg_var, int)));
	return (0);
}

int	print_format_and_vars(const char *format, va_list arg_var)
{
	size_t	i;
	int		print_count;

	print_count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && isformat(format[i + 1]))
		{
			if (format[i + 1] == '%')
			{
				i++;
				print_count += print_char('%');
			}
			else
			{
				print_count += print_in_your_format(arg_var, format[i + 1]);
				i++;
			}
		}
		else if (format[i] != '%')
			print_count += print_char(format[i]);
		i++;
	}
	return (print_count);
}
