/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <hulamy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:20:53 by hulamy            #+#    #+#             */
/*   Updated: 2019/04/19 23:02:00 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include "libft/includes/libft.h"

/*
** this function prints a 16 bites short
*/

void	print_bits(short line)
{
	int mask;

	mask = 1 << 27;
	while (mask >>= 1)
		(line & mask) ? ft_putnbr(1) : ft_putnbr(0);
	ft_putchar('\n');
}

/*
** this function transforme a tetrminos char* into a short of 16 bites
** then it fills it and its reverse into the list
*/

int		fill_list(char *line, t_fillist *list)
{
	short	tmp;
	int	 	test;

	while (*line)
	{
		list->tetribit <<= 1;
		if (*line == '\n')
			line++;
		if (*(line++) == '#')
			list->tetribit |= 1;
	}
	tmp = list->tetribit;
	while (tmp)
	{
		if (tmp & 1)
			list->tibirtet |= 1;
		list->tibirtet <<= 1;
		tmp >>= 1;
	}
	test = list->tibirtet;
	print_bits(test);
	while (test <<= 1)
		print_bits(test);
	return (0);
}

/*
** this function create the linked list and add a new structure linked each time needed
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

int		main(int ac, char **av)
{
	static t_fillist	*list = NULL;	// avant d'appeller add_to_list il faut declarer un pointeur static vers la structure
	int					i;

	if (ac > 1)
	{
		add_to_list(*(++av), &list);
		while (list && (i = -1))
		{
			printf("%d\n", list->tetribit);
			print_bits(list->tetribit);
			print_bits(list->tibirtet);
			list = list->next;
		}
	}

	return (0);
}

