/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:29:05 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/14 17:46:32 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Function that display error message *s on fd
*/

void	print_error(char *s)
{
	write(2, s, strlen(s));
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
		i++;
	}
	if (line_nbr < 4 || line_nbr > 129)
		return (1);
	return (0);
}

/*
int		ft_tetri_errors()
{

}
*/
