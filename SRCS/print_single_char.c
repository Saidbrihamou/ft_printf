/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_single_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:27:13 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/09 12:43:22 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	return (write(1, &c, 1));
}
