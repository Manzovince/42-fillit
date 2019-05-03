/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:24:28 by hulamy            #+#    #+#             */
/*   Updated: 2019/05/03 14:19:51 by hulamy           ###   ########.fr       */
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
** Print the final map with the letters
*/

void	print_final_map(t_fillist *list, int size)
{
//	unsigned int	print;	
	t_fillist	*tmp;
	char		*map;
	int			i;
	int			j;

	map = (char *)malloc(sizeof(*map) * (size * size + 1));
	map[size*size] = '\0';
//	i = -1;
//	while (++i < size * size)
//		map[i] = '.';
	tmp = list;
	while (tmp)
	{
		j = 0;
		i = -1;
		while (++i < tmp->width * tmp->height)
		{
//			ft_putchar('\n');
//			print = tmp->tetribit << 16;
//			print_map(&print, tmp->width, tmp->height);
//			print_bits(tmp->tetribit, 16);
//			print_bits(1 << (15 - i), 16);
//			(1 >> i & tmp->tetribit) ? ft_putchar('1') : ft_putchar('.');
			if (i && i + 1 % tmp->width == 0)
				j += size;
			if (1 << (15 - i) & tmp->tetribit)
				map[tmp->position + i + j] = tmp->letter;
			else
				map[tmp->position + i + j] = '.';
		}
		tmp = tmp->next;
	}
	i = -1;
	while (++i < size * size)
	{
		if (i && i % size == 0)
			ft_putchar('\n');
		ft_putchar(map[i]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
}

