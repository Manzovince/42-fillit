# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/01 13:24:35 by vmanzoni          #+#    #+#              #
#    Updated: 2019/04/16 16:39:00 by vmanzoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

OBJ_DIR	=	objs./
HEADER	=	fillit.h

SRCS	=	*.c
OBJS	=	$(SRCS:.c=.o)
LIB		=	libft/

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -rf

all:	$(NAME)

$(NAME):
	make -C libft/
	$(CC) $(CFLAGS) -I$(HEADER) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS) -L $(LIB) -lft
	mkdir $(OBJ_DIR)
	mv $(OBJS) $(OBJ_DIR)

clean:
	make -C libft/ clean
	$(RM) $(OBJ_DIR)

fclean:	clean
	make -C libft/ fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
