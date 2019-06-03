/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:13:04 by hulamy            #+#    #+#             */
/*   Updated: 2019/04/03 15:43:41 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** compare two bytes strings (doesnt recognize a null terminated string)
** and return value of difference between first two different character
*/

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*frst;
	unsigned char	*scnd;
	size_t			i;

	i = 0;
	frst = (unsigned char *)s1;
	scnd = (unsigned char *)s2;
	while (i < n && frst[i] == scnd[i])
		i++;
	return ((i == n) ? 0 : frst[i] - scnd[i]);
}
