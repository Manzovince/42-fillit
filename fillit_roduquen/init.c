/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:12:31 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/01 17:12:32 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>

int		i_got_a_fillit(int check_fd)
{
	int		fd;
	char	buffer[BUFF_SIZE];
	char	bufftest[21];
	char	tetri[27];
	int		ret;

	ft_memset(bufftest, 42, 21);
	ft_memset(tetri, 42, 27);
	bufftest[20] = 0;
	if ((fd = open("external_file.txt", O_RDONLY)) < 0)
		return (OPEN_ERROR);
	if (read(fd, buffer, BUFF_SIZE) <= 0)
		return (READ_ERROR);
	fd = 0;
	while ((ret = read(check_fd, bufftest, 20)) > 0)
	{
		if (ret != 20 || check_file(bufftest, tetri, buffer, fd) != SUCCESS)
			return (FILE_ERROR);
		if (read(check_fd, bufftest, 1) > 0 && bufftest[0] != '\n')
			return (FILE_ERROR);
		tetri[++fd] = 42;
	}
	if (ret < 0 || fd == 0 || bufftest[0] == '\n')
		return (FILE_ERROR);
	return (do_i_fillit(tetri, fd));
}

int		check_file(char bufftest[], char tetri[], char buffer[], int fd)
{
	if (bufftest[0] != '.' && bufftest[0] != '#')
		return (FILE_ERROR);
	if (full_tetri(tetri, buffer, bufftest, fd) != SUCCESS)
		return (FILE_ERROR);
	return (SUCCESS);
}
