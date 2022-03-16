# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yatilla <yatilla@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 12:42:06 by yatilla           #+#    #+#              #
#    Updated: 2022/03/16 12:12:34 by yatilla          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a

SRCS = ft_printf.c ft_putchar.c ft_printptr.c ft_printstr.c ft_putnbr.c\
	   ft_print_unsign.c ft_printhex.c


OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = gcc

RM = rm -f

all: $(NAME)
	@ECHO "\033[0;91m\nProgram checking..."

$(NAME): $(OBJS)
	@echo "\033[0;93m"
	ar rc $(NAME) $(OBJS)

clean:
	@echo "$(GREEN)Loading..."
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: clean re fclean all




