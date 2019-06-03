CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = fillit
SRCDIR = ./
INCLDIR = ./
SRCS = $(SRCDIR)main.c $(SRCDIR)check_square.c $(SRCDIR)check_square2.c \
		$(SRCDIR)fillit.c $(SRCDIR)full_square.c $(SRCDIR)check_hole.c\
		$(SRCDIR)full_square2.c $(SRCDIR)remove_square.c $(SRCDIR)utilitys.c \
		$(SRCDIR)do_i_fillit.c $(SRCDIR)count_island.c \
		$(SRCDIR)check_count_island.c $(SRCDIR)init.c \
		$(SRCDIR)check_count_island2.c
OBJS_ = $(SRCS:.c=.o)
OBJS = $(notdir $(OBJS_))

all : $(NAME)

$(NAME) : $(SRCS)
	@make $(OBJS)
	@$(CC) $(CFLAGS) -I $(INCLDIR) $^ -o $@
	@echo "\n\033[36mCreation :\033[0m \033[35;4m$(NAME)\033[0m\n"

%.o : %.c
	@$(CC) $(CFLAGS) -c -I $(INCLDIR) $^
	@echo "\033[36mCompilation :\033[0m \033[32m$*\033[0m"

clean :
	@rm -rf $(OBJS)
	@echo "\n\033[36mDeletion :\033[0m \033[32mObjects\033[0m\n"

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[36mDeletion :\033[0m \033[35;4m$(NAME)\033[0m\n"

re : fclean all
