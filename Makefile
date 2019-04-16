# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/01 13:24:35 by vmanzoni          #+#    #+#              #
#    Updated: 2019/04/15 20:17:47 by vmanzoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

OBJ_DIR	=	objs/
HEADER	=	includes/

SRCS	=	*.c
OBJS	=	$(SRCS:.c=.o)
LIB	=	fillit.h

CC	=	gcc
CFLAGS	=	-Wall -Werror -Wextra

RM	=	rm -rf

all:	$(NAME)

$(NAME):
	make -C libft/
	$(CC) $(CFLAGS) -I$(HEADER) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS) -L libft/ -lft
	#$(CC) $(CFLAGS) -I$(HEADER) -c $(addprefix $(SRC_DIR), $(SRCS))
	#$(CC) $(OBJS) -o $(NAME)
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
