/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_count_island.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:12:04 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/01 19:15:21 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_square6(int i, t_type *square, char nbr)
{
	if ((square->isl[i + 1] == nbr && (i + 1) % square->size != 0)
		|| square->isl[i - square->size] == nbr
		|| square->isl[i - 1] == nbr)
	{
		square->isl[i] = nbr;
		if (square->str[i + 1] == '.' && (i + 1) % square->size != 0)
			square->isl[i + 1] = nbr;
		if (square->str[i - square->size] == '.')
			square->isl[i - square->size] = nbr;
		if (square->str[i - 1] == '.')
			square->isl[i - 1] = nbr;
		return (SUCCESS);
	}
	return (ERROR);
}
