/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:12:34 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/01 17:12:35 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int			fd;

	if (ac != 2 || (fd = open(av[1], O_DIRECTORY | O_RDONLY)) >= 0)
	{
		write(2, "fillit: usage : fillit [PATH/FILE]\n", 35);
		return (-1);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		write(2, "fillit: usage : fillit [PATH/FILE]\n", 35);
		return (-1);
	}
	else
	{
		if ((fd = i_got_a_fillit(fd)) < 0)
		{
			if (fd == FILE_ERROR || fd == ERROR)
				write(1, "error\n", 6);
			if (fd == OPEN_ERROR || fd == READ_ERROR)
				write(2, "Something went wrong, please try again\n", 39);
		}
	}
	return (fd);
}
