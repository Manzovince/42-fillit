# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/01 13:24:35 by vmanzoni          #+#    #+#              #
#    Updated: 2019/04/24 15:44:55 by hulamy           ###   ########.fr        #
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

SRCS = $(shell find . -depth 1 -type f -not -name '.*' -not -name 'test*' -name '*.c')


# - - - - - - - - - - - - - - - #
#          RULES                #
# - - - - - - - - - - - - - - - #

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(SRCS) -o $(NAME)

debug:
	$(CC) -g $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(SRCS) -o $(NAME)

lib:
	make -C ./libft/

clean:
	/bin/rm -rf $(NAME)
	/bin/rm -rf $(NAME).dSYM

re: clean all
