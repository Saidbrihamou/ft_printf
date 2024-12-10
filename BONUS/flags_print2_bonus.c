/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_print2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:42:02 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/15 17:09:47 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_str_or_char(char format, t_flags *flags, va_list arg_var)
{
	int	count_print;

	count_print = 0;
	if (format == 's')
	{
		if (flags->ispoint == 1)
			count_print += putnstr(va_arg(arg_var, char *), flags->point);
		else
			count_print += print_in_your_format(arg_var, format);
	}
	if (format == 'c')
		count_print += print_in_your_format(arg_var, 'c');
	return (count_print);
}

int	left_aligns(const char *format, int *i, va_list arg_var, t_flags *flags)
{
	va_list	copy_var;
	int		count_len_var;
	int		count_print;

	count_print = 0;
	va_copy(copy_var, arg_var);
	if (format[*i] != 'c' && format[*i] != 's')
	{
		count_len_var = count_and_cheakzero_for_prec(copy_var, \
												format[*i], flags);
		if (format[*i] == 'i' || format[*i] == 'd')
			count_print = pint_integer_and_cheak_singe(arg_var, \
												flags, count_len_var);
		else
		{
			count_print = print_n_char('0', flags->point - count_len_var);
			count_print += print_and_cheakzero(arg_var, format[*i], flags);
		}
	}
	count_print += print_str_or_char(format[*i], flags, arg_var);
	count_print += print_n_char(' ', flags->whith - count_print);
	return (count_print);
}

int	right_alings_part2(const char *format, int *i, va_list arg_var, \
														t_flags *flags)
{
	va_list	copy_var;
	int		count_len_var;
	int		count_print;

	va_copy(copy_var, arg_var);
	count_len_var = 0;
	if (format[*i] != 's' && format[*i] != 'c')
	{
		count_len_var = count_and_cheakzero_for_prec(copy_var, \
												format[*i], flags);
		if (format[*i] == 'i' || format[*i] == 'd')
			count_print = pint_integer_and_cheak_singe(arg_var, \
											flags, count_len_var);
		else
		{
			count_print = print_n_char('0', flags->point - count_len_var);
			count_print += print_and_cheakzero(arg_var, format[*i], flags);
		}
	}
	else if (format[*i] == 's')
		count_print = putnstr(va_arg(arg_var, char *), flags->point);
	else
		count_print = print_char(va_arg(arg_var, int));
	return (count_print);
}

int	pint_integer_and_cheak_singe(va_list arg_var, t_flags *flags, \
												int count_len_var)
{
	long long	value;
	int			count_print;

	count_print = 0;
	value = va_arg(arg_var, int);
	if (value == 0 && flags->point == 0 && flags->ispoint == 1)
		return (0);
	if (value < 0)
	{
		count_print += print_char('-');
		value *= -1;
	}
	count_print += print_n_char('0', flags->point - count_len_var);
	if (value == 2147483648)
		count_print += print_string("2147483648");
	else
		count_print += print_decimal_or_integer(value);
	return (count_print);
}

int	print_and_cheakzero(va_list arg_var, char format, t_flags *flags)
{
	void	*value;
	va_list	arg_copy;

	va_copy(arg_copy, arg_var);
	if (format != 'p')
		value = (void *)(long long)va_arg(arg_copy, int);
	else
		value = va_arg(arg_copy, void *);
	if (flags->point != 0)
		return (print_in_your_format(arg_var, format));
	if (value == 0 && flags->ispoint == 1)
	{
		if (format == 'p')
			return (print_string("0x"));
		return (0);
	}
	return (print_in_your_format(arg_var, format));
}
