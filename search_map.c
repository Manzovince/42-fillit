/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <hulamy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:47:22 by hulamy            #+#    #+#             */
/*   Updated: 2019/05/10 17:00:08 by hulamy           ###   ########.fr       */
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
	int				j;

	mask = ~0u << (32 - list->width);	// creer un mask avec les size bits de gauche a 1 (ex: 11111110000000000000000000000000)
	j = (list->height - 1) * size + pos;
	tmp = 0;
	while (j >= pos)
	{
		tmp >>= list->width;
		tmp |= (mask & (map[j / 32] << j));
		tmp |= (mask & (map[(j + list->width) / 32] >> (32 - j)));
		j -= size;
	}
	if (!((tmp >> 16) & list->tetribit))
		return (pos + 1);
	return (0);
}

/*
** function that look for the first place in the map for a tetri
*/

int		find_place(unsigned int *tab, t_fillist *list, int size, int pos)
{
	// boucle jusqu'a la dernier place pour le tetri dans la map ou qu'il fit dans un trou
	while (pos < (size - list->height + 1) * size)
	{
		// pour ne pas deborder a droite de la map
		if (pos % size == size - list->width + 1)
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
		if (j % 32 != 1)
			map[(j + size) / 32] ^= (mask & tetri << (16 + i)) << (32 - j + 1);
		j -= size;
		i -= list->width;
	}
}

/*
** function that try to optimize the speed
** TOTAL FAILURE :p
*/

int		check_others(unsigned int *map, t_fillist *list, int size, int num)
{
	t_fillist	*tmp;
	int			dots;
	int			total;
	int			i;
	int			j;

	dots = 0;
	i = -1;
	num *= 4;
	total = size * size;
	while (++i < total && dots <= total - num)
	{
		tmp = list->next;
		j = 1;
		// saute les position pas vides
		while (1 << (i % 32) & map[i % 32])
			i++;
		// pour chaque position vide regarde si chaque tetri non encode places peuvent y rentrer
		while (j && tmp)
		{
			// si le tetri est trop a droite ou trop en bas il ne rentre pas ce n'est pas la peine de chercher donc on passe au tetri suivant
			if (tmp->width > (size - i % size) || (total - i) <= (tmp->height * size))
				tmp = tmp->next;
			// sinon verifier si on peut le mettre a cette position et si on ne peut pas passer au tetri suivant
			else if (!fit_in_place(map, list, size, i))
				tmp = tmp->next;
			// si le tetri peut rentrer on arrete la boucle en mettant j = 0
			else
				j = 0;
		}
		// si j existe c que le tetri ne pouvait pas etre place donc on rajoute 1 au compteur de point isoles
		if (j)
			dots++;
	}
	return (dots > total - num);
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
//		print_final_map(link, size); ft_putnbrendl(pos); print_map(map, size, size, '#'); ft_putchar('\n'); // DEBUG
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
