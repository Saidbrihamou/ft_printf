/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:06:20 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/14 21:53:35 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
