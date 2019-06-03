/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:20:09 by hulamy            #+#    #+#             */
/*   Updated: 2019/03/25 15:12:04 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** create a copy of s without the firsts and lasts empty characters
*/

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		len;
	char	*str;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	len = ft_strlen(s) - 1;
	while (len >= 0 && (s[len] == ' ' || s[len] == '\t' || s[len] == '\n'))
		len--;
	len++;
	if (!(str = ft_strsub(s, 0, len)))
		return (NULL);
	return (str);
}
