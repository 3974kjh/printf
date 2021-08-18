# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jukim <jukim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/19 21:21:14 by jukim             #+#    #+#              #
#    Updated: 2021/06/22 15:15:34 by jukim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

NAME = libftprintf.a
SOURCE = ./ft_printf.c \
		 ./ft_printf_ads.c \
		 ./ft_printf_char.c \
		 ./ft_printf_hexu.c \
		 ./ft_printf_int.c \
		 ./ft_printf_pasor.c \
		 ./ft_printf_settings.c \
		 ./ft_printf_str.c \
		 ./ft_printf_utils.c \
		 ./ft_check_zero.c \
		 ./ft_puthex.c \
		 ./ft_puthex_long.c \
		 ./ft_itoa.c
OBJECTS = $(SOURCE:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME) : $(OBJECTS)
	ar rcs $@ $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
