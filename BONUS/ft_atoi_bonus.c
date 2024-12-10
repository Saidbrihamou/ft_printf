/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:11:05 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/14 21:50:45 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	skep_and_singe(int *i, const char *str)
{
	int	singe;

	singe = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			singe = -1;
		}
		(*i)++;
	}
	return (singe);
}

int	ft_atoi(const char *str, int *i)
{
	int			singe;
	long long	resulat;

	resulat = 0;
	singe = skep_and_singe(i, str);
	while (ft_isdigit(str[*i]))
	{
		resulat *= 10;
		resulat += str[*i] - '0';
		(*i)++;
	}
	(*i)--;
	return (resulat * singe);
}
