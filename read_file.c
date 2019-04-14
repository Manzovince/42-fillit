/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 12:09:46 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/14 21:37:37 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function that read and return a ptr to file
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

/*
** Function that parse a file and return each tetrimino
*/

int		parse_input(char *input)
{
	char			/*NOM DE LA VARIABLE*/;
	int				c;
	int				i;
	int				j;

	c = 0;
	while (input[c])
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				/*NOM DE LA VARIABLE[j]*/ = input[c++];
				j++;
			}
			c++;
			i++;
		}
		c++;
	}
}
