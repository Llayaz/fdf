# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 15:04:07 by ncsomori          #+#    #+#              #
#    Updated: 2021/11/03 15:04:35 by ncsomori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = 	./ft_atoi.c		\
	./ft_bzero.c		\
	./ft_free_arr.c		\
	./ft_isalpha.c		\
	./ft_isalnum.c		\
	./ft_isascii.c		\
	./ft_isblank.c		\
	./ft_iscntrl.c		\
	./ft_isdigit.c		\
	./ft_islower.c		\
	./ft_isprint.c		\
	./ft_isspace.c		\
	./ft_isupper.c		\
	./ft_isxdigit.c		\
	./ft_itoa.c			\
	./ft_lstadd.c		\
	./ft_lstadd_back.c	\
	./ft_lstiter.c		\
	./ft_lstmap.c		\
	./ft_lstnew.c		\
	./ft_lstdel.c		\
	./ft_lstdelone.c	\
	./ft_lstlast.c		\
	./ft_lstsize.c		\
	./ft_memalloc.c		\
	./ft_memccpy.c		\
	./ft_memchr.c		\
	./ft_memcmp.c		\
	./ft_memcpy.c		\
	./ft_memdel.c		\
	./ft_memmove.c		\
	./ft_memset.c		\
	./ft_putchar.c		\
	./ft_putchar_fd.c	\
	./ft_putendl.c		\
	./ft_putendl_fd.c	\
	./ft_putnbr.c		\
	./ft_putnbr_fd.c	\
	./ft_putstr.c		\
	./ft_putstr_fd.c	\
	./ft_strcat.c		\
	./ft_strchr.c		\
	./ft_strclr.c		\
	./ft_strcpy.c		\
	./ft_strcmp.c		\
	./ft_strdel.c		\
	./ft_strdup.c		\
	./ft_strequ.c		\
	./ft_striter.c		\
	./ft_striteri.c		\
	./ft_strjoin.c		\
	./ft_strlcat.c		\
	./ft_strlen.c		\
	./ft_strmap.c		\
	./ft_strmapi.c		\
	./ft_strncat.c		\
	./ft_strncmp.c		\
	./ft_strnew.c		\
	./ft_strnequ.c		\
	./ft_strncpy.c		\
	./ft_strnlen.c		\
	./ft_strnstr.c		\
	./ft_strrchr.c		\
	./ft_strstr.c		\
	./ft_strtrim.c		\
	./ft_strsplit.c		\
	./ft_strsub.c		\
	./ft_tolower.c		\
	./ft_toupper.c		\
	./ft_word_count.c	\
	./get_next_line.c	\
	./ft_abs.c			\
	./ft_abs_f.c

HDRS = libft.h

OBJECTS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	gcc -c -Wall -Wextra -Werror $(SRCS) $(HDRS)
	ar rc $(NAME) $(OBJECTS)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
