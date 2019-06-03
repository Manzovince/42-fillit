/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hole.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:12:10 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/01 17:12:11 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_hole(t_type *square, char tetri[], int to_test)
{
	if (count_island(square, 0, tetri, to_test) > square->hole)
		return (ERROR);
	return (SUCCESS);
}

int		i_fillit_the_power(t_type *square, char tetri[], int pos)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (i < pos)
	{
		if (tetri[i] == tetri[pos])
			j = i;
		i++;
	}
	if (j == -1)
		return (0);
	i = 0;
	while (square->str[i] != j + 'A')
		i++;
	return (i);
}
