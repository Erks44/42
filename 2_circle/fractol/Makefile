# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: errikosgjika <errikosgjika@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/23 17:38:58 by errikosgjik       #+#    #+#              #
#    Updated: 2026/01/25 13:51:28 by errikosgjik      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = \
	src/main.c \
	src/parse_args.c \
	src/print_usage.c \
	src/init_defaults.c \
	src/init_mlx.c \
	src/put_pixel.c \
	src/mandelbrot.c \
	src/ft_atod.c \
	src/events.c \
	src/julia.c \
	src/cleanup.c \
	src/color.c \
	src/zoom.c \
	src/mapping.c

OBJS = $(SRCS:.c=.o)

UNAME_S := $(shell uname -s)

# -------- MLX (OS switch) --------
ifeq ($(UNAME_S),Darwin)
	MLX_DIR = mlx
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lz
else
	MLX_DIR = mlx_linux
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
endif

# -------- libft --------
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I. -I$(MLX_DIR) -I$(LIBFT_DIR)
LIBS = $(MLX_FLAGS) -L$(LIBFT_DIR) -lft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
