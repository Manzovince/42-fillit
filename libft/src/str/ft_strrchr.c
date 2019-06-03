/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:19:23 by hulamy            #+#    #+#             */
/*   Updated: 2019/03/25 15:26:21 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** locate the last occurence of character c in string s
** and return pointer to its location
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i++;
	while (i--)
		if (s[i] == c)
			return ((char *)s + i);
	return (NULL);
}
