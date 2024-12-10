/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:06:33 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/15 10:15:32 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *format, ...);

int		print_string(char *str);
size_t	ft_strlen(char *str);
int		print_decimal_or_integer(int n);
int		print_char(char c);
int		print_pointer_in_hex(void *p);
int		recursive_print_hex(void *p, const char *hex);
int		print_unsigned_decimal(unsigned int n);
int		print_hex_uppercase(unsigned int nbr);
int		print_hex_lowercase(unsigned int nbr);
int		print_format_and_vars(const char *format, va_list arg_var);

#endif