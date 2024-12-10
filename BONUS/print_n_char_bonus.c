/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_n_char_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:30:59 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/15 09:57:29 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_n_char(char c, int n)
{
	int	i;
	int	count_print;

	count_print = 0;
	i = 0;
	while (i < n)
	{
		count_print += print_char(c);
		i++;
	}
	return (count_print);
}
