/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal_or_integer_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:42:45 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/15 09:49:29 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_decimal_or_integer(int n)
{
	int		count_print;
	long	nbr;
	int		singe;
	char	c;

	singe = 1;
	nbr = n;
	count_print = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		count_print += write(1, "-", 1);
	}
	if (nbr > 9)
		count_print += print_decimal_or_integer(nbr / 10);
	c = nbr % 10 + '0';
	count_print += write(1, &c, 1);
	return (count_print);
}
