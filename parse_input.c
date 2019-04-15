/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:48:14 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/15 15:10:01 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function that parse a file and return each tetrimino
*/

void	parse_input(char *input)
{
	char	*tetri;
	int		i;

	i = 0;
	while (input[i])
	{
		tetri[i] = input[i];
		if (i != 0 && i%19 == 0)
		{

			i+2;
		}
	}
}
