/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:12:39 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/01 17:12:50 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_strstr(char haystack[], char needle[])
{
	int		i;
	int		j;

	i = 0;
	while (i < BUFF_SIZE)
	{
		j = 0;
		while (i + j < BUFF_SIZE && needle[j] && needle[j] == haystack[i + j])
			j++;
		if (!needle[j])
			return (i);
		i++;
	}
	return (ERROR);
}

void	ft_memset(void *ptr, char c, int len)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char*)ptr;
	while (i < len)
		str[i++] = c;
}
