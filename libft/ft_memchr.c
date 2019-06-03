/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:12:32 by hulamy            #+#    #+#             */
/*   Updated: 2019/04/03 15:43:14 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** locate character in string and return its position
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sbis;
	size_t			i;

	sbis = (unsigned char *)s;
	i = -1;
	while (++i < n)
		if (sbis[i] == (unsigned char)c)
			return ((void *)sbis + i);
	return (NULL);
}
