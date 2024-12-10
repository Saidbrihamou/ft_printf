/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_print3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:45:56 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/15 17:22:54 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	right_alings(const char *format, int *i, va_list arg_var, t_flags *flags)
{
	va_list	copy_var;
	int		count_len_var;
	int		count_print;

	va_copy(copy_var, arg_var);
	count_len_var = 0;
	count_print = 0;
	if (format[*i] != 's' && format[*i] != 'c')
	{
		count_len_var += count_and_cheakzero(copy_var, format[*i], flags);
	}
	else if (format[*i] == 's')
		count_len_var += count_putnstr(va_arg(copy_var, char *), flags->point);
	else
		count_len_var += count_char();
	count_print += print_n_char(' ', flags->whith - count_len_var);
	count_print += right_alings_part2(format, i, arg_var, flags);
	return (count_print);
}

int	count_and_cheakzero_for_prec(va_list arg_copy, char format, t_flags *flags)
{
	long long	value;
	va_list		copy2;
	int			count_singe;

	count_singe = 0;
	va_copy(copy2, arg_copy);
	value = (long long)va_arg(copy2, void *);
	if (value == 0 && flags->point == 0 && flags->ispoint == 1)
	{
		if (format == 'p')
			return (2);
		return (0);
	}
	if ((format == 'i' || format == 'd') && (int)value < 0)
		count_singe = -1;
	return (count_print_var(arg_copy, format) + count_singe);
}

int	count_and_cheakzero(va_list arg_copy, char format, t_flags *flags)
{
	int		value;
	va_list	copy2;
	int		count_len_var;
	int		count_singe;

	count_singe = 0;
	va_copy(copy2, arg_copy);
	count_len_var = 0;
	value = (int)va_arg(copy2, void *);
	if (value == 0 && flags->point == 0)
	{
		if (format == 'p')
			return (2);
		return (0);
	}
	count_len_var += count_print_var(arg_copy, format);
	if ((format == 'i' || format == 'd') && value < 0 && \
							(flags->point - count_len_var) >= 0)
		count_singe++;
	count_len_var += count_n_char(flags->point - count_len_var) + count_singe;
	return (count_len_var);
}
