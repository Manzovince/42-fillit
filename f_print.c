/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <hulamy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:24:28 by hulamy            #+#    #+#             */
/*   Updated: 2019/05/29 19:10:33 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** function that print a map of height and width
** usefull to print tetris
*/

void	print_sized_map(unsigned int *tab, int width, int height, char letter)
{
	int				i;
	unsigned int	mask;

	i = 0;
	mask = 0;
	while (i++ < width)
		mask = (mask >> 1) | ((mask | 1) << 31);
	i = 0;
	while (i < width * height)
	{
		if (i && !(i % width))
			ft_putchar('\n');
		if (tab[i / 32] & (1 << (31 - i % 32)))
			ft_put_tetri_color(letter);
		else
			ft_putchar('.');
		ft_putchar(' ');
		i++;
	}
	write(1, "\n", 1);
}

/*
** Print the final map with the letters
** if flag value is 0 -> print moulinette version
** if flag value is 0 -> print in color
*/

char	*init_print_map(t_fillist *list, int size)
{
	char		*map;
	int			i;
	int			j;

	map = (char *)malloc(sizeof(*map) * (size * size + 1));
	map[size * size] = '\0';
	i = -1;
	while (++i < size * size)
		map[i] = '.';
	while (list)
	{
		j = 0;
		i = -1;
		while (++i < list->width * list->height)
		{
			if (i && i % list->width == 0)
				j += size - list->width;
			if (1 << (15 - i) & list->tetribit && list->test == 1)
				map[list->position + i + j - 1] = list->letter;
		}
		list = list->next;
	}
	return (map);
}

/*
** Function that print the map with color if flag = 1
** or for moulinette if flag = 0;
*/

void	print_letter_map(t_fillist *list, int size, int flag)
{
	int			i;
	char		*map;

	map = init_print_map(list, size);
	i = -1;
	while (++i < size * size)
	{
		if (i && i % size == 0)
			ft_putchar('\n');
		if (flag == 0)
			ft_putchar(map[i]);
		else
		{
			ft_put_tetri_color(map[i]);
			ft_putchar(' ');
		}
	}
	free(map);
	ft_putchar('\n');
}

/*
** Function that print the map
*/

void	print_final_map(t_fillist *list, int size)
{
	if (list->dope[2])
	{
		ft_putendl("result for humans :");
		print_letter_map(list, size, 1);
		ft_putchar('\n');
		ft_putendl("result for moulinette :");
	}
	print_letter_map(list, size, 0);
	if (list->dope[2])
		ft_putchar('\n');
}
