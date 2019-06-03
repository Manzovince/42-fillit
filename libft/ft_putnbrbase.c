/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:17:00 by hulamy            #+#    #+#             */
/*   Updated: 2018/11/16 15:23:43 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char *base)
{
	int i;
	int j;

	i = 0;
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

void		ft_putnbrbase(int nbr, char *base)
{
	int		i;
	long	n;

	i = 0;
	n = nbr;
	if (check(base))
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		while (base[i])
			i++;
		if (n >= i)
			ft_putnbrbase(n / i, base);
		ft_putchar(base[n % i]);
	}
}
