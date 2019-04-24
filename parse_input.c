/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:48:14 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/23 21:23:47 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function that parse a file and put each tetrimino in a linked list
*/

void	parse_input(char *input)
{
	static t_fillist	*list = NULL;
	char				tetri[20];
	int					i;
	int					j;

	i = 0;
	printf("%s", input);
	while (input[i])
	{
		j = 0;
		while (j < 19)
			tetri[j++] = input[i++];
		tetri[19] = '\0';
		if (check_tetri_errors(tetri))
			print_error("Error: Tetrimino not valid.");
		add_to_list(tetri, &list);
		printf("added to list !!\n");
		while (input[i] && input[i] != '.' && input[i] != '#')
			i++;
	}
/*DEBUG PART - Print each tetribit*/
//	while (list != NULL)
//	{
//		printf("%i\n", list->tetribit);
//		printf("\n");
//		list = list->next;
//	}
}

/*
** DELETE BEFORE EVAL - NOT USED ANYMORE
** Function that parse a file and put each tetrimino in a linked list
*/

char	**create_square(char *tetri)
{
	char	**square;
	int		i;
	int		k;

	i = 0;
	if (!(square = (char**)malloc(sizeof(*square) * (4 + 1))))
		return (NULL);
	square[4] = NULL;
	while (*tetri && (k = -1))
	{
		if (!(square[i] = (char*)malloc(sizeof(**square) * (4 + 1))))
			return (NULL);
		square[i][4] = '\0';
		while (++k < 4)
			square[i][k] = *(tetri++);
		while (*tetri == '\n')
			tetri++;
		i++;
	}
	return (square);
}
