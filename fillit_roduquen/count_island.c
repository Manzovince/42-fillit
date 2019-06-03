/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:12:17 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/01 19:13:25 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <unistd.h>

int		count_island(t_type *square, int i, char tetri[], int to_test)
{
	char	nbr;

	ft_memset(square->isl, '.', 170);
	nbr = 'a';
	while (1)
	{
		i = 0;
		while (square->str[i])
		{
			if (square->isl[i] == '.' && square->str[i] == '.')
				break ;
			i++;
		}
		if (square->str[i])
			square->isl[i] = nbr;
		else
			return (count_hole(square, nbr, tetri, to_test));
		full_count_island_square(square, nbr);
		nbr++;
	}
	return (ERROR);
}

void	full_count_island_square(t_type *square, char nbr)
{
	int		i;
	int		j;

	i = 0;
	while (i < square->size * 2)
	{
		j = 0;
		while (square->str[j])
		{
			if (square->str[j] == '.' && square->isl[j] == '.')
				ft_check_square(j, square, nbr);
			j++;
		}
		i++;
	}
}

int		count_hole(t_type *square, char nbr, char tetri[], int to_test)
{
	int		i;
	int		nbr_hole;
	int		total;

	total = 0;
	while (nbr >= 'a')
	{
		i = 0;
		nbr_hole = 0;
		while (i < square->size * square->size)
		{
			if (square->isl[i] == nbr)
				nbr_hole++;
			i++;
		}
		if (nbr_hole == 4)
			total += check_new_possibility(square, nbr, tetri, to_test);
		else
			total += nbr_hole % 4;
		nbr--;
	}
	return (total);
}

int		check_if_placing_tetri_is_possible(t_type *square, char tetri[],
			int to_test, int i)
{
	while (tetri[to_test] != 42)
	{
		if (tetri[to_test] == -9 || tetri[to_test] == -7
			|| tetri[to_test] == -6 || tetri[to_test] == -4
			|| tetri[to_test] == -3 || tetri[to_test] == -1
			|| tetri[to_test] == 0 || tetri[to_test] == 1
			|| tetri[to_test] == 3 || tetri[to_test] == 5
			|| tetri[to_test] == 6 || tetri[to_test] == 7
			|| tetri[to_test] == 8)
		{
			if (check_square(square, tetri[to_test], i) == SUCCESS)
				return (0);
		}
		else if (tetri[to_test] == -8 || tetri[to_test] == -5
			|| tetri[to_test] == -2 || tetri[to_test] == 2
			|| tetri[to_test] == 4)
		{
			if (check_square(square, tetri[to_test], i - 1) == SUCCESS)
				return (0);
		}
		else if (check_square(square, tetri[to_test], i - 2) == SUCCESS)
			return (0);
		to_test++;
	}
	return (4);
}

int		check_new_possibility(t_type *square, char nbr, char tetri[],
			int to_test)
{
	int		i;

	i = 0;
	while (square->isl[i] != nbr)
		i++;
	return (check_if_placing_tetri_is_possible(square, tetri, to_test, i));
}
