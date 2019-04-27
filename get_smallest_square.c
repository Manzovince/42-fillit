/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_smallest_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 22:29:45 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/27 15:04:46 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function to bruteforce with backtracking for smallest square
*/

int		*get_smallest_square(t_fillist list, int size, unsigned int map[])
{
	unsigned int	mask;
	int				i;
	int				j;

	i = 0;
	mask = map[size];
	while (list.tetribit != NULL)
	{
		mask = (mask >> 1) | (((1 << (i % 32)) & map[j]) << (31 - (i % 32)));
		if (!(tetri & mask))
			return (1);
		i++;
	}
	return (0);
}
