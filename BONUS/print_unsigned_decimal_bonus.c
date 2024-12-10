/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:24:47 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/12 12:01:09 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_unsigned_decimal(unsigned int n)
{
	int	count_print;

	count_print = 0;
	if (n > 9)
		count_print += print_decimal_or_integer(n / 10);
	count_print += print_char(n % 10 + '0');
	return (count_print);
}
