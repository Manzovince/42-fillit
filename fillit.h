/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:34:46 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/13 17:56:19 by vmanzoni         ###   ########.fr       */
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
	char				letter;
	uint64_t			memory;
	struct s_fillist	*same;
	struct s_fillist	*next;
}						t_fillist;

/*
**	FUNCTIONS
*/

char	*read_file(char *file);
void	print_error(char *s);
void	print_error_extended(int error);
void    parse_input(char *input);
int		check_file_errors(char *file);
int		check_tetri_errors(char *tetri);
int		check_tetri_errors_proxy(char *tetri);
int		add_to_list(char *square, t_fillist **list, char letter);
void    fill_list(char line[], t_fillist *list);
void    print_bits(unsigned int bits, int size); //TO DELETE BEFORE EVAL
void    print_tetri(unsigned int bits, int size); //TO DELETE BEFORE EVAL
void	search_map(t_fillist *list);
void	print_map(unsigned int *tab, int width, int height, char letter);
void    print_final_map(t_fillist *list, int size);
void	ft_put_tetri_color(char c);

#endif
