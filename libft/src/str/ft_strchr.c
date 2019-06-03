/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:15:48 by hulamy            #+#    #+#             */
/*   Updated: 2019/04/16 17:28:46 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** locate the first occurence of character c in string s
** and return pointer to its location
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (s[i])
		i++;
	while (++j < i + 1)
		if (s[j] == c)
			return ((char *)s + j);
	return (NULL);
}
