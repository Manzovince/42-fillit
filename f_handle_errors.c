/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handle_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:29:05 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/06/01 19:44:08 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function that display error message *s on fd and exit program
*/

void	print_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(0);
}

/*
** Function that display error message *s on fd with more informations
*/

void	print_error_extended(int error, int *dope)
{
	if (!dope[3])
		print_error("error\n");
	if (error == 1)
		print_error("error: File contains char other than '.','#' and '\\n'\n");
	if (error == 2)
		print_error("error: File contains two tetriminos not"
					"separated by a '\\n'\n");
	if (error == 3)
		print_error("error: File contains more than 2 '\\n' in a row\n");
	if (error == 4)
		print_error("error: File contains less than 1 tetrimino\n");
	if (error == 5)
		print_error("error: File contains more than 26 tetriminos\n");
	if (error == 6)
		print_error("error: Tetrimino has more or less than 4 #\n");
	if (error == 7)
		print_error("error: Tetrimino # are not all connected\n");
	print_error("error\n");
}

/*
** Function to see if there if an error if the file
** - less than 4 lines
** - more than 104 (26 tetri) + 25 (\n) = 129 lines
** - two \n in a row
*/

void	check_file_errors(char *file, int *dope)
{
	int		i;
	int		line_nbr;

	i = 0;
	line_nbr = 0;
	while (file[i])
	{
		if (file[i] != '.' && file[i] != '#' && file[i] != '\n')
			print_error_extended(1, dope);
		else if (file[i] == '\n')
			line_nbr++;
		if (file[i] == '\n' && line_nbr % 5 == 0 && file[i - 1] != '\n')
			print_error_extended(2, dope);
		if (file[i] == '\n' && file[i + 1] != '\0' && \
			file[i + 2] != '.' && file[i + 2] != '#')
			print_error_extended(3, dope);
		i++;
	}
	if (file[i - 1] == '\n')
		print_error_extended(3, dope);
	if (line_nbr < 3)
		print_error_extended(4, dope);
	if (!dope[3] && line_nbr > 129)
		print_error_extended(5, dope);
}

/*
** Function that check if tetrimino square contains:
** - 4 x #
** - 12 x .
*/

int		check_tetri_errors(char *tetri)
{
	int		i;
	int		htg;
	int		dot;

	i = 0;
	htg = 0;
	dot = 0;
	while (tetri[i])
	{
		if (tetri[i] == '#')
			htg++;
		else if (tetri[i] == '.')
			dot++;
		i++;
	}
	if (htg != 4 || dot != 12 || check_tetri_errors_proxy(tetri))
		return (6 + check_tetri_errors_proxy(tetri));
	return (0);
}

/*
** Function that check if 4 # (tetrimino parts) are linked
*/

int		check_tetri_errors_proxy(char *tetri)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tetri[i])
	{
		if (i < 19 && tetri[i] == '#' && tetri[i + 1] == '#')
			j++;
		if (i > 0 && tetri[i] == '#' && tetri[i - 1] == '#')
			j++;
		if (i < 15 && tetri[i] == '#' && tetri[i + 5] == '#')
			j++;
		if (i > 4 && tetri[i] == '#' && tetri[i - 5] == '#')
			j++;
		i++;
	}
	return ((j < 6) ? 1 : 0);
}
