# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egjika <egjika@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/10 00:58:33 by egjika            #+#    #+#              #
#    Updated: 2025/09/10 00:58:33 by egjika           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_unsigned.c ft_puthex.c ft_puthexa.c ft_putptr.c
OBJ = $(SRC:.c=.o)
HEADER = printf.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
    ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
