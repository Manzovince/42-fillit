/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 12:09:46 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/14 17:44:18 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*read_file(char *file)
{
	char	buf[BUFF_SIZE];
	int		fd;
	int		rv;
	int		i;
	char	*result;

	if (((fd = open(file, O_RDONLY)) < 0) \
		|| ((rv = read(fd, &buf, BUFF_SIZE)) < 0) \
		|| !(result =  malloc(sizeof(char) * rv)))
		return (NULL);
	buf[rv] = '\0';
	i = 0;
	while (buf[i])
	{
		result[i] = buf[i];
		i++;
	}
	result[i] = '\0';
	close(fd);
	return (result);
}
