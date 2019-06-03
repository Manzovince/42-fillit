/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:16:44 by hulamy            #+#    #+#             */
/*   Updated: 2019/03/25 15:21:02 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** return 0 if strings s1 and s2 are identical and 1 if not
*/

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	return (ft_strcmp(s1, s2) == 0);
}
