/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:42:46 by hulamy            #+#    #+#             */
/*   Updated: 2019/06/01 13:46:56 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Test optimisation for not testing wrong maps when tetri are identical
*/

int		check_tetri_memory(t_fillist *list, int pos)
{
	t_fillist		*tetri;
	unsigned int	mask;

	tetri = list;
	mask = 1 << ((pos % 32) - 1);
	if (tetri->same)
	{
		if (!(tetri->same->memory[pos / 32] & mask))
			return (tetri->same->memory[pos / 32] |= mask);
	}
	else
	{
		if (!(tetri->memory[pos / 32] & mask))
			return (tetri->memory[pos / 32] |= mask);
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
** Function that free the list->memory each time it's malloc
*/

t_fillist	*clean_list_memory(t_fillist *list, t_fillist *tmp)
{
	while (tmp)
	{
		if (tmp->memory)
			free(tmp->memory);
		tmp = tmp->next;
	}
	return (list);
}

/*
** Test optimisation for not testing wrong maps when tetri are identical
*/

int		check_same_tetri(t_fillist *list, int num)
{
	t_fillist	*curr_tetri;
	t_fillist	*next_tetri;
	int			i;

	curr_tetri = clean_list_memory(list, list);
//	curr_tetri = list;
	while (curr_tetri != NULL)
	{
		i = 0;
		if (!(curr_tetri->memory =
					(unsigned int *)malloc(sizeof(*curr_tetri->memory) * num)))
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
		curr_tetri->total_num = num;
		curr_tetri = curr_tetri->next;
	}
	return (0);
}
