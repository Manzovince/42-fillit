/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:29:05 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/15 14:41:19 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function that display error message *s on fd and exit program
*/

void	print_error(char *s)
{
	write(2, s, strlen(s));
	exit(1);
}

/*
** Function to see if there if an error if the file
** - less than 4 lines
** - more than 104 (26 tetri) + 25 (\n) = 129 lines
** - two \n in a row
*/

int		check_file_errors(char *file)
{
	int		i;
	int		line_nbr;

	i = 0;
	line_nbr = 0;
	while (file[i])
	{
		if (file[i] != '.' && file[i] != '#' && file[i] != '\n')
			return (1);
		if (file[i] == '\n')
			line_nbr++;
		if (file[i] == '\n' && file[i+1] != '\0' && \
			file[i+2] != '.' && file[i+2] != '#')
			return (1);
		i++;
	}
	if (line_nbr < 4 || line_nbr > 129)
		return (1);
	return (0);
}

/*
** Function that check if tetrimino square contains:
** - 4 '#'
** - 12 '.'
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
	if (htg != 4 || dot != 12 || check_tetri_errors2(tetri))
		return (1);
	return (0);
}

/*
** Function that check if tetrimino parts are linked
*/

int		check_tetri_errors2(char *tetri)
{
	int		i;

	i = 0;
	while (tetri[i])
	{
		if (tetri[i] == '.' || tetri[i] == '\n')
			i++;
		else if (tetri[i] == '#' && (tetri[i + 1] == '#' || tetri[i - 1] == '#'
				|| tetri[i + 5] == '#' || tetri[i - 5] == '#'))
			i++;
		else
			return (1);
	}
	return (0);
}
