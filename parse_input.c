/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:48:14 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/25 14:59:45 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function that transforme a tetrminos char* into a short of 16 bites
** and then fills it and its reversed into the list
*/

void	fill_list(char line[], t_fillist *list)
{
	unsigned short	tmp;
	int				i;

	i = 0;
	while (line[i])
	{
		list->tetribit <<= 1;
		if (line[i] == '\n')
			i++;
		if (line[i++] == '#')
			list->tetribit |= 1;
	}
	while (!(list->tetribit & (1 << 15)))
		list->tetribit <<= 1;
	tmp = list->tetribit;
	while (tmp)
	{
		list->tibirtet <<= 1;
		if (tmp & 1)
			list->tibirtet |= 1;
		tmp >>= 1;
	}
}

/*
** Function that creates the linked list and add a new structure
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
** Function that parse a file and put each tetrimino in a linked list
*/

void	parse_input(char *input)
{
	static t_fillist	*list = NULL;
	char				tetri[20];
	int					i;
	int					j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (j < 19)
			tetri[j++] = input[i++];
		tetri[19] = '\0';
		if (check_tetri_errors(tetri))
			print_error("Error: Tetrimino not valid.");
		add_to_list(tetri, &list);
		while (input[i] && input[i] != '.' && input[i] != '#')
			i++;
	}
}

