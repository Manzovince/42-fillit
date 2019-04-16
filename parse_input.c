/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:48:14 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/16 11:50:45 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function that parse a file and put each tetrimino in a linked list
*/

char	**create_square(char *tetri)
{
	char	**square = NULL;
	int		i;
	int		k;

	i = 0;
	while (tetri[i])
	{
		k = 0;
		*square = malloc((sizeof(char)*4) + 1);
		while (k < 4)
		{
			*square[k] = tetri[i];
			k++;
			i++;
		}
		i++;
		//printf("print:\n%s\n", *square);
		while (tetri[i] == '\n')
			i++;
	}
	return (square);
}

void	parse_input(char *input)
{
	static t_fillist	*list = NULL;
	char				tetri[20];
	int					i;
	int					j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (j < 19)
			tetri[j++] = input[i++];
		tetri[19] = '\0';
		//printf("PRINT:\n%s\n", tetri);
		if (check_tetri_errors(tetri))
			print_error("Error: Tetrimino not valid.");
		add_to_list(create_square(tetri), &list);
		while (input[i] == '\n')
			i++;
	}
}
