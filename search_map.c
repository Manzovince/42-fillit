/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <hulamy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:47:22 by hulamy            #+#    #+#             */
/*   Updated: 2019/05/10 20:45:35 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** function that look if a tretri fit in a place
*/

unsigned int	fit_in_place(unsigned int *map, t_fillist *list, int size, int pos)
{
	unsigned int	tmp;
	unsigned int	mask;
	int				i;

	mask = ~0u << (32 - list->width);
	i = (list->height - 1) * size + pos;
	tmp = 0;
	while (i >= pos)
	{
		tmp >>= list->width;
		tmp |= (mask & (map[i / 32] << i)) | (mask & (map[(i / 32) + 1] >> (32 - i)));
		i -= size;
	}
	return (!((tmp >> 16) & list->tetribit));
}

/*
** function that look for the first place in the map for a tetri
*/

int		find_place(unsigned int *tab, t_fillist *list, int size, int pos)
{
	// boucle jusqu'a la dernier place pour le tetri dans la map ou qu'il entre dans un trou
	while (pos < (size - list->height + 1) * size)
	{
		// pour ne pas deborder a droite de la map
		if (pos % size > size - list->width)
			pos += list->width - 2;
		else if (fit_in_place(tab, list, size, pos))
			return (pos + 1);
		pos++;
	}
	return (0);
}

/*
** function that add or remove a tetri on the map
*/

void	add_remove(unsigned int *map, t_fillist *list, int size, int pos)
{
	unsigned int	mask;
	unsigned short	tetri;
	int				i;
	int				j;

	tetri = list->tetribit;
	mask = ~0u << (32 - list->width);
	i = (list->height - 1) * list->width;
	j = (list->height - 1) * size + pos;
	// change les bits du tetri sur la map a la position donnee
	while (j >= pos)
	{
		map[(j - 1) / 32] ^= (mask & tetri << (16 + i)) >> (j - 1);
		map[(j - 1) / 32 + 1] ^= (mask & tetri << (16 + i)) << (32 - j) << 1;
		j -= size;
		i -= list->width;
	}
}

/*
** function that recursively try to fill the map with the tetris
*/

int		fill_map(unsigned int *map, t_fillist *list, int size, t_fillist *link)	// DEBUG "link"
{
	int	pos;

	pos = 0;
	if (!list)
		return (1);
//	unsigned int tmp = list->tetribit << 16; print_map(&tmp, list->width, list->height, list->letter);	// DEBUG
	while ((pos = find_place(map, list, size, pos)))
	{
		add_remove(map, list, size, pos);
		list->position = pos;
//		print_final_map(link, size); ft_putnbrendl(pos); print_map(map, size, size, '#'); ft_putchar('\n'); // DEBUG
		if (fill_map(map, list->next, size, link))
			return (1);
		add_remove(map, list, size, pos);
//		list->position = -1;	// DEBUG
	}
	return (0);
}

/*
** function that init the map to the right size fill with int equal to zeros
*/

unsigned int	*init_map(int i)
{
	unsigned int	*new;
	int				size;

	size = (i * i) / 32 + 1;
	new = (unsigned int *)malloc(sizeof(*new) * size);
	while (size)
		new[size--] = 0;
	return (new);
}

/*
** function that send to "fill_map" a map of a certain size and increment its size untill it's solved
*/

void	search_map(t_fillist *list)
{
	t_fillist		*tmp;

	unsigned int	*map;
	int				size;
	int				num;

	size = 2;
	num = 1;
	tmp = list;
	// trouve le nombre de tetri en parcourant la liste chainee
	while ((tmp = tmp->next))
		num++;
	// trouve la taille minimale de la map
	while (size * size < num * 4)
		size++;
	map = init_map(size);



	unsigned int	print;
	tmp = list;
	while (tmp)
	{
		// imression pour tests
		print = tmp->tetribit;
		print <<= 16;
		print_map(&print, tmp->width, tmp->height, tmp->letter);		// test, imprime le tetri
		ft_putchar('\n');
		tmp = tmp->next;
	}


	// lance la recursive fill_map en augmentant la taille de la map tant qu'il n'y a pas de solution
	while (!fill_map(map, list, size, list))
		map = init_map(size++);
	print_final_map(list, size);		// DEBUG
	print_map(map, size, size, '#');	// DEBUG
}
