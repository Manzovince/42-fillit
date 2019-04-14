/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:29:05 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/14 14:16:01 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Function that display error message *s on fd
*/

void	ft_display_error(char *s, int fd)
{
	write(fd, s, strlen(s));
}

/*
** Function to see if there if an error if the file
** - less than 4 lines
** - more than 104 (26 tetri) + 25 (\n) = 129 lines
** - two \n in a row
*/

int		ft_file_errors(char *file)
{
	int		line_nbr;

	line_nbr = 0;
	while (*file)
	{
		if (*file == '\n')
			line_nbr++;
		file++;
		if (*file == '\n')
		 	return (1);
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
