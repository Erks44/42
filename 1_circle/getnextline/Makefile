# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egjika <egjika@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/14 22:30:22 by egjika            #+#    #+#              #
#    Updated: 2025/10/15 16:54:31 by egjika           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= get_next_line.a
SRC			= get_next_line.c get_next_line_utils.c
OBJ			= $(SRC:.c=.o)
HEADER		= get_next_line.h

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus:
	@$(CC) $(CFLAGS) -c get_next_line_bonus.c get_next_line_utils_bonus.c
	@ar rcs get_next_line_bonus.a get_next_line_bonus.o get_next_line_utils_bonus.o

.PHONY: all clean fclean re bonus