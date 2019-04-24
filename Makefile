# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/01 13:24:35 by vmanzoni          #+#    #+#              #
#    Updated: 2019/04/23 15:16:05 by vmanzoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

OBJ_DIR	=	./objs
HEADER	=	fillit.h

SRCS	=	main.c					\
			read_file.c				\
			handle_errors.c			\
			parse_input.c			\
			add_to_list.c			\
#			get_smallest_square.c	\
			print_fillit.c


OBJS	=	$(SRCS:.c=.o)
LIB		=	libft/

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -rf

all:	$(NAME)

$(NAME):
	make -C $(LIB)
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
