/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:12:36 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/01 17:12:38 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		remove_square(t_type *square, char nbr, char type)
{
	int		i;
	int		ret;

	i = 0;
	ret = -1;
	while (square->str[i])
	{
		if (square->str[i] == nbr)
		{
			if (ret == -1)
				ret = i;
			square->str[i] = '.';
		}
		i++;
	}
	return (chose_type(type, ret));
}

int		chose_type(char type, int ret)
{
	if (type == -9 || type == -7 || type == -6 || type == -4
		|| type == -3 || type == -1 || type == 0 || type == 1
		|| type == 3 || type == 5 || type == 6 || type == 7
		|| type == 8)
		return (ret + 1);
	else if (type == 9)
		return (ret - 1);
	else
		return (ret);
}
