/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:34:46 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/28 12:15:39 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

#include "libft/includes/libft.h"

/*
** DEFINE
*/

# define BUFF_SIZE 1024

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define RESET "\x1B[0m"

//#define RED   "\e[41m"
//#define GRN   "\e[42m"
//#define YEL   "\e[43m"
//#define BLU   "\e[44m"
//#define MAG   "\e[45m"
//#define CYN   "\e[46m"
//#define RESET "\e[49m"

/*
**	STRUCTURE
** tetribit : tetri ecrit en binaire dans un short de 16 bits
** width : largeur du tetri
** height : hauteur du tetri
** position : memorise la position d tetri bit a bit
** place : position sur l'axe des abscisses de la map (position % size)
** rank : position de 1 a 32 dans l'int du tableau d'int (position % 32)
** num : memorise dans quel int du tableau on se trouve (position / 32)
** total_num : le nombre d'int dans le tableau d'int
** test :
** letter :
** dope :
** memory :
** same :
** next :
** start :
*/
typedef struct			s_fillist
{
	unsigned short		tetribit;
	int					width;
	int					height;
	int					position;
	int					place;
	int					rank;
	int					num;
	int					test;
	char				letter;
	int					*dope;
	unsigned int		*memory;
	struct s_fillist	*same;
	struct s_fillist	*next;
	struct s_fillist	*start;
}						t_fillist;

/*
**	bonus_print.c
*/
t_fillist		*print_tetri(t_fillist *list);
int				print_binary_map(unsigned int *map, int size, int *dope);
int				print_flags_usage(void);

/*
**	bonus_opti.c
*/
int				check_same_tetri(t_fillist *list, int num);
int				compare_tetri(t_fillist *tetri_a, t_fillist *tetri_b);
int				check_tetri_memory(t_fillist *list, int pos);

/*
**	main.c
*/
int				main(int argc, char **argv);
int				*create_dope(char *av, int mdp);
int				is_mdp(int ac, char **av);

/*
**	read_file.c
*/
char			*read_file(char *file);

/*
**	handle_errors.c
*/
void			print_error(char *s);
void			print_error_extended(int error, int *dope);
void			check_file_errors(char *file, int *dope);
int				check_tetri_errors(char *tetri);
int				check_tetri_errors_proxy(char *tetri);

/*
**	parse_input.c
*/
int			    parse_input(char *input, t_fillist **list, int *dope);
int				add_to_list(char *sqr, t_fillist **lst, char lett, int *dope);
void		    fill_list(char line[], t_fillist *list);
unsigned short	reduce_tetri(unsigned short tetri, int width);
unsigned short	tab_to_bin(char line[]);

/*
**	search_map.c
*/
unsigned int	fit_in_place(unsigned int *map, t_fillist *lst, int siz, int i);
int				find_place(unsigned int *map, t_fillist *list, int size);
void			add_remove(unsigned int *map, t_fillist *list, int size);
int				fill_map(unsigned int *map, t_fillist *list, int size);
int				search_map(t_fillist *list);

/*
**	print.c
*/
void			print_sized_map(unsigned int *tab, int width, int height, char letter);
char			*init_print_map(t_fillist *list, int size);
void			print_letter_map(t_fillist *list, int size, int flag);
void		    print_final_map(t_fillist *list, int size);

<<<<<<< HEAD
char	*read_file(char *file);
void	print_error(char *s);
void	print_error_extended(int error);
int	    parse_input(char *input, t_fillist **list);
int		check_file_errors(char *file);
int		check_tetri_errors(char *tetri);
int		check_tetri_errors_proxy(char *tetri);
int		add_to_list(char *square, t_fillist **list, char letter);
void    fill_list(char line[], t_fillist *list);
void    print_bits(unsigned int bits, int size);
void    print_tetri(unsigned int bits, int size);
int		search_map(t_fillist *list);
void	print_map(unsigned int *tab, int width, int height, char letter);
void    print_final_map(t_fillist *list, int size, int flag);
=======
>>>>>>> master
void	ft_put_tetri_color(char c);

#endif
