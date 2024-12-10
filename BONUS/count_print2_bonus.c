/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_print2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:18:09 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/14 20:32:32 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	recursive_count_hex(void *p, const char *hex)
{
	unsigned long	nbr;
	int				count_print;

	count_print = 0;
	nbr = (unsigned long)p;
	if (nbr > 15)
	{
		count_print += recursive_count_hex((void *)(nbr / 16), hex);
	}
	count_print += 1;
	return (count_print);
}

int	count_char(void)
{
	return (1);
}

int	count_string(const char *str)
{
	if (!str)
		return (6);
	return (ft_strlen((char *)str));
}

int	count_hex(unsigned int i)
{
	return (recursive_count_hex((void *)(long long)i, "0123456789abcdef"));
}

int	count_pointer(void *p)
{
	return (recursive_count_hex(p, "0123456789abcdef") + 2);
}
