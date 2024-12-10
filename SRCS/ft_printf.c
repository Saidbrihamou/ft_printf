/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:06:20 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/15 10:00:49 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	argvar;

	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(argvar, format);
	count = print_format_and_vars(format, argvar);
	va_end(argvar);
	return (count);
}
