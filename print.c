/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <hulamy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:24:28 by hulamy            #+#    #+#             */
/*   Updated: 2019/05/17 17:24:54 by hulamy           ###   ########.fr       */
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

void	print_map(unsigned int *tab, int width, int height, char letter)
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
		tab[i / 32] & (1 << (31 - i % 32)) ? ft_put_tetri_color(letter) : ft_putchar('.');
		ft_putchar(' ');
		i++;
	}
	write(1, "\n", 1);
}

/*
** Print the final map with the letters
*/

void	print_final_map(t_fillist *list, int size, int flag)	// DEBUG flag vaut 0 pour imprimer comme rendu et 1 pour imprimer en couleur
{
	t_fillist	*tmp;
	char		*map;
	int			i;
	int			j;

	map = (char *)malloc(sizeof(*map) * (size * size + 1));
	map[size*size] = '\0';
	i = -1;
	while (++i < size * size)
		map[i] = '.';
	tmp = list;
	while (tmp)
	{
		j = 0;
		i = -1;
		while (++i < tmp->width * tmp->height)
		{
			if (i && i % tmp->width == 0)
				j += size - tmp->width;
			if (1 << (15 - i) & tmp->tetribit/* && tmp->test == 1*/)	// DEBUG "&& tmp->position != -1" pour imprimer les bonnes lettres au coours du debug
				map[tmp->position + i + j - 1] = tmp->letter;
		}
		tmp = tmp->next;
	}
	i = -1;
	while (++i < size * size)
	{
		if (i && i % size == 0)
			ft_putchar('\n');
		if (flag == 0)						// DEBUG imprim comme rendu
			ft_putchar(map[i]);
		else								// DEBUG imprim avec couleurs
		{
			ft_put_tetri_color(map[i]);
			ft_putchar(' ');
		}
	}
	ft_putchar('\n');
}
