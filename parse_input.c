/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:48:14 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/19 12:53:40 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** !!! DELETE PRINT_BITS BEFORE EVAL !!!
*/

void	print_bits(short octet)
{
	int i;

	i = 1 << 16;
	while (i >>= 1)
		(octet & i) ? write(1, "1", 1) : write(1, "0", 1);
	printf("\n");
}


/*
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

short	create_tetribit(char *tetri)
{
	short	tetribit;
	int		i;

	i = 0;
	tetribit = 0;
	while (tetri[i])
	{
		if (tetri[i] != '\n')		// Pour comparer avec le tetri en char
			printf("%c", tetri[i]);
		if (tetri[i] == '#')
		{
			tetribit = tetribit | 1;
			tetribit <<= 1;
		}
		else
			tetribit <<= 1;
		i++;
	}
	return (tetribit);
}

void	parse_input(char *input)
{
	static t_fillist	*list = NULL;
	char				tetri[20];
	int					i;
	int					j;
	short				test; //DELETE BEFORE EVAL

	i = 0;
	printf("input: %s\n", input);
	printf("end\n");
	while (input[i])
	{
		j = 0;
		while (j < 19)
			tetri[j++] = input[i++];
		tetri[19] = '\0';
		if (check_tetri_errors(tetri))
			print_error("Error: Tetrimino not valid.");
		test = create_tetribit(tetri);
		printf("\n");
		print_bits(test);
		//test = create_square(tetri);
		//add_to_list(test, &list);
		while (input[i] == '\n')
			i++;
	}
	/*
	** ce qui suit sert juste a afficher le contenu de tous les tetraminos de la liste chainee
	** pour debug, a effacer au rendu
	*/
	while (list && (i = -1))
	{
		while (++i < list->size[1])
			printf("%s\n", list->tetraminos[i]);
		printf("\n");
		list = list->next;
	}
}
