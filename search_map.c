/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <hulamy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:47:22 by hulamy            #+#    #+#             */
/*   Updated: 2019/05/13 18:24:56 by vmanzoni         ###   ########.fr       */
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
			i += list->width - 1;
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
//		print_final_map(list, size);
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
		if (j % 32 != 1)
			map[(j + size) / 32] ^= (mask & tetri << (16 + i)) << (32 - j + 1);
		j -= size;
		i -= list->width;
	}
}

/*
** Test optimisation for not testing wrong maps when tetri are identical
*/

int		check_same_tetri(t_fillist *list)
{
	t_fillist	*curr_tetri;
	t_fillist	*next_tetri;

	curr_tetri = list;

	while (curr_tetri != NULL)
	{
		next_tetri = curr_tetri->next;
		while (next_tetri != NULL)
		{
			if (curr_tetri->tetribit == next_tetri->tetribit)
			{
				if (next_tetri->same == NULL)
					next_tetri->same = curr_tetri;
				printf("%c->%c\n", next_tetri->letter, next_tetri->same->letter);
			}
			next_tetri = next_tetri->next;
		}
		curr_tetri = curr_tetri->next;
	}
	return (0);
}

/*
** Test optimisation for not testing wrong maps when tetri are identical
*/

int		check_tetri_memory(t_fillist *list, int pos)
{
	t_fillist	*tetri;
	uint64_t	mask;

	tetri = list;
	if (tetri->same != NULL)
	{
		mask = 1 << (pos - 1);
		print_bits(mask, 64);
		if (tetri->same->memory & mask)
		{
			ft_putstr("test\n");
			return (pos + 1);
		}
	}
	return (pos);
}

/*
** Function that recursively try to fill the map with the tetris
*/

int		fill_map(unsigned int *map, t_fillist *list, int size, t_fillist *link)	// DEBUG "link"
{
	int		pos;

	pos = 0;
	if (!list)
		return (1);
//	unsigned int tmp = list->tetribit << 16; print_map(&tmp, list->width, list->height, list->letter);	// DEBUG
	while ((pos = find_place(map, list, size, pos)))
	{
		list->memory = (list->memory << 1) + 1;
		add_remove(map, list, size, pos);
		list->position = pos;
		check_tetri_memory(list, pos);
		print_final_map(link, size);		// DEBUG
//		ft_putnbrendl(pos);
//		print_map(map, size, size, '#');	// DEBUG
		ft_putchar('\n'); 					// DEBUG
//		if (list->same && list->position == 1)
//		{
//			list = list->next;
//			if (fill_map(map, list->next, size, link))
//				return (1);
//		}
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
	check_same_tetri(list);
	// lance la recursive fill_map en augmentant la taille de la map tant qu'il n'y a pas de solution
	while (!fill_map(map, list, size, list))
		map = init_map(size++);
	print_final_map(list, size);		// DEBUG
//	print_map(map, size, size, '#');	// DEBUG
}
