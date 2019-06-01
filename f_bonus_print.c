/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_bonus_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <hulamy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:46:29 by hulamy            #+#    #+#             */
/*   Updated: 2019/06/01 14:17:43 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** function that print the given tetris if flag p is present
*/

t_fillist	*print_tetri(t_fillist *list)
{
	unsigned int	print;
	t_fillist		*tmp;

	tmp = list;
	if (list->dope[2])
	{
		while (tmp)
		{
			check_same_tetri(list, 1);
			print = tmp->tetribit;
			print <<= 16;
			print_sized_map(&print, tmp->width, tmp->height, tmp->letter);
			if (tmp->same && list->dope[1])
			{
				print = tmp->same->tetribit;
				print <<= 16;
				ft_putstr("same --> ");
				ft_put_tetri_color(tmp->same->letter);
				ft_putchar('\n');
			}
			ft_putchar('\n');
			tmp = tmp->next;
		}
	}
	return (list);
}

/*
** function that print the map in binary if flag p is present
** it returns anyway the size of the map for main to print it
*/

int			print_binary_map(unsigned int *map, int size, int *dope)
{
	size--;
	if (dope[2])
	{
		ft_putendl("result in binary :");
		print_sized_map(map, size, size, '#');
		ft_putchar('\n');
	}
	free(map);
	return (size);
}

/*
** function that print the flags usage
*/

int			print_flags_usage(void)
{
	ft_putendl("flags usage :");
	ft_putendl("d : debug print (print the map during the backtracking)");
	ft_putendl("o : optimisation ultra fast but with some errors still");
	ft_putendl("p : print the tetri and the map in different formats");
	ft_putendl("e : error msgs more precise AND no error for too much tetri\n");
	return (0);
}
