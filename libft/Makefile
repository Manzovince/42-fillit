# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hulamy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/03 21:52:28 by hulamy            #+#    #+#              #
#    Updated: 2019/06/03 21:52:33 by hulamy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -I.

SRCS = ft_isdigit.c ft_memccpy.c ft_putnbr.c ft_strcpy.c ft_strmapi.c ft_strsub.c \
	   ft_any.c ft_isprint.c ft_memchr.c ft_putnbr_fd.c ft_strdel.c ft_strmultisplit.c ft_strtrim.c \
	   ft_arraymap.c ft_issort.c ft_memcmp.c ft_putnbrbase.c ft_strdup.c ft_strncat.c ft_tolower.c \
	   ft_atoi.c ft_itoa.c ft_memcpy.c ft_putnbrendl.c ft_strequ.c ft_strncmp.c ft_toupper.c \
	   ft_atoibase.c ft_lstadd.c ft_memdel.c ft_putnbrendl_fd.c ft_striter.c ft_strncpy.c \
	   ft_bzero.c ft_lstdel.c ft_memmove.c ft_putstr.c ft_striteri.c ft_strnequ.c \
	   ft_convertbase.c ft_lstdelone.c ft_memset.c ft_putstr_fd.c ft_strjoin.c ft_strnew.c \
	   ft_foreach.c ft_lstiter.c ft_putchar.c ft_strcat.c ft_strjoinfree.c ft_strnstr.c \
	   ft_isalnum.c ft_lstmap.c ft_putchar_fd.c ft_strchr.c ft_strlcat.c ft_strrchr.c \
	   ft_isalpha.c ft_lstnew.c ft_putendl.c ft_strclr.c ft_strlen.c ft_strsplit.c \
	   ft_isascii.c ft_memalloc.c ft_putendl_fd.c ft_strcmp.c ft_strmap.c ft_strstr.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	@gcc $(CFLAGS) -c $(SRCS)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

