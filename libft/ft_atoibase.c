/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:15:31 by hulamy            #+#    #+#             */
/*   Updated: 2018/11/16 15:22:34 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_valid_base(char *base, int i, int j)
{
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	if (i >= 2)
		return (1);
	return (0);
}

static int	skip(int i, char *str, int *n)
{
	while ((str[i] == 32) || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*n = -1;
		i++;
	}
	return (i);
}

int			ft_atoibase(char *str, char *base)
{
	int i;
	int j;
	int length;
	int res;
	int n;

	length = 0;
	res = 0;
	n = 1;
	if (!is_valid_base(base, 0, 0))
		return (0);
	while (base[length])
		length++;
	i = skip(0, str, &n);
	while (str[i] && str[i] > 32 && str[i] != '-' && str[i] != '+')
	{
		j = 0;
		while (str[i] != base[j] && base[j])
			j++;
		if (base[j] == '\0')
			return (0);
		res = (res * length) + j;
		i++;
	}
	return (res * n);
}
