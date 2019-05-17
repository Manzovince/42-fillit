# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/01 13:24:35 by vmanzoni          #+#    #+#              #
#    Updated: 2019/05/17 17:11:53 by hulamy           ###   ########.fr        #
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

TRASH = $(shell find . -depth 1 -name '*.dSYM')
TRASH += $(shell find . -depth 1 -type f -name '*.o')
TRASH += $(shell find . -depth 1 -type f -name '*.swp')
TRASH += $(shell find . -depth 1 -type f -name '*.swo')
TRASH += $(shell find . -depth 1 -type f -name '*.swn')

# - - - - - - - - - - - - - - - #
#          RULES                #
# - - - - - - - - - - - - - - - #

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(SRCS) -o $(NAME)

debug: $(SRCS)
	$(CC) -g $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(SRCS) -o $(NAME)

lib:
	make -C ./libft/

clean:
	/bin/rm -rf $(TRASH)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
