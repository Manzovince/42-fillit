/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:29:05 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/24 18:02:08 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function that display error message *s on fd and exit program
*/

void	print_error(char *str)
{
	write(1, str, ft_strlen(str));
//	exit(1);
}

/*
** Function that display error message *s on fd
** with more informations
** and exit program
*/

void	print_error_extended(int error, int *dope)
{
	if (!dope[3])
	{
		print_error("error\n");
		exit(0);
	}
	if (error == 1)
		ft_putstr("error: File contains char other than '.','#' and '\\n'.\n");
	if (error == 2)
		ft_putstr("error: File contains more than 2 '\\n' in a row.\n");
	if (error == 3)
		ft_putstr("error: File contains less than 1 tetrimino "
					"or more than 26.\n");
	if (error == 4)
		ft_putstr("error: Tetrimino has more or less than 4 #.\n");
	if (error == 5)
		ft_putstr("error: Tetrimino # are not all connected.\n");
//	exit(1);
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
		if (file[i] == '\n' && line_nbr % 5 == 0 && file[i-1] != '\n')
			print_error("error\n");		// est-ce que ca n'imprime pas error deux fois ??
		if (file[i] == '\n' && file[i+1] != '\0' && \
			file[i+2] != '.' && file[i+2] != '#')
			print_error_extended(2, dope);
		i++;
	}
	if (line_nbr < 4 || line_nbr > 129)
		print_error_extended(3, dope);
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
		return (4 + check_tetri_errors_proxy(tetri));
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
		if (tetri[i] == '#' && tetri[i + 1] == '#')
			j++;
		if (tetri[i] == '#' && tetri[i - 1] == '#')
			j++;
		if (tetri[i] == '#' && tetri[i + 5] == '#')
			j++;
		if (tetri[i] == '#' && tetri[i - 5] == '#')
			j++;
		if (tetri[i] == '.' || tetri[i] == '\n')
			i++;
		else if (tetri[i] == '#' && (tetri[i + 1] == '#' || tetri[i - 1] == '#'
			|| tetri[i + 5] == '#' || tetri[i - 5] == '#'))
			i++;
		else
			return (1);
	}
	return ((j < 6) ? 1 : 0);
}