/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_in_hex_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:18:28 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/15 09:58:33 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_pointer_in_hex(void *p)
{
	int	count_print;

	count_print = 0;
	count_print += print_string("0x");
	count_print += recursive_print_hex(p, "0123456789abcdef");
	return (count_print);
}

int	recursive_print_hex(void *p, const char *hex)
{
	unsigned long	nbr;
	int				count_print;

	nbr = (unsigned long)p;
	count_print = 0;
	if (nbr > 15)
	{
		count_print += recursive_print_hex((void *)(nbr / 16), hex);
	}
	count_print += print_char(hex[nbr % 16]);
	return (count_print);
}
