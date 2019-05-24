/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:34:46 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/24 18:04:17 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdlib.h>
#include <unistd.h> // for system call write
#include <fcntl.h> // for system call open
#include <stdbool.h>
#include <stdio.h> // for printf (DELETE BEFORE EVAL)

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
	unsigned int		*memory;
	struct s_fillist	*same;
	struct s_fillist	*next;
}						t_fillist;

/*
**	main.c
*/
int		main(int argc, char **argv);
int		*create_dope(char *av);
int		is_mdp(int ac, char **av);

/*
**	read_file.c
*/
char	*read_file(char *file);

/*
**	handle_errors.c
*/
void	print_error(char *s);
void	print_error_extended(int error, int *dope);
int		check_file_errors(char *file, int *dope);
int		check_tetri_errors(char *tetri);
int		check_tetri_errors_proxy(char *tetri);

/*
**	handle_errors.c
*/
int	    parse_input(char *input, t_fillist **list, int *dope);
int		add_to_list(char *square, t_fillist **list, char letter);
void    fill_list(char line[], t_fillist *list);
unsigned short	reduce_tetri(unsigned short tetri, int width);
unsigned short	tab_to_bin(char line[]);

void    print_bits(unsigned int bits, int size); //TO DELETE BEFORE EVAL
void    print_tetri(unsigned int bits, int size); //TO DELETE BEFORE EVAL
int		search_map(t_fillist *list);
void	print_map(unsigned int *tab, int width, int height, char letter);
void    print_final_map(t_fillist *list, int size, int flag);
void	ft_put_tetri_color(char c);
int		check_tetri_memory(t_fillist *list, int pos);
void	remove_tetri_memory(t_fillist *list, int pos);
int		check_same_tetri(t_fillist *list, int num);
int		compare_tetri(t_fillist *tetri_a, t_fillist *tetri_b);

#endif
