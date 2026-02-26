# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egjika <egjika@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/28 17:11:17 by egjika            #+#    #+#              #
#    Updated: 2026/01/28 17:11:34 by egjika           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk
NAME_SERVER	= server
NAME_CLIENT	= client

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR	= ft_printf
FT_PRINTF	= $(FT_PRINTF_DIR)/libftprintf.a

INCLUDES	= -I. -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

SRCS_SERVER	= server.c
SRCS_CLIENT	= client.c

OBJS_SERVER	= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT	= $(SRCS_CLIENT:.c=.o)

all: $(LIBFT) $(FT_PRINTF) $(NAME_SERVER) $(NAME_CLIENT)

$(NAME): all

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) $(FT_PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) $(FT_PRINTF) -o $(NAME_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus $(NAME)
