/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnstr_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:39:44 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/15 09:58:57 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	putnstr(char *str, int n)
{
	int	i;
	int	count_print;

	if (str == NULL)
		str = "(null)";
	i = 0;
	count_print = 0;
	while (str[i] && i < n)
	{
		count_print += write(1, str + i, 1);
		i++;
	}
	return (count_print);
}
