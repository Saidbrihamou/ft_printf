/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:06:33 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/11/15 15:42:13 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

int		print_string(char *str);
size_t	ft_strlen(char *str);
int		print_decimal_or_integer(int n);
int		print_char(char c);
int		print_mod(void);
int		print_pointer_in_hex(void *p);
int		recursive_print_hex(void *p, const char *hex);
int		print_unsigned_decimal(unsigned int n);
int		print_hex_uppercase(unsigned int nbr);
int		print_hex_lowercase(unsigned int nbr);
int		print_format_and_vars(const char *format, va_list arg_var);
int		print_in_your_format(va_list arg_var, char c);
typedef struct s_flags
{
	int	whith;
	int	add;
	int	subtract;
	int	zero;
	int	point;
	int	ispoint;
	int	hash;
	int	space;
}	t_flags;

int		isflags(char c);
int		ft_isdigit(int c);
int		isformat(char c);
int		ft_atoi(const char *str, int *i);
t_flags	*get_flags_list(const char *format, va_list \
						arg_var, int *i, t_flags *var_flags);
t_flags	*get_new_var_flags(void);
int		hash(const char *format, int *i, va_list arg_var, t_flags *flags);
int		space(const char *format, int *i, va_list arg_var, t_flags *flags);
int		add(const char *format, int *i, va_list arg_var, t_flags *flags);
int		width(const char *format, int *i, va_list arg_var, t_flags *flags);

int		count_print_var(va_list arg_var, char format);
int		count_unsigned_decimal(unsigned int n);
int		count_decimal_or_integer(int n);
int		recursive_count_hex(void *p, const char *hex);
int		count_char(void);
int		count_string(const char *str);
int		count_hex(unsigned int i);
int		count_pointer(void *p);
int		count_n_char(int n);
int		count_putnstr(char *str, int n);
int		count_mod(void);

int		print_n_char(char c, int n);
int		putnstr(char *str, int n);
int		left_aligns(const char *format, int *i, \
					va_list arg_var, t_flags *flags);
int		right_alings(const char *format, int *i, \
					va_list arg_var, t_flags *flags);
int		right_alings_part2(const char *format, \
				int *i, va_list arg_var, t_flags *flags);

int		count_and_cheakzero(va_list arg_copy, \
					char format, t_flags *flags);
int		print_and_cheakzero(va_list arg_var, \
				char format, t_flags *flags);
int		pint_integer_and_cheak_singe(va_list arg_var, \
					t_flags *flags, int count_len_var);
int		count_and_cheakzero_for_prec(va_list arg_copy, \
						char format, t_flags *flags);
int		print_intege_and_min_int(int n);
void	cheak_is_width_negative(t_flags *flags);

#endif