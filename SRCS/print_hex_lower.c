/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:36:36 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/15 10:04:30 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_lowercase(unsigned int nbr)
{
	return (recursive_print_hex((void *)(long)nbr, "0123456789abcdef"));
}
