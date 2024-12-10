/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_print_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:59:01 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/15 15:59:53 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	hash(const char *format, int *i, va_list arg_var, t_flags *flags)
{
	int		count_print;
	va_list	copy_arg;
	va_list	copy_arg2;
	int		count_len_var;
	int		number;

	va_copy(copy_arg, arg_var);
	va_copy(copy_arg2, arg_var);
	number = va_arg(copy_arg, int);
	count_len_var = 0;
	if ((format[*i] == 'x' || format[*i] == 'X') && number != 0)
		count_len_var += 2;
	if (isformat(format[*i]))
		count_len_var += count_print_var(arg_var, format[*i]);
	count_print = print_n_char(' ', flags->whith - count_len_var);
	if ((format[*i] == 'x' || format[*i] == 'X') && number != 0)
	{
		if (format[*i] == 'x')
			count_print += print_string("0x");
		else
			count_print += print_string("0X");
	}
	if (isformat(format[*i]))
		count_print += (print_in_your_format(copy_arg2, format[*i]));
	return (count_print);
}

int	space(const char *format, int *i, va_list arg_var, t_flags *flags)
{
	int		count_print;
	int		number;
	va_list	copy_var;
	int		count_len_var;

	va_copy(copy_var, arg_var);
	if (format[*i] == 'd' || format[*i] == 'i')
	{
		number = va_arg(copy_var, int);
		count_len_var = (number >= 0);
		count_len_var += count_decimal_or_integer(number);
	}
	else
		count_len_var = count_print_var(copy_var, format[*i]);
	count_print = print_n_char(' ', flags->whith - count_len_var);
	if (format[*i] == 'd' || format[*i] == 'i')
	{
		number = va_arg(arg_var, int);
		if (number >= 0)
			count_print += print_char(' ');
		count_print += print_decimal_or_integer(number);
	}
	else if (isformat(format[*i]))
		count_print += print_in_your_format(arg_var, format[*i]);
	return (count_print);
}

int	add(const char *format, int *i, va_list arg_var, t_flags *flags)
{
	int		print_count;
	int		number;
	int		count_len_var;
	va_list	copy_var;

	va_copy(copy_var, arg_var);
	if (format[*i] == 'i' || format[*i] == 'd')
	{
		number = va_arg(copy_var, int);
		count_len_var = (number >= 0);
		count_len_var += count_decimal_or_integer(number);
	}
	else
		count_len_var = count_print_var(copy_var, format[*i]);
	print_count = print_n_char(' ', flags->whith - count_len_var);
	if (format[*i] == 'i' || format[*i] == 'd')
	{
		number = va_arg(arg_var, int);
		if (number >= 0)
			print_count += print_char('+');
		print_count += print_decimal_or_integer(number);
	}
	else if (isformat(format[*i]))
		print_count += print_in_your_format(arg_var, format[*i]);
	return (print_count);
}

int	print_intege_and_min_int(int number)
{
	if (number == -2147483648)
	{
		return (print_string("2147483648"));
	}
	return (print_decimal_or_integer((number < 0) * \
					(-number) + (number > 0) * number));
}

int	width(const char *format, int *i, va_list arg_var, t_flags *flags)
{
	va_list	copy_var;
	int		count_len_var;
	int		count_print;
	char	c;
	int		number;

	c = ' ';
	if (flags->zero)
		c = '0';
	count_print = 0;
	va_copy(copy_var, arg_var);
	if ((format[*i] == 'd' || format[*i] == 'i') && c == '0')
	{
		number = va_arg(arg_var, int);
		if (number < 0)
			count_print += print_char('-');
		count_len_var = count_decimal_or_integer(number);
		count_print += print_n_char(c, flags->whith - count_len_var);
		count_print += print_intege_and_min_int(number);
		return (count_print);
	}
	count_len_var = count_print_var(copy_var, format[*i]);
	count_print += print_n_char(c, flags->whith - count_len_var);
	count_print += print_in_your_format(arg_var, format[*i]);
	return (count_print);
}
