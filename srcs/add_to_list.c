/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:20:53 by hulamy            #+#    #+#             */
/*   Updated: 2019/04/14 17:30:57 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

void	find_start_to_end(char **square, int *x1, int *x2, int *y1, int *y2)
{
	while (*y1 == 4 && !(*y1 = 0) && square[++(*x1)][0] != '#')
		while (*y1 < 4 && square[*x1][*y1] != '#')
			(*y1)++;
	while (*y2 == 0 && (*y2 = 3) && square[--(*x2)][3] != '#')
		while (*y2 > 0 && square[*x2][*y2] != '#')
			(*y2)--;
}

void	reduce_tetraminos(char **square, t_fillist *list)
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	x1 = -1;
	x2 = 4;
	y1 = 4;
	y2 = 0;
	find_start_to_end(square, &x1, &x2, &y1, &y2);
	printf("de [%d,%d] a [%d,%d]\n",x1, y1, x2, y2);
}

int		add_to_list(char **square)
{
	t_fillist	*list;

	square++;
	printf("square[0] : %s\n", square[0]);
	if (!(list = (t_fillist*)malloc(sizeof(*list))))
		return (0);
	reduce_tetraminos(square, list);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 5)
	{
		add_to_list(av);
	}
	return (0);
}
