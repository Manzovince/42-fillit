/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:12:25 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/01 17:29:03 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		full_square(t_type *square, char tetri, char nbr, int pos)
{
	if (tetri == -9)
	{
		square->str[pos] = nbr;
		square->str[pos + 1] = nbr;
		square->str[pos + square->size + 1] = nbr;
		square->str[pos + 2 * square->size + 1] = nbr;
	}
	else if (tetri == -8)
	{
		square->str[pos + 1] = nbr;
		square->str[pos + 1 + square->size] = nbr;
		square->str[pos + 2 * square->size] = nbr;
		square->str[pos + 2 * square->size + 1] = nbr;
	}
	else if (tetri == -7)
	{
		square->str[pos] = nbr;
		square->str[pos + 1] = nbr;
		square->str[pos + square->size] = nbr;
		square->str[pos + 2 * square->size] = nbr;
	}
	else
		full_square2(square, tetri, nbr, pos);
}

void		full_square2(t_type *square, char tetri, char nbr, int pos)
{
	if (tetri == -6)
	{
		square->str[pos] = nbr;
		square->str[pos + square->size] = nbr;
		square->str[pos + 2 * square->size] = nbr;
		square->str[pos + 2 * square->size + 1] = nbr;
	}
	else if (tetri == -5)
	{
		square->str[pos + 1] = nbr;
		square->str[pos + 2] = nbr;
		square->str[pos + square->size] = nbr;
		square->str[pos + square->size + 1] = nbr;
	}
	else if (tetri == -4)
	{
		square->str[pos] = nbr;
		square->str[pos + 1] = nbr;
		square->str[pos + square->size + 1] = nbr;
		square->str[pos + square->size + 2] = nbr;
	}
	else
		full_square3(square, tetri, nbr, pos);
}

void		full_square3(t_type *square, char tetri, char nbr, int pos)
{
	if (tetri == -3)
	{
		square->str[pos] = nbr;
		square->str[pos + square->size] = nbr;
		square->str[pos + square->size + 1] = nbr;
		square->str[pos + 2 * square->size] = nbr;
	}
	else if (tetri == -2)
	{
		square->str[pos + 1] = nbr;
		square->str[pos + 1 + square->size] = nbr;
		square->str[pos + square->size] = nbr;
		square->str[pos + 2 * square->size + 1] = nbr;
	}
	else if (tetri == -1)
	{
		square->str[pos] = nbr;
		square->str[pos + 1] = nbr;
		square->str[pos + 2] = nbr;
		square->str[pos + 3] = nbr;
	}
	else
		full_square4(square, tetri, nbr, pos);
}

void		full_square4(t_type *square, char tetri, char nbr, int pos)
{
	if (tetri == 0)
	{
		square->str[pos] = nbr;
		square->str[pos + 1] = nbr;
		square->str[pos + square->size] = nbr;
		square->str[pos + square->size + 1] = nbr;
	}
	else if (tetri == 1)
	{
		square->str[pos] = nbr;
		square->str[pos + square->size] = nbr;
		square->str[pos + square->size * 2] = nbr;
		square->str[pos + 3 * square->size] = nbr;
	}
	else if (tetri == 2)
	{
		square->str[pos + 1] = nbr;
		square->str[pos + 1 + square->size] = nbr;
		square->str[pos + square->size] = nbr;
		square->str[pos + square->size + 2] = nbr;
	}
	else
		full_square5(square, tetri, nbr, pos);
}

void		full_square5(t_type *square, char tetri, char nbr, int pos)
{
	if (tetri == 3)
	{
		square->str[pos] = nbr;
		square->str[pos + 1] = nbr;
		square->str[pos + 2] = nbr;
		square->str[pos + square->size + 1] = nbr;
	}
	else if (tetri == 4)
	{
		square->str[pos + 1] = nbr;
		square->str[pos + 1 + square->size] = nbr;
		square->str[pos + square->size] = nbr;
		square->str[pos + 2 * square->size] = nbr;
	}
	else if (tetri == 5)
	{
		square->str[pos] = nbr;
		square->str[pos + square->size] = nbr;
		square->str[pos + square->size + 1] = nbr;
		square->str[pos + 2 * square->size + 1] = nbr;
	}
	else
		full_square6(square, tetri, nbr, pos);
}
