# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/01 13:24:35 by vmanzoni          #+#    #+#              #
#    Updated: 2019/04/12 22:33:31 by vmanzoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

SRC_DIR	=	srcs/

SRCS	=	*.c

OBJ_DIR	=	objs/

OBJS	=	$(SRCS:.c=.o)

HEADER	=	includes/

LIB	=	fillit.h

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM	=	rm -f

all:	$(NAME)

$(NAME)
	$(CC) $(CFLAGS) -I$(HEADER) -c $(addprefix $(SRC_DIR), $(SRCS))
	$(CC) $(OBJS) -o $(NAME)
	mkdir $(OBJ_DIR)
	mv *.o $(OBJ_DIR)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
