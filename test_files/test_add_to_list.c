/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <hulamy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:20:53 by hulamy            #+#    #+#             */
/*   Updated: 2019/04/30 14:14:32 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//#include <stdio.h>

/*
** DELETE BEFORE EVAL - TEST FUNCTION
** Function that prints a 16 bites short
*/
/*
void	print_bits(short line)
{
	int mask;

	mask = 1 << 16;
	while (mask >>= 1)
		(line & mask) ? write(1, "1", 1) : write(1, "0", 1);
	write(1, "\n", 1);
}
*/

/*
** Function that transforme a tetrminos char* into a short of 16 bites
** and then fills it and its reversed into the list
*/

void	fill_list(char line[], t_fillist *list)
{
	int				i;

	i = 0;
	while (line[i])
	{
		list->tetribit <<= 1;
		if (line[i] == '\n')
			i++;
		if (line[i++] == '#')
			list->tetribit |= 1;
		print_bits(list->tetribit, 16);
	}
//	print_bits(list->tetribit);
}

/*
** Function that create the linked list and add a new structure
** linked each time needed
*/

int		add_to_list(char *line, t_fillist **list)
{
	t_fillist	*tmp;

	if (!(tmp = (t_fillist*)malloc(sizeof(*tmp))))
		return (0);
	if (!(*list))
		tmp->next = NULL;
	else
		tmp->next = *list;
	*list = tmp;
	fill_list(line, *list);
	return (1);
}

/*
** DELETE BEFORE EVAL - MAIN FOR TEST
*/

//int		main(int ac, char **av)
//{
//	static t_fillist	*list = NULL;	// avant d'appeller add_to_list il faut declarer un pointeur static vers la structure
//	int					i;
//
//	if (ac > 1)
//	{
//		add_to_list(*(++av), &list);
//		while (list && (i = -1))
//		{
//			printf("%d\n", list->tetribit);
//			print_bits(list->tetribit);
//			print_bits(list->tibirtet);
//			list = list->next;
//		}
//	}
//	return (0);
//}
