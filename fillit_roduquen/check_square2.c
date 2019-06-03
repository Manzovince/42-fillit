/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_square2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:12:15 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/01 17:26:45 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_square6(t_type *square, char tetri, int pos)
{
	if (tetri == 6
		&& (pos + 1) % square->size != 0 && (pos + 2) % square->size != 0
		&& pos + square->size < square->size * square->size
		&& square->str[pos] == '.'
		&& square->str[pos + 1] == '.'
		&& square->str[pos + square->size] == '.'
		&& square->str[pos + 2] == '.')
		return (SUCCESS);
	if (tetri == 7
		&& (pos + 1) % square->size != 0 && (pos + 2) % square->size != 0
		&& pos + 2 + square->size < square->size * square->size
		&& square->str[pos] == '.'
		&& square->str[pos + 1] == '.'
		&& square->str[pos + 2] == '.'
		&& square->str[pos + 2 + square->size] == '.')
		return (SUCCESS);
	if (tetri == 8
		&& (pos + 1) % square->size != 0 && (pos + 2) % square->size != 0
		&& pos + 2 + square->size < square->size * square->size
		&& square->str[pos] == '.'
		&& square->str[pos + 1 + square->size] == '.'
		&& square->str[pos + square->size] == '.'
		&& square->str[pos + 2 + square->size] == '.')
		return (SUCCESS);
	return (check_square7(square, tetri, pos));
}

int		check_square7(t_type *square, char tetri, int pos)
{
	if (tetri == 9
		&& (pos + 1) % square->size != 0 && (pos + 2) % square->size != 0
		&& pos + 2 + square->size < square->size * square->size
		&& square->str[pos + 2] == '.'
		&& square->str[pos + 1 + square->size] == '.'
		&& square->str[pos + square->size] == '.'
		&& square->str[pos + 2 + square->size] == '.')
		return (SUCCESS);
	return (ERROR);
}
