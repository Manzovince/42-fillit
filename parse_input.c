/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:48:14 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/18 14:17:14 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** function that transform a tab of . and # into a binary tab of int
*/

unsigned short	tab_to_bin(char line[])
{
	unsigned short	tmp;
	int				i;

	i = 0;
	tmp = 0;
	while (line[i])
	{
		tmp <<= 1;
		if (line[i] == '\n')
			i++;
		if (line[i++] == '#')
			tmp |= 1;
	}
	return (tmp);
}

/*
** Function that take a tetrimino of 4*4
** and reduce it to its right size, in binary
*/

unsigned short	reduce_tetri(unsigned short tetri, int width)
{
	unsigned int	mask;
	unsigned int	tmp;

	// cree un mask avec des 1 a gauche sur la largeur du tetriminos
	mask = ~0u << (32 - width) >> 16;
	// fabrique la ligne pour le tetriminos de la bonne largeur
	tmp = tetri;
	tmp = (mask & tetri);
	tmp |= ((mask & tetri << 4) >> width);
	tmp |= ((mask & tetri << 8) >> (2 * width));
	tmp |= ((mask & tetri << 12) >> (3 * width));
	return (tmp);
}

/*
** Function that transforme a tetriminos char* into a short of 16 bites
** and then fills it and its reversed into the list
**
** 1)	transforme la ligne de . et # en un short de 0 et 1
** 2)	cree un mask avec des 1 sur la colonne de droite (#...#...#...#...)
** 3)	utilise le mask pour trouver la largeur que prend le tetriminos
** 4)	deplace le tetriminos tout en haut a gauche
** 		(i - list->width = le nombre de colonne vide a gauche)
** 5)	trouve la hauteur du tetri
** 6)	fabrique la ligne pour le tetriminos de la bonne largeur
*/

void	fill_list(char line[], t_fillist *list)
{
	unsigned int	mask;
	int				i;

	list->tetribit = tab_to_bin(line);
	list->memory = 0;
	mask = (1 << 15) | (1 << 11) | (1 << 7) | (1 << 3);
	i = 0;
	while (!(mask & list->tetribit) && i++ < 4)
		mask >>= 1;
	list->width = i;
	while (mask & list->tetribit && ++i < 4)
		mask >>= 1;
	list->width = i - list->width;
	list->tetribit <<= (i - list->width);
	while (!(list->tetribit & (~0u << 12)))
		list->tetribit <<= 4;
	i = 0;
	while (i < 4 && list->tetribit & (~0u << 28 >> (i * 4 + 16)))
		i++;
	list->height = i;
	list->tetribit = reduce_tetri(list->tetribit, list->width);
	list->test = 0;	// DEBUG pour que print_final_map puisse imprimer correctement au fur et a mesure
}

/*
** Function that creates the linked list and add a new structure
** linked each time needed
*/

int		add_to_list(char *line, t_fillist **list, char letter)
{
	t_fillist	*tmp;
	t_fillist	*test;

	if (!(tmp = (t_fillist*)malloc(sizeof(*tmp))))
		return (0);
	tmp->next = NULL;
	test = *list;
	if (!test)
		*list = tmp;
	else
	{
		while(test->next)
			test = test->next;
		test->next = tmp;
	}
	fill_list(line, tmp);
	tmp->letter = letter;
	return (1);
}

/*
** Function that parse a file and put each tetrimino in a linked list
*/

int		parse_input(char *input, t_fillist **list)
{
	char				tetri[20];
	int					i;
	int					j;
	int					letter;

	i = 0;
	letter = 'A';
	while (input[i])
	{
		j = 0;
		while (j < 19)
			tetri[j++] = input[i++];
		tetri[19] = '\0';
		if (check_tetri_errors(tetri))
			print_error("error\n");
//			print_error("error: Wrong tetrimino.\n");
//			print_error_extended(check_tetri_errors(tetri));
		add_to_list(tetri, list, letter++);
		while (input[i] && input[i] != '.' && input[i] != '#')
			i++;
	}
	int size = search_map(*list);
	return (size);
}
