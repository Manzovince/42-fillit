# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/01 13:24:35 by vmanzoni          #+#    #+#              #
#    Updated: 2019/06/01 16:57:51 by hulamy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# - - - - - - - - - - - - - - - #
#          VARIABLES            #
# - - - - - - - - - - - - - - - #

NAME = fillit
CC = gcc

CFLAGS = -I.
CFLAGS += -Wall -Wextra -Werror

LDFLAGS = -L./libft/
LDLIBS = -lft

SRCS = main.c \
	   f_bonus_opti.c \
	   f_bonus_print.c \
	   f_handle_errors.c \
	   f_parse_input.c \
	   f_print.c \
	   f_print_map_with_colors.c \
	   f_read_file.c \
	   f_search_map.c

OBJS = $(SRCS:.c=.o)

# - - - - - - - - - - - - - - - #
#          RULES                #
# - - - - - - - - - - - - - - - #

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft/
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(SRCS) -o $(NAME)

clean:
	make clean -C libft/
	/bin/rm -rf $(OBJS)

fclean: clean
	make fclean -C libft/
	/bin/rm -rf $(NAME)

re: fclean all
