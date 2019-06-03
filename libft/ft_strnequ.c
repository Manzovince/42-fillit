/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:18:55 by hulamy            #+#    #+#             */
/*   Updated: 2019/03/25 15:25:20 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** return 0 if n first character of strings s1 and s2 are identical
** and 1 if not
*/

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	return (ft_strncmp(s1, s2, n) == 0);
}
