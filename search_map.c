/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <hulamy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:47:22 by hulamy            #+#    #+#             */
/*   Updated: 2019/05/09 18:03:46 by hulamy           ###   ########.fr       */
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

int		check_others(unsigned int *map, t_fillist *list, int size, int num)
{
	t_fillist	*tmp;
	int			dots;
	int			total;
	int			i;
	int			j;

	dot = 0;
	i = -1;
	num *= 4;
	total = size * size;
	while (++i < total && dots <= total - num)
	{
		tmp = list->next;
		j = 1;
		while (verifier si i est un point)
			i++;
		while (j && tmp)
		{
			// si le tetri est trop a droite ou trop en bas il ne rentre pas ce n'est pas la peine de charcher
			if (tmp->width > (size - i % size) || (total - i) <= (tmp->height * size))
				tmp = tmp->next;
			else if (tmp->tetribit ne rentre pas dans la place i)
				tmp = tmp->next;
			else
				j = 0;
		}
		if (j)
			dots++;
	}
	// verifie que les tetri restant puissent un par un se placer sur la map
	// ca n'optimise qu'en fin de map donc ca ralentit les grosses map en fait
//	while ((tmp = tmp->next))
//		if (!find_place(map, tmp, size, 0))
//			return (0);
	return (1);
}

/*
** function that recursively try to fill the map with the tetris
*/

int		fill_map(unsigned int *map, t_fillist *list, int size, int num, t_fillist *link)	// DEBUG "link"
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
		print_final_map(link, size); ft_putnbrendl(pos); print_map(map, size, size, '#'); ft_putchar('\n'); // DEBUG
		if (check_others(map, list, size, num) && fill_map(map, list->next, size, num, link))
			return (1);
		add_remove(map, list, size, pos);
		list->position = -1;	// DEBUG
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
	while (!fill_map(map, list, size, num, list))
		map = init_map(size++);
	print_final_map(list, size);		// DEBUG
	print_map(map, size, size, '#');	// DEBUG
}
