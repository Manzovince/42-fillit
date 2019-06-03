/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_i_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:12:19 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/01 17:27:29 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include <unistd.h>

int		do_i_fillit(char tetri[], int nbr)
{
	int		i;
	t_type	*square;

	i = 0;
	if (!(square = (t_type*)malloc(sizeof(t_type))))
		return (ERROR);
	while (i * i < nbr * 4)
		i++;
	if (!(square->str = (char*)malloc(sizeof(char) * (i * i + 1))))
		return (free_error(square));
	square->size = i;
	full_square_hole(square, nbr);
	i = 0;
	while (i < square->size * square->size)
		square->str[i++] = '.';
	square->str[i] = 0;
	return (do_i_fillit2(tetri, square));
}

int		do_i_fillit2(char tetri[], t_type *square)
{
	int		i;

	while (fillit(tetri, square) == ERROR)
	{
		free(square->str);
		square->size++;
		square->hole += square->size * 2 - 1;
		if (!(square->str = (char*)malloc(sizeof(char) * (square->size
			* square->size + 1))))
			return (free_error(square));
		i = 0;
		while (i < square->size * square->size)
			square->str[i++] = '.';
		square->str[i] = 0;
	}
	free(square->str);
	free(square);
	return (SUCCESS);
}

int		free_error(void *ptr)
{
	free(ptr);
	return (ERROR);
}

void	print_tab(t_type *square)
{
	int i;

	i = 0;
	while (i < square->size * square->size)
	{
		if (i != 0 && i % square->size == 0)
			write(1, "\n", 1);
		write(1, &square->str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	full_square_hole(t_type *square, int nbr)
{
	if (nbr == 1 || nbr == 4 || nbr == 9 || nbr == 16 || nbr == 25)
		square->hole = 0;
	else if (nbr == 2 || nbr == 6 || nbr == 12 || nbr == 20)
		square->hole = 1;
	else if (nbr == 3 || nbr == 8 || nbr == 15 || nbr == 24)
		square->hole = 4;
	else if (nbr == 5 || nbr == 11 || nbr == 19)
		square->hole = 5;
	else if (nbr == 7 || nbr == 14 || nbr == 23)
		square->hole = 8;
	else if (nbr == 10 || nbr == 18)
		square->hole = 9;
	else if (nbr == 13 || nbr == 22)
		square->hole = 12;
	else if (nbr == 17)
		square->hole = 13;
	else if (nbr == 21)
		square->hole = 16;
	else
		square->hole = 17;
}
