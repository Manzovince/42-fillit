/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraymap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:17:24 by hulamy            #+#    #+#             */
/*   Updated: 2018/11/16 15:17:27 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_arraymap(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*newtab;

	i = -1;
	if (!tab)
		return (NULL);
	if (!(newtab = (int*)malloc(sizeof(*newtab) * (length + 1))))
		return (NULL);
	while (++i < length)
		newtab[i] = (*f)(tab[i]);
	return (newtab);
}
