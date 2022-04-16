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
	$Sdraw.c \
	$Sutility.c \
	$Slineclip.c \
	$Scolor.c

HDR = $Sfdf.h

OBJ = $(SRC:%.c=%.o)

LIBFT = libft/
LIBA = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -lX11 -lXext -framework OpenGL -framework AppKit

RM = /bin/rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -I /usr/X11/include -L /usr/X11/lib $(MLXFLAGS) -o $@ \
	$(CFLAGS) $(OBJ) $(LIBA)

$(LIBA):
	make -C $(LIBFT)

%.o: %.c $(LIBA) $(HDR)
	gcc $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

