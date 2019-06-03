/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:19:36 by hulamy            #+#    #+#             */
/*   Updated: 2019/03/25 15:26:39 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** return an array of string with each word found in str, with c as separator
*/

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (s[++i])
		if (s[i] != c)
		{
			len++;
			while (s[i] && s[i] != c)
				i++;
		}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = 0;
	if (!s || !c)
		return (0);
	if (!(array = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1))))
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c)
		{
			len = 0;
			while (s[i + len] && s[i + len] != c)
				len++;
			array[j++] = ft_strsub(s, i, len);
			i = i + len - 1;
		}
	}
	array[j] = 0;
	return (array);
}
