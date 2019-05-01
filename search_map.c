/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:47:22 by hulamy            #+#    #+#             */
/*   Updated: 2019/05/01 23:12:57 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** function that look for the first place in the map for a tetri
*/

int		find_place(unsigned int *tab, t_fillist *list, int size)
{
	int				i;
	int				j;
	unsigned int	mask;
	unsigned int	tmp;

	// creer un mask avec les size bits de gauche a 1 (ex: 11111110000000000000000000000000)
	mask = ~0u << (32 - list->width);
	tmp = mask;
	i = 0;
	// boucle jusqu'a la dernier place pour le tetri dans la map ou qu'il fit dans un trou
	while (i < (size - list->height + 1) * size)
	{
		tmp = 0;
		// construit un tmp qui est une photo de la map de la taille du tetri a un emplacement donne
		j = (list->height - 1) * size + i;
		while (j >= i)
		{
			tmp >>= list->width;
			tmp |= (mask & (tab[j / 32] << j));
			tmp |= (mask & (tab[(j + list->width) / 32] >> (32 - j)));
			j -= size;
		}
		if (!((tmp >> 16) & list->tetribit))
			return ((list->position = i + 1));
		if (i % size == size - list->width)
			i += list->width - 1;
		i++;
	}
	return (0);
}

/*
** function that add or remove a tetri on the map
*/

void	add_remove(unsigned int *map, t_fillist *list, int size, int pos)
{
	unsigned int	mask;
	unsigned int	tmp;
	int				j;
	int				i;

	mask = ~0u << (32 - list->width);
	tmp = 0;
	i = (list->height - 1) * list->width;
	j = (list->height - 1) * size + pos;
	// change les bits du tetri sur la map a la position donnee
	while (j >= pos)
	{
								print_map(map, size, size);																						// POUR DEBUG
								ft_putstr("map[j / 32]    : "); print_bits(map[j / 32], 32);													// POUR DEBUG
								ft_putstr("mask           : "); print_bits((mask & list->tetribit << (16 + i)) >> (j - 1), 32);					// POUR DEBUG
		map[j / 32] ^= (mask & list->tetribit << (16 + i)) >> (j - 1);
								ft_putstr("map[j / 32]    : "); print_bits(map[j / 32], 32);													// POUR DEBUG
								ft_putstr("map[(j+s) / 32]: "); print_bits(map[(j + size) / 32], 32);											// POUR DEBUG
								ft_putstr("mask 2         : "); print_bits((mask & list->tetribit << (16 + i)) << ((j % 32) + 1), 32);			// POUR DEBUG
								ft_putstr("(j % 32) + 1   : "); ft_putnbrendl((j % 32) + 1);													// POUR DEBUG
								ft_putstr("j              : "); ft_putnbrendl(j);																// POUR DEBUG
		map[(j + size) / 32] ^= (mask & list->tetribit << (16 + i)) << ((j % 32) + 1);
								ft_putstr("map[(j+s) / 32]: "); print_bits(map[(j + size) / 32], 32);											// POUR DEBUG
		j -= size;
		i -= list->width;
	}
								print_map(map, size, size);																						// POUR DEBUG
	ft_putchar('\n');
}

/*
** function that recursively try to fill the map with the tetris
*/

int		fill_map(unsigned int *map, t_fillist *list, int size)
{
	if (!list)
		return (1);
	while (find_place(map, list, size))
	{
		add_remove(map, list, size, list->position);
		print_map(map, size, size);			// POUR DEBUG
		ft_putendl("add_remove");			// POUR DEBUG
		if (fill_map(map, list->next, size))
				return (1);
		add_remove(map, list, size, list->position);
		list->position++;
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
	int				i;

	size = 2;
	i = 1;
	tmp = list;
	// trouve le nombre de tetri en parcourant la liste chainee
	while ((tmp = tmp->next))
		i++;
	// trouve la taille minimale de la map
	while (size * size < i * 4)
		size++;
	map = init_map(size);
	
	// lance la recursive fill_map en augmentant la taille de la map tant qu'il n'y a pas de solution
	ft_putstr("test "); ft_putnbrendl(size);	// POUR DEBUG
	while (!fill_map(map, list, size))
		map = init_map(size++);
}

