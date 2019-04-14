/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:34:46 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/14 22:24:29 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdlib.h>
#include <unistd.h> // for system call write
#include <fcntl.h> // for system call open
#include <string.h> // for memmove and strlen
#include <stdio.h> // for debug printf
#include <stdbool.h> // to use bool type

# define BUFFER_SIZE 1024

/*
**	DELETE BEFORE EVALUATION
*/

void	print_test(char *test);

/*
**	FUNCTIONS
*/

char	*read_file(char *file);
void	print_error(char *s, int fd);
int		ft_file_errors(char *file);

typedef struct			s_fillist
{
	int					id;
	char				**tetraminos;
	int					position[2];
	int					size[2];
	int					area;
	struct s_fillist	*next;
}						t_fillist;

#endif
