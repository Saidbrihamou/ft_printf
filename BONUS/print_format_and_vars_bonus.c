/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_and_vars_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:57:16 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/15 15:57:31 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
	if (c == '%')
		return (print_mod());
	return (0);
}

int	handling_and_print(va_list arg_var, const char *format, int *i)
{
	t_flags	*var_flags;
	int		count_print;

	count_print = 0;
	(*i)++;
	var_flags = get_flags_list(format, arg_var, i, get_new_var_flags());
	cheak_is_width_negative(var_flags);
	if (var_flags->hash == 1)
		count_print = hash(format, i, arg_var, var_flags);
	else if (var_flags->space == 1)
		count_print = space(format, i, arg_var, var_flags);
	else if (var_flags->add == 1)
		count_print = add(format, i, arg_var, var_flags);
	else if (var_flags->whith > 0 && !var_flags->ispoint \
										&& !var_flags->subtract)
		count_print = (width(format, i, arg_var, var_flags));
	else if (var_flags->subtract == 1)
		count_print = (left_aligns(format, i, arg_var, var_flags));
	else if (var_flags->ispoint == 1)
		count_print = right_alings(format, i, arg_var, var_flags);
	else
		count_print += print_in_your_format(arg_var, format[*i]);
	free(var_flags);
	return (count_print);
}

void	cheak_is_width_negative(t_flags *flags)
{
	if (flags->whith < 0)
	{
		flags->whith *= -1;
		flags->subtract = 1;
	}
}

t_flags	*get_flags_list(const char *format, va_list arg_var, \
										int *i, t_flags *var_flags)
{
	while (ft_isdigit(format[*i]) || isflags(format[*i]))
	{
		if (format[*i] == '.')
			var_flags->ispoint = 1;
		if (format[*i] == ' ')
			var_flags->space = 1;
		else if (format[*i] == '+')
			var_flags->add = 1;
		else if (format[*i] == '#')
			var_flags->hash = 1;
		else if (format[*i] == '-')
			var_flags->subtract = 1;
		else if (format[*i] == '0')
			var_flags->zero = 1;
		else if (format[*i] == '.' && ft_isdigit(format[*i + 1]) && ++(*i))
			var_flags->point = ft_atoi(format, i);
		else if (format[*i] == '.' && format[*i + 1] == '*' && ++(*i))
			var_flags->point = va_arg(arg_var, int);
		else if (format[*i] == '*')
			var_flags->whith = va_arg(arg_var, int);
		else if (ft_isdigit(format[*i]))
			var_flags->whith = ft_atoi(format, i);
		(*i)++;
	}
	return (var_flags);
}

int	print_format_and_vars(const char *format, va_list arg_var)
{
	int		i;
	int		print_count;

	print_count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && (isformat(format[i + 1]) || \
			ft_isdigit(format[i + 1]) || isflags(format[i + 1])))
		{
			if (format[i + 1] == '%')
			{
				i++;
				print_count += print_char('%');
			}
			else
			{
				print_count += handling_and_print(arg_var, format, &i);
			}
		}
		else if (format[i] != '%')
			print_count += print_char(format[i]);
		i++;
	}
	return (print_count);
}
