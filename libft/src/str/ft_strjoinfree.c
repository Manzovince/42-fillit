/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:05:28 by hulamy            #+#    #+#             */
/*   Updated: 2019/03/25 15:22:28 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** create a new string by concatenating the two strings s1
** and s2 then freeing them
*/

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*str;

	if (!(str = ft_strjoin(s1, s2)))
		return (NULL);
	free(s1);
	return (str);
}
