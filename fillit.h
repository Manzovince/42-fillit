/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:34:46 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/25 16:41:29 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdlib.h>
#include <unistd.h> // for system call write
#include <fcntl.h> // for system call open
#include <stdio.h> // for printf (DELETE BEFORE EVAL)

#include "libft/includes/libft.h"
# define BUFF_SIZE 1024

/*
**	STRUCTURE
*/

typedef struct			s_fillist
{
	unsigned short		tetribit;
	int					large;
	int					height;
	int					position;
	struct s_fillist	*next;
}						t_fillist;

/*
**	FUNCTIONS
*/

char	*read_file(char *file);
void	print_error(char *s);
void	parse_input(char *input);
int		check_file_errors(char *file);
int		check_tetri_errors(char *tetri);
int		check_tetri_errors_proxy(char *tetri);

#endif
