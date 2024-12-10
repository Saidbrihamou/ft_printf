/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_is_flags_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:49:57 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/14 22:01:49 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	isflags(char c)
{
	char	*format;

	format = "-.0# +*";
	while (*format)
	{
		if (*format == c)
			return (1);
		format++;
	}
	return (0);
}

int	isformat(char c)
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

t_flags	*get_new_var_flags(void)
{
	t_flags	*flag;

	flag = malloc(sizeof(t_flags));
	if (!flag)
		return (NULL);
	flag->add = 0;
	flag->hash = 0;
	flag->point = 0;
	flag->space = 0;
	flag->ispoint = 0;
	flag->subtract = 0;
	flag->whith = 0;
	flag->zero = 0;
	return (flag);
}
