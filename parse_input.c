/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:48:14 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/15 21:33:52 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function that parse a file and put each tetrimino in a linked list
*/

void	parse_input(char *input)
{
	//static t_fillist	*list = NULL;
	char				**square;
	int					i;
	int					j;
	int					k;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
				square[j][k++] = input[i++];
			j++;
		}
		printf("print:\n%s\n", *square);
		//add_to_list(square, &list);
		while (input[i] == '\n')
			i++;
	}
}

/*
void	parse_input(char *input)
{
	//static t_fillist	*list = NULL;
	char				square[19];
	int					i;
	int					j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (j < 19)
			square[j++] = input[i++];
		square[19] = '\0';
		printf("PRINT:\n%s\n", square);
		//add_to_list(square, &list);
		while (input[i] == '\n')
			i++;
	}
}
*/
