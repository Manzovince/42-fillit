/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <hulamy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:47:22 by hulamy            #+#    #+#             */
/*   Updated: 2019/05/28 17:33:43 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** function that look if a tretri fit in a place
*/

unsigned int	fit_in_place(unsigned int *map, t_fillist *lst, int size, int i)
{
	unsigned int	tmp;
	unsigned int	mask;
	unsigned int	tetri;
	int				n;
	int				r;

	n = lst->num;
	r = lst->rank;
	i = lst->height;
	tetri = lst->tetribit << 16 >> lst->width;
	tmp = 0;
	mask = ~0u << (32 - lst->width);
	while (i--)
	{
		if (tmp & tetri)
			return (0);
		if (r >= 32 && ++n)
			r -= 32;
		tmp = (mask & (map[n] << r));
		if (n + 1 < lst->total_num)
			tmp |= (mask & (map[n + 1] >> (32 - r)));
		tetri <<= lst->width;
		r += size;
	}
	return (!(tmp & tetri));
}

/*
** function that look for the first place in the map for a tetri
*/

int				find_place(unsigned int *map, t_fillist *list, int size)
{
	int	limit;
	int pos;

	pos = list->position;
	list->place = pos % size;
	list->rank = pos % 32;
	list->num = pos / 32;
	limit = (size - list->height + 1) * size;
	while (pos < limit)
	{
		if (list->rank >= 32 && ++list->num)
			list->rank -= 32;
		if (list->place > size - list->width)
		{
			list->place = -1;
			pos += list->width - 2;
			list->rank += list->width - 2;
		}
		else if (fit_in_place(map, list, size, 0))
			return ((list->position = pos + 1));
		pos++;
		list->place++;
		list->rank++;
	}
	return (0);
}

/*
** function that add or remove a tetri on the map
*/

void			add_remove(unsigned int *map, t_fillist *list, int size)
{
	unsigned int	mask;
	unsigned short	tetri;
	int				i;
	int				j;

	tetri = list->tetribit;
	mask = ~0u << (32 - list->width);
	i = (list->height - 1) * list->width;
	j = (list->height - 1) * size + list->position;
	while (j >= list->position)
	{
		map[(j - 1) / 32] ^= (mask & tetri << (16 + i)) >> (j - 1);
		if ((j - 1) / 32 + 1 < list->total_num)
			map[(j - 1) / 32 + 1] ^= (mask & tetri << (16 + i)) << (32 - j) << 1;
		j -= size;
		i -= list->width;
	}
}

/*
** Function that recursively try to fill the map with the tetris
*/

int				fill_map(unsigned int *map, t_fillist *list, int size)
{
	if (!list)
		return (1);
	list->position = 0;
	while (find_place(map, list, size))
	{
		add_remove(map, list, size);
		list->test = 1;
		if (list->dope[0])
		{
			print_letter_map(list->start, size, 1);
			ft_putchar('\n');
		}
		if (list->dope[1])
			if (check_tetri_memory(list, list->position))
				if (fill_map(map, list->next, size))
					return (1);
		if (!list->dope[1])
			if (fill_map(map, list->next, size))
				return (1);
		add_remove(map, list, size);
		list->test = 0;
	}
	return (0);
}

/*
** function that send to "fill_map" a map of a certain size
** and increment its size untill it's solved
*/

int				search_map(t_fillist *list)
{
	t_fillist		*tmp;
	unsigned int	*map;
	int				size;
	int				num;
	int				i;

	size = 2;
	num = 1;
	tmp = print_tetri(list);
	while ((tmp = tmp->next))
		num++;
	while (size * size < num * 4)
		size++;
	i = 0;
	while (!i)
	{
		num = (size * size) / 32 + 1;
		if (!(map = (unsigned int *)malloc(sizeof(*map) * num)))
			return (0);
		check_same_tetri(list, num);
		while (num)
			map[num--] = 0;
		i = fill_map(map, list, size++);
	}
	return (print_binary_map(map, size, list->dope));
}
