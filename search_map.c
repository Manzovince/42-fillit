/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <hulamy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:47:22 by hulamy            #+#    #+#             */
/*   Updated: 2019/05/06 23:23:40 by hulamy           ###   ########.fr       */
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
//		tests pour trouver la nouvelle equation
//		ft_putstr("[j:"); ft_putnbr(j); ft_putstr("] [32 - j:"); ft_putnbr(32 - j); ft_putstr("] [i:"); ft_putnbr(i); ft_putstr("] [pos:"); ft_putnbr(pos); ft_putendl("]");
//		ft_putstr("map[j / 32]         :"); print_bits(map[j / 32], 32);
//		ft_putstr("mask                :"); print_bits((mask & list->tetribit << (16 + i)) >> (j - 1), 32);
//		ft_putstr("map[] ^ mask        :"); print_bits((map[j / 32] ^ (mask & list->tetribit << (16 + i)) >> (j - 1)), 32);
		map[j / 32] ^= (mask & tetri << (16 + i)) >> (j - 1);
//		ft_putchar('\n');
//		ft_putstr("map[(j + size) / 32]:"); print_bits(map[(j + size) / 32], 32);
//		ft_putstr("mask                :"); print_bits((mask & list->tetribit << (16 + i)), 32);
//		ft_putstr("mask                :"); print_bits((mask & list->tetribit << (16 + i)) << (32 - j), 32);
//		ft_putstr("map[] ^ mask        :"); print_bits(map[(j + size) / 32] ^ (mask & list->tetribit << (16 + i)) << (32 - j), 32);
//		ft_putchar('\n');
		map[(j + size) / 32] ^= (mask & tetri << (16 + i)) << (32 - j);
		j -= size;
		i -= list->width;
	}
}

/*
** function that recursively try to fill the map with the tetris
*/

int		fill_map(unsigned int *map, t_fillist *list, int size, t_fillist *link)
{
	int	pos;

	pos = 0;
	if (!list)
		return (1);
	while ((pos = find_place(map, list, size, pos)))
	{
		add_remove(map, list, size, pos);
		list->position = pos;
//		print_final_map(link, size);		// DEBUG tente imprime la map avec des lettres
//		print_map(map, size, size, '#');	// DEBUG
		if (fill_map(map, list->next, size, link))
			return (1);
		add_remove(map, list, size, pos);
		list->position = -1;
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





	//////////////////////////// TEST ////////////////////////////
//	// ce tableau permet de monter jusqu'a une map de 16*16
	unsigned int	print;
//	unsigned int	tab[8];
//	tab[0] = 2656554334;
//	tab[1] = 1394456818 ^ (1 << 11 | 1 << 22 | 1 << 4);
//	tab[2] = 1494256918;
//	tab[3] = 2656554334;
//	tab[4] = 1592453883;
//	tab[5] = 1444352908;
//	tab[6] = 2154339230;
//	tab[7] = 1576493154;
//	print_map(tab, 10, 10, '#');
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
//	// quand add_remove_marchera la ligne d'apres imprimera la map avec les pixels du tetri rajoutes a la bonne place
//		tmp = list;
//		while (tmp)
//		{
//			print = tmp->tetribit;
//			print <<= 16;
//			print_map(&print, tmp->width, tmp->height, '#');		// test, imprime le tetri
//			ft_putnbrendl(find_place(tab, tmp, 10, 0));
//			add_remove(tab, tmp, 10, find_place(tab, tmp, 10, 0));
//			ft_putchar('\n');					// DEBUG
//			print_map(tab, 10, 10, '#');
//			ft_putchar('\n');					// DEBUG
//			tmp = tmp->next;
//		}
	//////////////////////////// TEST ////////////////////////////





	// lance la recursive fill_map en augmentant la taille de la map tant qu'il n'y a pas de solution
	while (!fill_map(map, list, size, list))
		map = init_map(size++);
	print_final_map(list, size);	// DEBUG
	print_map(map, size, size, '#');
}
