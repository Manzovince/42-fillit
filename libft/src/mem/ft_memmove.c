/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:13:34 by hulamy            #+#    #+#             */
/*   Updated: 2019/04/03 15:44:28 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copy n characters from src to dst in a non destructive way and return dst
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*source;
	char	*dest;

	i = -1;
	source = (char *)src;
	dest = (char *)dst;
	if (source < dest)
		while ((int)(--len) >= 0)
			dest[len] = source[len];
	else
		while (++i < (int)len)
			dest[i] = source[i];
	return (dst);
}
