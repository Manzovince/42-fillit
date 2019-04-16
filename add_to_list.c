/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <hulamy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:20:53 by hulamy            #+#    #+#             */
/*   Updated: 2019/04/16 16:08:24 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
** Function that fills the char **tetraminos section of the structure
** with the most little rectangle that fit the tetraminos
*/

char	**fill_tetraminos(char **square, int *tab)
{
	char	**result;
	int		height;
	int		length;
	int		i;
	int		j;

	i = 0;
	height = tab[2] - tab[0] + 1;
	length = tab[3] - tab[1] + 1;
	if (!(result = (char**)malloc(sizeof(*result) * (height + 1))))
		return (NULL);
	result[height] = NULL;
	while (i < height)
	{
		if (!(result[i] = (char*)malloc(sizeof(**result) * (length + 1))))
			return (NULL);
		result[i][length] = '\0';
		i++;
	}
	i = -1;
	while (++i < height && (j = -1))
		while (++j < length)
			result[i][j] = square[tab[0] + i][tab[1] + j];
	return (result);
}

/*
** This function calculate the line and columns where the tetraminos
** start and end, by skipping the empty lines
**
** ! it has a little bug so far, i need to fix it
*/

void	find_start_and_end(char **square, int **x)
{
	int i;

	x[0][0] = -1;
	x[0][1] = -1;
	x[0][2] = 4;
	x[0][3] = 4;
	i = 4;
	while (x[0][0] < 4 && i == 4 && !(i = 0) && square[++(x[0][0])][0] != '#')
		while (i < 4 && square[*(x[0])][i] != '#')
			i++;
	i = 4;
	while (x[0][1] < 4 && i == 4 && !(i = 0) && square[0][++(x[0][1])] != '#')
		while (i < 4 && square[i][x[0][1]] != '#')
			i++;
	i = -1;
	while (x[0][2] >= 0 && i == -1 && (i = 3) && square[--(x[0][2])][3] != '#')
		while (i >= 0 && square[x[0][2]][i] != '#')
			i--;
	i = -1;
	while (x[0][3] >= 0 && i == -1 && (i = 3) && square[3][--(x[0][3])] != '#')
		while (i >= 0 && square[i][x[0][3]] != '#')
			i--;
}

/*
** this function first call find_start_and_end to find the coordinates
** of start en end of the most little rectangle that fit the tetraminos
**
** it allows it to fill the structure with the size information
** (for instance :
** "##" ".#" ".#"
** is a tatraminos of 2 by 3)
** then it fills also the area information (2 * 3 = 6)
**
** and finally it calls fill_tetraminos to fill the char **tetraminos
*/

int		fill_list(char **square, t_fillist *list)
{
	int	*tab;

	tab = (int*)malloc(sizeof(int) * 4);
	find_start_and_end(square, &tab);
	list->size[0] = tab[3] - tab[1] + 1;
	list->size[1] = tab[2] - tab[0] + 1;
	list->area = list->size[0] * list->size[1];
	list->tetraminos = fill_tetraminos(square, tab);
	return (1);
}

/*
** this function first checks if the structure has been created
** if not, it creates the first element, else it adds an element
** and modifies the initial pointer to link to the new first element
**
** then it calls fill_list to fill the data of the structure
*/

int		add_to_list(char **square, t_fillist **list)
{
	t_fillist	*tmp;

	if (!(tmp = (t_fillist*)malloc(sizeof(*tmp))))
		return (0);
	if (!(*list))
		tmp->next = NULL;
	else
		tmp->next = *list;
	*list = tmp;
	fill_list(square, *list);
	return (1);
}

/*
**int		main(int ac, char **av)
**{
**	static t_fillist	*list = NULL;	// avant d'appeller add_to_list il faut declarer un pointeur static vers la structure
**	int					i;
**
**	if (ac > 1)
**	{
**		add_to_list(++av, &list);		// l'appel de la fonction se fait avec un carre valide de 4*4 et l'adresse du pointeur vers la liste
**		if (ac == 9)
**			add_to_list(av += 4, &list);
**		while (list && (i = -1))
**		{
**			while (++i < list->size[1])
**				printf("%s\n", list->tetraminos[i]);
**			printf("\n");
**			list = list->next;
**		}
**	}
**
**	return (0);
**}
*/
