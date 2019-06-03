/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:15:55 by hulamy            #+#    #+#             */
/*   Updated: 2019/04/17 17:09:35 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_malloc_size(int decimal, int length, int i)
{
	if (decimal <= 0)
		i++;
	while (decimal)
	{
		decimal /= length;
		i++;
	}
	return (i);
}

static char	*ft_decimal_to_base(int decimal, char *base, char *res, int size)
{
	long	nb;
	int		i;

	nb = decimal;
	i = 0;
	while (base[i])
		i++;
	if (nb < 0)
		nb = -nb;
	while (--size >= 0)
	{
		res[size] = base[nb % i];
		nb /= i;
	}
	return (res);
}

static int	ft_base_to_decimal(char *nbr, char *base, int length, int i)
{
	long	decimal;
	int		j;

	decimal = 0;
	if (nbr[i] == '-')
		i++;
	while (nbr[i])
	{
		j = 0;
		while (nbr[i] != base[j] && base[j])
			j++;
		decimal = (decimal * length) + j;
		i++;
	}
	if (nbr[0] == '-')
		decimal = -decimal;
	return (decimal);
}

char		*ft_convertbase(char *nbr, char *base_from, char *base_to)
{
	int		length;
	int		size;
	int		decimal;
	char	*res;

	res = 0;
	length = 0;
	while (base_from[length])
		length++;
	decimal = ft_base_to_decimal(nbr, base_from, length, 0);
	length = 0;
	while (base_to[length])
		length++;
	size = ft_malloc_size(decimal, length, 0);
	res = (char *)malloc(sizeof(char) * (size + 1));
	res[size] = '\0';
	return (ft_decimal_to_base(decimal, base_to, res, size));
}
