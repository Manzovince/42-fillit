/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:19:45 by hulamy            #+#    #+#             */
/*   Updated: 2019/03/25 15:26:59 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** locate the first occurence of the string little in big
** and return a pointer to this occurence if found
*/

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (!ft_strlen(to_find))
		return ((char *)str);
	while (i == 0)
	{
		while (to_find[i] && to_find[i] == str[j + i])
			i++;
		if (to_find[i])
		{
			j++;
			if (str[j] == '\0' && to_find[i])
				return (0);
			i = 0;
		}
	}
	return ((char *)str + j);
}
