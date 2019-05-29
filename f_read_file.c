/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 12:09:46 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/28 18:36:35 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function that read and return a ptr to file content
*/

char	*read_file(char *file)
{
	char	buf[BUFF_SIZE];
	int		fd;
	int		rv;
	int		i;
	char	*result;

	if (((fd = open(file, O_RDONLY)) < 0) \
		|| ((rv = read(fd, &buf, BUFF_SIZE)) < 0) \
			|| !(result = malloc(sizeof(char) * rv)))
		return (NULL);
	buf[rv - 1] = '\0';
	i = -1;
	while (buf[++i])
		result[i] = buf[i];
	result[i] = '\0';
	close(fd);
	return (result);
}
