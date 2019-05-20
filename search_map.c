/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <hulamy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:47:22 by hulamy            #+#    #+#             */
/*   Updated: 2019/05/20 15:50:12 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	OLD VERSION of find_place and fit_in_place all in one but with a lot of divisions and modulo
**
**	int		find_place(unsigned int *tab, t_fillist *list, int size, int pos)
**	{
**		int				i;
**		int				j;
**		unsigned int	mask;
**		unsigned int	tmp;
**	
**		mask = ~0u << (32 - list->width);
**		tmp = mask;
**		i = pos;
**		while (i < (size - list->height + 1) * size)
**		{
**			if (i % size == size - list->width + 1)
**				i += list->width - 1;
**			else
**			{
**				tmp = 0;
**				j = (list->height - 1) * size + i;
**				while (j >= i)
**				{
**					tmp >>= list->width;
**					tmp |= (mask & (tab[j / 32] << j));
**					tmp |= (mask & (tab[(j + list->width) / 32] >> (32 - j)));
**					j -= size;
**				}
**				if (!((tmp >> 16) & list->tetribit))
**					return (i + 1);
**				i++;
**			}
**		}
**		return (0);
**	}
*/

/*
** function that try to optimize the speed
** SECOND ATTEMPT
** by finding the isolated dots whille fillling the map
** untill they get more numerous than the max amount available
** TOTAL FAILURE :p
**
**	int		check_others(unsigned int *map, t_fillist *list, int size, int num)
**	{
**		t_fillist	*tmp;
**		int			dots;
**		int			total;
**		int			i;
**		int			j;
**	
**		dots = 0;
**		i = -1;
**		num *= 4;
**		total = size * size;
**		while (++i < total && dots <= total - num)
**		{
**			tmp = list->next;
**			j = 1;
**			// saute les position pas vides
**			while (1 << (i % 32) & map[i % 32])
**				i++;
**			// pour chaque position vide regarde si chaque tetri non encode places peuvent y rentrer
**			while (j && tmp)
**			{
**				// si le tetri est trop a droite ou trop en bas il ne rentre pas ce n'est pas la peine de chercher donc on passe au tetri suivant
**				if (tmp->width > (size - i % size) || (total - i) <= (tmp->height * size))
**					tmp = tmp->next;
**				// sinon verifier si on peut le mettre a cette position et si on ne peut pas passer au tetri suivant
**				else if (!fit_in_place(map, list, size, i))
**					tmp = tmp->next;
**				// si le tetri peut rentrer on arrete la boucle en mettant j = 0
**				else
**					j = 0;
**			}
**			// si j existe c que le tetri ne pouvait pas etre place donc on rajoute 1 au compteur de point isoles
**			if (j)
**				dots++;
**		}
**		return (dots > total - num);
**	}
*/

/*
** function that try to optimize the speed
** FIRST ATTEMPT
** by verifying if the place left is enough to place at least
** one of each tetri left
** TOTAL FAILURE :p
**
**	int		check_others(unsigned int *map, t_fillist *list, int size, int num)
**	{
**		t_fillist	*tmp;
**	
**		// verifie que les tetri restant puissent un par un se placer sur la map
**		// ca n'optimise qu'en fin de map donc ca ralentit les grosses map en fait
**		while ((tmp = tmp->next))
**			if (!find_place(map, tmp, size, 0))
**				return (0);
**		return (1);
**	}
*/

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
		tmp = (mask & (map[n] << r)) | (mask & (map[n + 1] >> (32 - r)));
		tetri <<= lst->width;
		r += size;
	}
	return (!(tmp & tetri));
}

/*
** function that look for the first place in the map for a tetri
*/

int		find_place(unsigned int *map, t_fillist *list, int size)
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

void	add_remove(unsigned int *map, t_fillist *list, int size)
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
		map[(j - 1) / 32 + 1] ^= (mask & tetri << (16 + i)) << (32 - j) << 1;
		j -= size;
		i -= list->width;
	}
}

/*
** Test optimisation for not testing wrong maps when tetri are identical
*/

int		check_tetri_memory(t_fillist *list, int pos)
{
	t_fillist		*tetri;
	unsigned int	mask;

	tetri = list;
	mask = 1 << ((pos % 32) - 1);
	if (tetri->same != NULL)
	{
		if (!(tetri->same->memory[pos / 32] & mask))
		{
			tetri->same->memory[pos / 32] |= mask;
			return (1);
		}
	}
	else
	{
		tetri->memory[pos / 32] |= mask;
		return (1);
	}
	return (0);
}

/*
** Function that recursively try to fill the map with the tetris
*/

int		fill_map(unsigned int *map, t_fillist *list, int size)
{
	if (!list)
		return (1);
	list->position = 0;
	while (find_place(map, list, size))
	{
		add_remove(map, list, size);
		if (check_tetri_memory(list, list->position))
			if (fill_map(map, list->next, size))
				return (1);
		add_remove(map, list, size);
	}
	return (0);
}

/*
** Test optimisation for not testing wrong maps when tetri are identical
*/

int		compare_tetri(t_fillist *tetri_a, t_fillist *tetri_b)
{
	if (tetri_a->tetribit != tetri_b->tetribit)
		return (0);
	if (tetri_a->width != tetri_b->width)
		return (0);
	if (tetri_a->height != tetri_b->height)
			return (0);
	return (1);
}

/*
** Test optimisation for not testing wrong maps when tetri are identical
*/

int		check_same_tetri(t_fillist *list, int num)
{
	t_fillist	*curr_tetri;
	t_fillist	*next_tetri;
	int			i;

	curr_tetri = list;
	while (curr_tetri != NULL)
	{
		i = 0;
		if (!(curr_tetri->memory = (unsigned int *)malloc(sizeof(*curr_tetri->memory) * num)))
			return (0);
		while (i < num)
			curr_tetri->memory[i++] = 0;
		next_tetri = curr_tetri->next;
		while (next_tetri != NULL)
		{
			if (compare_tetri(curr_tetri, next_tetri))
				if (next_tetri->same == NULL)
					next_tetri->same = curr_tetri;
			next_tetri = next_tetri->next;
		}
		curr_tetri = curr_tetri->next;
	}
	return (0);
}

/*
** function that send to "fill_map" a map of a certain size and increment its size untill it's solved
*/

int		search_map(t_fillist *list)
{
	t_fillist		*tmp;
	unsigned int	*map;
	int				size;
	int				num;
	int				i;

	/////////////////////////////////////////////////// TEST
	unsigned int	print;
	tmp = list;
	while (tmp)
	{
		// imression pour tests
		print = tmp->tetribit;
		print <<= 16;
		print_map(&print, tmp->width, tmp->height, tmp->letter);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	/////////////////////////////////////////////////// TEST

	size = 2;
	num = 1;
	tmp = list;
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
	ft_putendl("result in binary :");
	print_map(map, size - 1, size - 1, '#');	// DEBUG
	return (--size);
}
