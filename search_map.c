/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <hulamy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:47:22 by hulamy            #+#    #+#             */
/*   Updated: 2019/05/08 17:54:32 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** function that look for the first place in the map for a tetri
*/

int		find_place(unsigned int *tab, t_fillist *list, int size, int pos)
{
	int				i;
	int				j;
	unsigned int	mask;
	unsigned int	tmp;

	// creer un mask avec les size bits de gauche a 1 (ex: 11111110000000000000000000000000)
	mask = ~0u << (32 - list->width);
	tmp = mask;
	i = pos;
	// boucle jusqu'a la dernier place pour le tetri dans la map ou qu'il fit dans un trou
	while (i < (size - list->height + 1) * size)
	{
		// pour ne pas deborder a droite de la map
		if (i % size == size - list->width + 1)
			i += list->width;
		else
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
				return (i + 1);
			i++;
		}
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
		ft_putstr("j: "); ft_putnbrendl(j);
//		ft_putstr("map[(j - 1) / 32]                         :"); print_bits(map[(j - 1) / 32], 32);
//		ft_putstr("(mask & tetri << (16 + i)) >> (j - 1)     :"); print_bits((mask & tetri << (16 + i)) >> (j - 1), 32);
		map[(j - 1) / 32] ^= (mask & tetri << (16 + i)) >> (j - 1);
//		ft_putstr("map[(j - 1) / 32] ^ mask...               :"); print_bits(map[j / 32], 32);
		if (j % 32 != 1)
		{
//			ft_putendl("if (j % 32 != 1) :");
			ft_putstr("map[(j + size) / 32]                      :"); print_bits(map[(j + size) / 32], 32);
			ft_putstr("(mask & tetri << (16 + i))                :"); print_bits((mask & tetri << (16 + i)), 32);
			ft_putstr("(mask & tetri << (16 + i)) << (32 - j + 1):"); print_bits((mask & tetri << (16 + i)) << (32 - j + 1), 32);
			map[(j + size) / 32] ^= (mask & tetri << (16 + i)) << (32 - j + 1);
			ft_putstr("map[(j + size) / 32] ^ mask...            :"); print_bits(map[(j + size) / 32], 32);
		}
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
	unsigned int tmp = list->tetribit << 16; print_map(&tmp, list->width, list->height, list->letter);	// DEBUG
	while ((pos = find_place(map, list, size, pos)))
	{
		add_remove(map, list, size, pos);
		list->position = pos;
							print_final_map(link, size);		// DEBUG
							ft_putnbrendl(pos);
							print_map(map, size, size, '#');	// DEBUG
							ft_putchar('\n');
		if (fill_map(map, list->next, size, link))
			return (1);
		add_remove(map, list, size, pos);
							list->position = -1;				// DEBUG
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
