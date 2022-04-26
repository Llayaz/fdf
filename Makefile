# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 13:43:12 by ncsomori          #+#    #+#              #
#    Updated: 2022/03/09 13:43:15 by ncsomori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

S = src/

SRC = $Smain.c \
	$Sreader.c \
	$Sparse.c \
	$Skey.c \
	$Skey2.c \
	$Sdraw.c \
	$Sutility.c \
	$Sutility2.c \
	$Slineclip.c \
	$Scolor.c \
	$Sexit.c \
	$Srotate.c

HDR = $Sfdf.h

OBJ = $(SRC:%.c=%.o)

LIBFT = libft/
LIBA = libft/libft.a
MLX = $(MLX_DIRECTORY)libmlx.a
MLX_DIRECTORY = ./mlx/

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Wconversion -O3
MLXFLAGS = -lmlx -lX11 -lXext -framework OpenGL -framework AppKit

RM = /bin/rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -I /usr/X11/include -L /usr/X11/lib $(MLXFLAGS) -o $@ \
	$(CFLAGS) $(OBJ) $(LIBA) $(MLX)

$(LIBA):
	make -C $(LIBFT)

$(MLX):
	make -C $(MLX_DIRECTORY)

%.o: %.c $(LIBA) $(MLX) $(HDR)
	gcc $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT) clean
	make -C $(MLX_DIRECTORY) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean
	$(RM) $(MLX)

re: fclean all
