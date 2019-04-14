/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:20:53 by hulamy            #+#    #+#             */
/*   Updated: 2019/04/14 19:11:50 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

int		find_start_and_end(char *square)
{
	int i;

	i = -1;
	while (++i < 4)
		printf("%c",square[0] + i);
	return (i);
}

void	reduce_tetraminos(char **square, t_fillist *list)
{
	int	start;

	start = find_start_and_end(square[1]);
	(void)list;
}

int		add_to_list(char **square)
{
	t_fillist	*list;

	square++;
	if (!(list = (t_fillist*)malloc(sizeof(*list))))
		return (0);
	reduce_tetraminos(square, list);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 5)
	{
		add_to_list(av);
	}
	return (0);
}
