/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:12:12 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/01 19:14:13 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <unistd.h>

int		check_square(t_type *square, char tetri, int pos)
{
	if (tetri == -9
		&& square->str[pos] == '.' && (pos + 1) % square->size != 0
		&& pos + 2 * square->size + 1 < square->size * square->size
		&& square->str[pos + 1] == '.'
		&& square->str[pos + square->size + 1] == '.'
		&& square->str[pos + 2 * square->size + 1] == '.')
		return (SUCCESS);
	if (tetri == -8
		&& (pos + 1) % square->size != 0
		&& pos + 2 * square->size + 1 < square->size * square->size
		&& square->str[pos + 1] == '.'
		&& square->str[pos + 2 * square->size] == '.'
		&& square->str[pos + square->size + 1] == '.'
		&& square->str[pos + 2 * square->size + 1] == '.')
		return (SUCCESS);
	if (tetri == -7
		&& (pos + 1) % square->size != 0
		&& pos + 2 * square->size < square->size * square->size
		&& square->str[pos] == '.'
		&& square->str[pos + 1] == '.'
		&& square->str[pos + square->size] == '.'
		&& square->str[pos + 2 * square->size] == '.')
		return (SUCCESS);
	return (check_square2(square, tetri, pos));
}

int		check_square2(t_type *square, char tetri, int pos)
{
	if (tetri == -6
		&& (pos + 1) % square->size != 0
		&& pos + 2 * square->size + 1 < square->size * square->size
		&& square->str[pos] == '.'
		&& square->str[pos + 2 * square->size + 1] == '.'
		&& square->str[pos + square->size] == '.'
		&& square->str[pos + 2 * square->size] == '.')
		return (SUCCESS);
	if (tetri == -5
		&& (pos + 1) % square->size != 0 && (pos + 2) % square->size != 0
		&& pos + square->size + 1 < square->size * square->size
		&& square->str[pos + 1] == '.'
		&& square->str[pos + 2] == '.'
		&& square->str[pos + square->size] == '.'
		&& square->str[pos + 1 + square->size] == '.')
		return (SUCCESS);
	if (tetri == -4
		&& (pos + 1) % square->size != 0 && (pos + 2) % square->size != 0
		&& pos + 2 + square->size < square->size * square->size
		&& square->str[pos] == '.'
		&& square->str[pos + 1] == '.'
		&& square->str[pos + square->size + 1] == '.'
		&& square->str[pos + 2 + square->size] == '.')
		return (SUCCESS);
	return (check_square3(square, tetri, pos));
}

int		check_square3(t_type *square, char tetri, int pos)
{
	if (tetri == -3
		&& (pos + 1) % square->size != 0
		&& pos + 2 * square->size < square->size * square->size
		&& square->str[pos] == '.'
		&& square->str[pos + 1 + square->size] == '.'
		&& square->str[pos + square->size] == '.'
		&& square->str[pos + 2 * square->size] == '.')
		return (SUCCESS);
	if (tetri == -2
		&& (pos + 1) % square->size != 0
		&& pos + 2 * square->size + 1 < square->size * square->size
		&& square->str[pos + 1] == '.'
		&& square->str[pos + 1 + square->size] == '.'
		&& square->str[pos + square->size] == '.'
		&& square->str[pos + 2 * square->size + 1] == '.')
		return (SUCCESS);
	if (tetri == -1
		&& (pos + 1) % square->size != 0 && (pos + 2) % square->size != 0
		&& (pos + 3) % square->size != 0
		&& pos + 3 < square->size * square->size
		&& square->str[pos] == '.' && square->str[pos + 1] == '.'
		&& square->str[pos + 3] == '.'
		&& square->str[pos + 2] == '.')
		return (SUCCESS);
	return (check_square4(square, tetri, pos));
}

int		check_square4(t_type *square, char tetri, int pos)
{
	if (tetri == 0
		&& (pos + 1) % square->size != 0
		&& pos + square->size + 1 < square->size * square->size
		&& square->str[pos] == '.'
		&& square->str[pos + 1] == '.'
		&& square->str[pos + square->size] == '.'
		&& square->str[pos + 1 + square->size] == '.')
		return (SUCCESS);
	if (tetri == 1
		&& pos + 3 * square->size < square->size * square->size
		&& square->str[pos] == '.'
		&& square->str[pos + 3 * square->size] == '.'
		&& square->str[pos + square->size] == '.'
		&& square->str[pos + 2 * square->size] == '.')
		return (SUCCESS);
	if (tetri == 2
		&& (pos + 1) % square->size != 0 && (pos + 2) % square->size != 0
		&& pos + 2 + square->size < square->size * square->size
		&& square->str[pos + 1] == '.'
		&& square->str[pos + 1 + square->size] == '.'
		&& square->str[pos + square->size] == '.'
		&& square->str[pos + 2 + square->size] == '.')
		return (SUCCESS);
	return (check_square5(square, tetri, pos));
}

int		check_square5(t_type *square, char tetri, int pos)
{
	if (tetri == 3
		&& (pos + 1) % square->size != 0 && (pos + 2) % square->size != 0
		&& pos + 1 + square->size < square->size * square->size
		&& square->str[pos] == '.'
		&& square->str[pos + 1] == '.'
		&& square->str[pos + square->size + 1] == '.'
		&& square->str[pos + 2] == '.')
		return (SUCCESS);
	if (tetri == 4
		&& (pos + 1) % square->size != 0
		&& pos + 2 * square->size < square->size * square->size
		&& square->str[pos + 1] == '.'
		&& square->str[pos + 1 + square->size] == '.'
		&& square->str[pos + square->size] == '.'
		&& square->str[pos + 2 * square->size] == '.')
		return (SUCCESS);
	if (tetri == 5
		&& (pos + 1) % square->size != 0
		&& pos + 2 * square->size + 1 < square->size * square->size
		&& square->str[pos] == '.'
		&& square->str[pos + 1 + square->size] == '.'
		&& square->str[pos + square->size] == '.'
		&& square->str[pos + 2 * square->size + 1] == '.')
		return (SUCCESS);
	return (check_square6(square, tetri, pos));
}
