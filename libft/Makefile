##
# # ------------------------------------------------------
# # utiliser le makefile pour creer une librairie statique
# # ------------------------------------------------------
##
##
## - - - - - - - -
## compiler des .o
## - - - - - - - -
##
##
## quand on ecrit un programme il contient un main et les
## fonctions dont le main a besoin (ex ft_putchar) :
##
### #include <unistd.h>
###
###	void	ft_putchar(char c)
###	{
###		write(1, &c, 1);
###	}
###
### int		main()
### {
###		ft_putchar('0');
###		return (0);
###	}
##
## on peut compiler ce fichier avec gcc en faisant :
## gcc file.c
## et ca sort un executable a.out
## si on l'execute "./a.out" ca ecrit 0 dans la console
##
## mais pour ne pas reecrire a chaque fois ft_putchar
## on peut la mettre dans une librairie qu'on inclue dans
## le fichier qui l'utilise...
## si on sort ft_putchar du fichier :
##
### int		main()
### {
###		ft_putchar('0');
###		return (0);
###	}
##
## et qu'on l'execute "gcc file.c" on va avoir une erreur
## car file.c utilise ft_putchar mais gcc ne sait pas ce
## que c'est, donc il faut qu'on le rajoute a la compilation
## on peut par exemple l'ecrire dans un fichier ft_putchar.c
##
### #include <unistd.h>
###
###	void	ft_putchar(char c)
###	{
###		write(1, &c, 1);
###	}
##
## et compiler les deux :
## gcc file.c ft_putchar.c
##
## ca fonctionne mais gcc doit a chaque fois recompiler
## ft_putchar.c alors qu'il n'est pas modifie, donc on peut
## le compiler une bonne fois pour toute et le rajouter a la
## compilation finale quand on en a besoin sans que l'ordi
## ait a tout retraduire dans son langage
##
## mais si on essaye de compiler ft_putchar seul
## gcc ft_putchar.c
## ca nous donne une erreur car pour compiler, gcc a besoin
## de trouver un main !
##
## on va donc utiliser l'option -c pour
## creer une fichier objet .o qui est deja traduit en langue
## d'ordinateur et pret a etre rajoute a la compilation :
## gcc -c ft_putchar.c --> donne ft_putchar.o
## qu'on peut compiler avec le fichier qui contient le main :
##
## gcc file.c ft_putchar.o
##
## on a nos bouts de codes comme ft_putchar.o dans des fichiers
## objets prets a etre ajoutes a la compilation du main
##
## on va maintenant voir comment faire une libraire qui contien
## tous nos fichiers objets
##
##
## - - - - - - - -
## creer une lib.a
## - - - - - - - -
##
##
## pour mettre tous les fichiers .o dans un seul fichier .a
## on utilise un programme d'archive ar avec les options rc
## r indique d'inserer les .o en remplacant si necessaire
## c de creer une nouvelle archive
## le nom de l'archive doit commencer par lib et finir en .a :
## ar rc nom_de_l'archive fichier_1.o fichier_2.o etc
##
## ar rc libtest.a ft_putchar.o
##
## on obtient un fichier libtest.a qui contient les fichiers
## objets .o
##
## on peut l'utiliser a la compilation de cette manniere :
##
## gcc file.c -L. -ltest
##
## -L indique ou est la librairie (ici elle est dans le
## dossier courant .)
## -l indique son nom ("test" car on n'indique pas lib et .a)
##
##
# # -----------------------------------------------
# # ecrire un make file pour aider a la compilation
# # -----------------------------------------------
##
##
## exemple d'un makefilede basic
##
### NAME = libtest.h
### CC = gcc
### CFLAGS = -I. -c
### SRCS = example01.c \
###        example02.c
### OBJ = $(SRCS:.c=.o)	|ecrit les fichiers .c en .o
### 
### all: $(NAME)				|make execute sa premiere regle NAME
### $(NAME): $(OBJ)				|NAME execute d'abord OBJ
### 	ar -rc $@ $<			|
##
## Make a des built-in pattern rules :
## https://www.gnu.org/software/make/manual/html_node/Catalogue-of-Rules.html
## par exemple pour construire des .o a partir de .c
## qui sont utilisees par défaut si les variables
## sont bien nomee (genre CC ou CFLAGS)
##
## cependant si on veut mettre les fichiers .o dans un
## sous-fichier BUILDS il n'y a pas de built-in pattern
## il faut donc l'ecrire nous-meme :
##
### NAME = libtest.h
### CC = gcc
### CFLAGS = -I.
### SRCS = example01.c \
###        example02.c
### ODIR = ./builds
### OBJS = $(addprefix $(ODIR)/, $(SRCS:.c=.o))
### 
### all: $(NAME)
### $(NAME): $(OBJS)
### 	ar -rc $@ $<
###
### $(ODIR)/%.o : %.c
###		$(COMPILE.c) -o $@ $<
##
## cette regle est appellee par $(OBJS) puisque
## cette variable appelle la regle $(ODIR/file.o)
##
## COMPILE est une built-in variable qui execute
## les regles CC et CFLAGS avec l'option -c
##
## %   = "tout"
## $@  = "la valeur a gauche de :"
## $<  = "la premiere valeur a droite de :"
## $^  = "toutes les valeurs a droite de :"
##
##


# ----------------------------------------------------------- #
#                                                             #
# variables modifiables                                       #
#                                                             #
# ----------------------------------------------------------- #

NAME = libft.a

DEPS = libft.h

SDIR = ./src
ODIR = ./build
IDIR = ./includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(IDIR)


# ----------------------------------------------------------- #
#                                                             #
# ne pas modifier en dessous                                  #
#                                                             #
# ----------------------------------------------------------- #

## SUB_SDIR sera utilise pour creer les sous dossiers :
## avec mkdir -p ODIR/subdir1 ODIR/subdir2 ODIR/subdir3 etc...
## find $(SDIR) cherche recursivement tous le contenu de SDIR
## -type d ne trouve que les dossiers, pas les fichiers
## -mindepth 1 ne liste pas le dossier SDIR
## subst transform arg1 en arg2 dans arg3

SUB_SDIR = $(shell find $(SDIR) -mindepth 1 -type d)
SRC = $(shell find $(SDIR) -type f -not -name '.*' -name '*.c')
OBJ = $(subst $(SDIR), $(ODIR), $(SRC:.c=.o))

all: $(ODIR) $(NAME)

$(ODIR):
	mkdir -p $(subst $(SDIR), $(ODIR), $(SUB_SDIR))

$(ODIR)/%.o: $(SDIR)/%.c
	$(COMPILE.c) -o $@ $<

$(NAME): $(OBJ)
	ar -rc $@ $^
	@ranlib $@

clean:
	/bin/rm -rf $(ODIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean
