# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hilyas <hilyas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/11 14:49:58 by hilyas            #+#    #+#              #
#    Updated: 2026/01/20 22:21:21 by hilyas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_putadress.c ft_putchar.c ft_puthexnbr.c ft_putnbr.c ft_putstr.c ft_putunsigned.c

OBJS = ${SRC:.c=.o}
CC = cc 
CFLAGS=-Wall -Wextra -Werror

all : $(NAME)

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f ${OBJS} 
	
fclean: clean
	rm -f ${NAME}

re: fclean all
