/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:17:22 by hulamy            #+#    #+#             */
/*   Updated: 2019/03/25 15:22:42 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** append src to sized dest and return size of final dest
*/

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dest[i] && i < size)
		i++;
	while (src[j])
	{
		if (j + i < size - 1 && size)
		{
			dest[i + j] = src[j];
			dest[i + j + 1] = '\0';
		}
		j++;
	}
	return (i + j);
}
