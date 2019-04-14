/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:20:53 by hulamy            #+#    #+#             */
/*   Updated: 2019/04/15 00:07:50 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>


void	find_start_and_end(char **square, int *x1, int *x2, int *y1, int *y2)
{
	int i;

	i = 4;
	while (*x1 < 4 && i == 4 && !(i = 0) && square[++(*x1)][0] != '#')
		while (i < 4 && square[*x1][i] != '#')
			i++;
	i = 4;
	while (*y1 < 4 && i == 4 && !(i = 0) && square[0][++(*y1)] != '#')
		while (i < 4 && square[i][*y1] != '#')
			i++;
	i = -1;
	while (*x2 >= 0 && i == -1 && (i = 3) && square[--(*x2)][3] != '#')
		while (i >= 0 && square[*x2][i] != '#')
			i--;
	i = -1;
	while (*y2 >= 0 && i == -1 && (i = 3) && square[3][--(*y2)] != '#')
		while (i >= 0 && square[i][*y2] != '#')
			i--;
}

char	**fill_tetraminos(char **square, int x1, int y1, int x2, int y2)
{
	char	**result;
	int		height;
	int		length;
	int		i;
	int		j;

	i = 0;
	height = x2 - x1 + 1;
	length = y2 - y1 + 1;
	if (!(result = (char**)malloc(sizeof(*result) * (height + 1))))
		return (NULL);
	while (i < 4)
	{
		if (!(result[i] = (char*)malloc(sizeof(**result) * (length + 1))))
			return (NULL);
		result[i][length] = '\0';
		i++;
	}
	i = -1;
	while (++i < height && (j = -1))
		while (++j < length)
			result[i][j] = square[x1 + i][y1 + j];
	return (result);
}

int		add_to_list(char **square)
{
	t_fillist	*list;
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	x1 = -1;
	y1 = -1;
	x2 = 4;
	y2 = 4;
	if (!(list = (t_fillist*)malloc(sizeof(*list))))
		return (0);
	find_start_and_end(square, &x1, &x2, &y1, &y2);
	list->size[0] = y2 - y1 + 1;
	list->size[1] = x2 - x1 + 1;
	list->area = list->size[0] * list->size[1];
	list->tetraminos = fill_tetraminos(square, x1, y1, x2, y2);

//	int	i;															// pour imprimer
//	i = -1;															//
//	while (++i < list->size[1])										//
//		printf("%s\n", list->tetraminos[i]);						//

	return (0);
}

//	int		main(int ac, char **av)
// 	{
// 		if (ac == 5)
// 		{
// 			add_to_list(++av);
// 		}
// 		return (0);
// 	}
