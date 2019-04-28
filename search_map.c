/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:47:22 by hulamy            #+#    #+#             */
/*   Updated: 2019/04/28 16:23:19 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** DELETE BEFORE EVAL - TEST FUNCTION
** print a int in binary
*/

void	print_bits(unsigned int bits, int size)
{
	unsigned int	mask;

	mask = 1 << (size - 1);
	while (mask)
	{
		(bits & mask) ? write(1, "#", 1) : write(1, ".", 1);
		write(1, " ", 1);
		mask >>= 1;
	}
	write(1, "\n", 1);
}

/*
** DELETE BEFORE EVAL - TEST FUNCTION
** print a map of height and width
*/

void	print_map(unsigned int *tab, int width, int height)
{
	int				i;
	unsigned int	mask;

	i = 0;
	mask = ~0u << (32 - width);
	while (i < width * height)
	{
		if (i && !(i % width))
			ft_putnbrendl(i);	// pour imprimer les tailles du tableaux pour faciliter sa verification
		tab[i / 32] & (1 << (31 - i % 32)) ? ft_putchar('#') : ft_putchar('.');
		ft_putchar(' ');
		i++;
	}
	write(1, "\n", 1);
}

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
		j = list->height * size + i;
		// construit un tmp qui est une photo de la map de la taille du tetri a un emplacement donne
		while (j >= i)
		{
			tmp >>= list->width;
			tmp |= (mask & (tab[j / 32] << j));
			tmp |= (mask & (tab[(j + size) / 32] >> (32 - j)));
			j -= size;
		}
//		print_bits(tmp >> 16, 32);	// test pour imprimer la "photo de la map"
		if (!((tmp >> 16) & list->tetribit))
			return ((list->position = i + 1));
		if (i % size == size - list->width)
			i += list->width - 1;
		i++;
	}
	return (0);
}

/*
int		fill_map(unsigned int map, t_fillist *list, int size)
{
	if (!list)
		return (1);
	while (find_place(tab, list, size))
	{
		add_to_map(map, list);		// to create
		if (fill_map(map, size, list->next)
				return (1);
		remove_from_map(map, list);	// to create
		list->position++;
	}
	return (0);
}
*/

void	search_map(t_fillist *list)
{
	t_fillist		*tmp;

	//////////////////////////// TEST ////////////////////////////
	// ce tableau permet de monter jusqu'a une map de 16*16
	unsigned int	print;
	unsigned int	tab[8];
	tab[0] = 2656554334;
	tab[1] = 1394456818;
	tab[2] = 1494256918;
	tab[3] = 2656554334;
	tab[4] = 1592453883;
	tab[5] = 1444352908;
	tab[6] = 2154339230;
	tab[7] = 1576493154;
	print_map(tab, 10, 10);
	tmp = list;
	while (tmp)
	{
		// imression pour tests
		print = tmp->tetribit;
		print <<= 16;
		print_map(&print, tmp->width, tmp->height);
		ft_putnbrendl(find_place(tab, tmp, 10));
		ft_putchar('\n');
		tmp = tmp->next;
	}
	//////////////////////////// TEST ////////////////////////////

	/*
	//////////////////////////// en cours ////////////////////////////
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
	// alloue une map de la taille du nombre d'int necesaire pour contenir la taille de la map (size * size)
	map = (unsigned int *)malloc(sizeof(*map) * ((size * size) / 32 + 1));
	// lance la recursive fill_map en augmentant la taille de la map tant qu'il n'y a pas de solution
	while (!fill_map(map, list, size))
	{
		size++;
		free(map);
		map = (unsigned int *)malloc(sizeof(*map) * ((size * size) / 32 + 1));
	}
	//////////////////////////// en cours ////////////////////////////
	*/
}

