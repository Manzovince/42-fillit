/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:48:14 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/25 18:44:53 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	print_map(unsigned int *tab, int large, int height)
{
	int				i;
	unsigned int	mask;

	i = 0;
	mask = 0;
	while (i++ < large)
		mask = (mask >> 1) | ((mask | 1) << 31);
	i = 0;
	while (i < large * height)
	{
		if (!(i % large))
			ft_putchar('\n');
		tab[i / 32] & (1 << (31 - i % 32)) ? ft_putchar('#') : ft_putchar('.');
		ft_putchar(' ');
		i++;
	}
	write(1, "\n", 1);
}

/*
** Function that transforme a tetrminos char* into a short of 16 bites
** and then fills it and its reversed into the list
*/

void	fill_list(char line[], t_fillist *list)
{
	unsigned int	tmp;
	unsigned short	mask;
	int				i;

	i = 0;
	// transforme la ligne de . et # en un short de 0 et 1
	while (line[i])
	{
		list->tetribit <<= 1;
		if (line[i] == '\n')
			i++;
		if (line[i++] == '#')
			list->tetribit |= 1;
	}
	// deplace le tetriminos tout en haut a gauche
	while (!(list->tetribit & (1 << 15)))
		list->tetribit <<= 1;
	// cree un mask avec des 1 sur la colonne de droite
	mask = (1 << 15) | (1 << 11) | (1 << 7) | (1 << 3);
	// utilise le mask pour trouver la largeur que prend le tetriminos
	i = -1;
	while (i++ < 4 && mask & list->tetribit)
		mask >>= 1;
	list->large = i;
	// cree un mask avec des 1 a gauche sur la largeur du tetriminos
	mask = ~0;
	mask <<= 16 - i;
	// fabrique la ligne pour le tetriminos de la bonne largeur
	tmp = list->tetribit;
	list->tetribit = (mask & tmp) | ((mask & tmp << 4) >> i);
	list->tetribit |= ((mask & tmp << 8) >> 2 * i);
	list->tetribit |= ((mask & tmp << 12) >> 3 * i);
	// trouve la hauteur du tetri
	i = 1;
	print_bits(tmp, 32);
	while (i && !(tmp & 1 << i))
		i++;
	ft_putnbrendl((16 - i) / 4 + ((16 - i) % 4 != 0));
	list->height = ((16 - i) / 4 + ((16 - i) % 4 != 0));

	tmp = list->tetribit;
	tmp <<= 16;
	print_map(&tmp, list->large, 4);
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

