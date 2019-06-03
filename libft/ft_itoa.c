/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:10:25 by hulamy            #+#    #+#             */
/*   Updated: 2018/11/14 21:36:38 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	nbis;

	len = (n < 0) ? 2 : 1;
	nbis = n;
	while (nbis /= 10)
		len++;
	nbis = n;
	nbis *= (nbis < 0) ? -1 : 1;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = nbis % 10 + '0';
	while (nbis /= 10)
		str[--len] = nbis % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
