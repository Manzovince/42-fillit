/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:29:05 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/14 12:35:46 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_display_error(char *s, int fd)
{
	write(fd, s, strlen(s));
}

int		ft_file_errors(char *file)
{
	int		line_nbr;

	line_nbr = 0;
	while (*file)
	{
		if (*file == '\n')
			line_nbr++;
		file++;
	}
	/*less than 4 lines or more than 104 (26 tetri) + 25 = 129 lines*/
	if (line_nbr < 4 || line_nbr > 129)
		return (1);
	return (0);
}

/*
int		ft_tetri_errors()
{

}
*/
