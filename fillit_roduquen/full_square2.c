/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_square2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:12:29 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/01 17:12:30 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		full_square6(t_type *square, char tetri, char nbr, int pos)
{
	if (tetri == 6)
	{
		square->str[pos + 1] = nbr;
		square->str[pos + 2] = nbr;
		square->str[pos] = nbr;
		square->str[pos + square->size] = nbr;
	}
	else if (tetri == 7)
	{
		square->str[pos] = nbr;
		square->str[pos + 1] = nbr;
		square->str[pos + 2] = nbr;
		square->str[pos + square->size + 2] = nbr;
	}
	else if (tetri == 8 || tetri == 9)
	{
		square->str[(tetri == 8 ? pos : pos + 2)] = nbr;
		square->str[pos + square->size] = nbr;
		square->str[pos + 1 + square->size] = nbr;
		square->str[pos + square->size + 2] = nbr;
	}
}
