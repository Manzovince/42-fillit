/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:17:04 by hulamy            #+#    #+#             */
/*   Updated: 2019/03/25 15:21:27 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** apply function f to each element of string s with index specified
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;

	i = 0;
	while (s && *s && f)
		f(i++, s++);
}
