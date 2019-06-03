/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmultisplit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:18:29 by hulamy            #+#    #+#             */
/*   Updated: 2019/03/25 15:23:57 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** return an array of string with each word found in str
** with any character of charset difining a separator
*/

#include "libft.h"

static int	ft_is_separator(char c, char *charset, int i)
{
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	c = charset[i];
	return (0);
}

static int	ft_count(char *str, int word, char **tab, char *charset)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (ft_is_separator(str[k], charset, 0) == 1)
		k++;
	while (str[k] != '\0' && i != word)
	{
		j = 0;
		while (!ft_is_separator(str[k + j], charset, 0) && str[k + j] != '\0')
		{
			if (word == -2)
				tab[i][j] = str[k + j];
			j++;
		}
		k += j;
		while (ft_is_separator(str[k], charset, 0))
			k++;
		i++;
	}
	if (word == -1)
		return (i);
	return (j);
}

char		**ft_strmultisplit(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	k = 0;
	tab = 0;
	i = ft_count(str, -1, tab, charset);
	if (!(tab = (char**)malloc(sizeof(tab) * (i + 1))))
		return (NULL);
	tab[i] = 0;
	while (k < i)
	{
		j = ft_count(str, k + 1, tab, charset);
		tab[k] = (char*)malloc(sizeof(*tab) * (j + 1));
		tab[k][j] = '\0';
		k++;
	}
	ft_count(str, -2, tab, charset);
	return (tab);
}
