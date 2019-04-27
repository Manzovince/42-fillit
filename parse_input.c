/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:48:14 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/27 15:15:53 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** DELETE BEFORE EVAL - TEST FUNCTION
** Prints a ligne of size bits
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
** Print a map of height and width
*/

void	print_map(unsigned int *tab, int width, int height)
{
	int				i;
	unsigned int	mask;

	i = 0;
	mask = 0;
	while (i++ < width)
		mask = (mask >> 1) | ((mask | 1) << 31);
	i = 0;
	while (i < width * height)
	{
		if (i && !(i % width))
			ft_putchar('\n');
		tab[i / 32] & (1 << (31 - i % 32)) ? ft_putchar('#') : ft_putchar('.');
		ft_putchar(' ');
		i++;
	}
	write(1, "\n", 1);
}

/*
** Function that transform a tab of . and # into a binary tab of int
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
*/

void	fill_list(char line[], t_fillist *list)
{
	unsigned int	tmp;
	unsigned int	mask;
	int				i;

	// transforme la ligne de . et # en un short de 0 et 1
	list->tetribit = tab_to_bin(line);
	// cree un mask avec des 1 sur la colonne de droite
	mask = (1 << 15) | (1 << 11) | (1 << 7) | (1 << 3);
	// utilise le mask pour trouver la largeur que prend le tetriminos
	i = 0;
	while (!(mask & list->tetribit) && i++ < 4)
		mask >>= 1;
	list->width = i;
	while (mask & list->tetribit && ++i < 4)
		mask >>= 1;
	list->width = i - list->width;
	// deplace le tetriminos tout en haut a gauche (i - list->width = le nombre de colonne vide a gauche)
	list->tetribit <<= (i - list->width);
	while (!(list->tetribit & (~0u << 12)))
		list->tetribit <<= 4;
	// trouve la hauteur du tetri
	i = 0;
	while (i < 4 && list->tetribit & (~0u << 28 >> (i * 4 + 16)))
		i++;
	list->height = i;
	// fabrique la ligne pour le tetriminos de la bonne largeur
	list->tetribit = reduce_tetri(list->tetribit, list->width);

	// imression pour tests
	ft_putchar('\n');
	tmp = list->tetribit;
	tmp <<= 16;
	print_map(&tmp, list->width, list->height);
	tmp >>= 16;
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
