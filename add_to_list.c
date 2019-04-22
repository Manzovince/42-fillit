/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <hulamy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:20:53 by hulamy            #+#    #+#             */
/*   Updated: 2019/04/22 15:58:39 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
//#include "libft/includes/libft.h"

/*
** this function prints a 16 bites short
*/

void	print_bits(short line)
{
	int mask;

	mask = 1 << 27;
	while (mask >>= 1)
		(line & mask) ? write(1, "1", 1) : write(1, "0", 1);
	write(1, "\n", 1);
}

/*
** this function transforme a tetrminos char* into a short of 16 bites
** then it fills it and its reverse into the list
*/

int		fill_list(char line[], t_fillist *list)
{
	short	tmp;
	int	 	test;
	int		i;

	i = 0;
	while (line[i])
	{
		list->tetribit <<= 1;
		if (line[i] == '\n')
			i++;
		if (line[i++] == '#')
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

/*
** Print octet
*/

void	print_test(int octet)
{
	unsigned int i;

	i = 1 << 31;
	while (i)
	{
		(octet & i) ? printf("1") : printf("0");
		i >>= 1;
	}
}

/*
** ???
*/

void	test(unsigned int map[])
{
	int 			i;
	int 			j;
	int 			k;
	int 			l;
	unsigned int	mask;

	mask = map[9];

	i = -1;
	j = 9;
	while (j >= 0)
	{
		if (!(++i % 32) && j-- && (k = -1))
		{
			while (++k < 10)
				print_test(map[k]);
			printf("\n");
		}
		l = 0;
		while (l++ < 320 - 32 - i)
			printf(" ");
		print_test(mask);
		printf("\n");
		mask = (mask >> 1) | (((1 << (i % 32)) & map[j]) << (31 - (i % 32)));
	}
}
/*
int		main(int ac, char **av)
{
	static t_fillist	*list = NULL;	// avant d'appeller add_to_list il faut declarer un pointeur static vers la structure
	unsigned int		map[10] = {1568713153, 817645681, 654186132, 538171355, 1718453135, 551286515, 1631843343, 3413834313, 1155555555, 999999999};
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
	test(map);

	return (0);
}
*/
