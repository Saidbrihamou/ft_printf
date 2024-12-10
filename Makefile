SRCS =  SRCS/ft_printf.c SRCS/ft_strlen.c SRCS/print_decimal_or_integer.c SRCS/print_pointer_in_hex.c \
		SRCS/print_single_char.c SRCS/print_string.c SRCS/print_unsigned_decimal.c SRCS/print_hex_lower.c \
		SRCS/print_hex_upper.c SRCS/print_format_and_vars.c

SRCS_BONUS 	= 	BONUS/ft_printf_bonus.c BONUS/ft_strlen_bonus.c BONUS/print_decimal_or_integer_bonus.c \
				BONUS/print_format_and_vars_bonus.c BONUS/print_hex_lower_bonus.c BONUS/print_hex_upper_bonus.c \
				BONUS/print_pointer_in_hex_bonus.c BONUS/print_single_char_bonus.c BONUS/print_string_bonus.c \
				BONUS/print_unsigned_decimal_bonus.c BONUS/ft_isdigit_is_flags_bonus.c \
				BONUS/ft_atoi_bonus.c BONUS/flags_print_bonus.c BONUS/count_print_bonus.c BONUS/count_print2_bonus.c \
				BONUS/print_n_char_bonus.c BONUS/putnstr_bonus.c BONUS/print_mod_bonus.c \
				BONUS/flags_print3_bonus.c BONUS/flags_print2_bonus.c 

OBJS 		= ${SRCS:.c=.o}
OBJS_BONUS  = ${SRCS_BONUS:.c=.o}
FLAG		= -Wall -Wextra -Werror
NAME 		= libftprintf.a


all: ${NAME}

$(NAME): ${OBJS}
			ar rcs ${NAME} ${OBJS}

bonus: ${OBJS_BONUS} createlib

createlib:
		@rm -f ${NAME}
		ar rcs ${NAME} ${OBJS_BONUS}
	
SRCS/%.o:SRCS/%.c SRCS/ft_printf.h ft_printf.h
	cc ${FLAG} -c $< -o ${<:.c=.o}

BONUS/%.o:BONUS/%.c BONUS/ft_printf_bonus.h ft_printf.h
	cc ${FLAG} -c $< -o ${<:.c=.o}

clean:
		rm -f ${OBJS_BONUS} ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all
