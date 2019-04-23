/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:34:46 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/23 14:25:15 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdlib.h>
#include <unistd.h> // for system call write
#include <fcntl.h> // for system call open
#include <stdio.h> // for printf (DELETE BEFORE EVAL)

#include "libft/includes/libft.h"

/*
**	STRUCTURE
*/

typedef struct			s_fillist
{
	short				tetribit;
	short				tibirtet;
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
int		add_to_list(char *square, t_fillist **list);
int		fill_list(char *line, t_fillist *list);

#endif
