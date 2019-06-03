/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:19:16 by hulamy            #+#    #+#             */
/*   Updated: 2019/03/25 15:25:57 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** locate the first occurence of the string little in len first characters
** of big and return a pointer to this occurence if found
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	if (!ft_strlen(little))
		return ((char *)big);
	while (i == 0 && j <= len)
	{
		while (little[i] == big[j + i] && little[i] && j + i <= len)
			i++;
		if (little[i])
		{
			j++;
			if (!big[j] || j >= len)
				return (0);
			i = 0;
		}
	}
	return ((char *)big + j);
}
