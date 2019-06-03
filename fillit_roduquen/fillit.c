/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:12:23 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/01 17:28:16 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		full_tetri(char tetri[], char buffer[], char bufftest[], int fd)
{
	int		i;

	if (fd == 26)
		return (FILE_ERROR);
	i = ft_strstr(buffer, bufftest);
	if (i == 0 || i == 21 || i == 42 || i == 63)
		tetri[fd] = -1;
	if (i == 84 || i == 105 || i == 126 || i == 147)
		tetri[fd] = 1;
	if (i == 168 || i == 189 || i == 210 || i == 231 || i == 252 || i == 273)
		tetri[fd] = -8;
	if (i == 294 || i == 315 || i == 336 || i == 357 || i == 378 || i == 399)
		tetri[fd] = 7;
	if (i == 420 || i == 441 || i == 462 || i == 483 || i == 504 || i == 525)
		tetri[fd] = -7;
	if (i == 546 || i == 567 || i == 588 || i == 609 || i == 630 || i == 651)
		tetri[fd] = 8;
	if (i == 672 || i == 693 || i == 714 || i == 735 || i == 756 || i == 777)
		tetri[fd] = -6;
	if (i == 798 || i == 819 || i == 840 || i == 861 || i == 882 || i == 903)
		tetri[fd] = 6;
	if (i == 924 || i == 945 || i == 966 || i == 987 || i == 1008 || i == 1029)
		tetri[fd] = -9;
	return (full_tetri2(i, tetri, fd));
}

int		full_tetri2(int i, char tetri[], int fd)
{
	if (i == 1050 || i == 1071 || i == 1092 || i == 1113 || i == 1134
		|| i == 1155)
		tetri[fd] = 9;
	if (i == 1176 || i == 1197 || i == 1218 || i == 1239 || i == 1260
		|| i == 1281 || i == 1302 || i == 1323 || i == 1344)
		tetri[fd] = 0;
	if (i == 1365 || i == 1386 || i == 1407 || i == 1428 || i == 1449
		|| i == 1470)
		tetri[fd] = -5;
	if (i == 1491 || i == 1512 || i == 1533 || i == 1554 || i == 1575
		|| i == 1596)
		tetri[fd] = 5;
	if (i == 1617 || i == 1638 || i == 1659 || i == 1680 || i == 1701
		|| i == 1722)
		tetri[fd] = 3;
	if (i == 1743 || i == 1764 || i == 1785 || i == 1806 || i == 1827
		|| i == 1848)
		tetri[fd] = -3;
	if (i == 1869 || i == 1890 || i == 1911 || i == 1932 || i == 1953
		|| i == 1974)
		tetri[fd] = 2;
	if (i == 1995 || i == 2016 || i == 2037 || i == 2058 || i == 2079
		|| i == 2100)
		tetri[fd] = -2;
	return (full_tetri3(i, tetri, fd));
}

int		full_tetri3(int i, char tetri[], int fd)
{
	if (i == 2121 || i == 2142 || i == 2163 || i == 2184 || i == 2205
		|| i == 2226)
		tetri[fd] = -4;
	if (i == 2247 || i == 2268 || i == 2289 || i == 2310 || i == 2331
		|| i == 2352)
		tetri[fd] = 4;
	if (tetri[fd] == 42)
		return (FILE_ERROR);
	return (SUCCESS);
}

int		fillit(char tetri[], t_type *square)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j >= 0)
	{
		if (check_square(square, tetri[j], i) == SUCCESS)
		{
			if (fillit2(square, tetri, &j, &i) == SUCCESS)
				return (SUCCESS);
		}
		else if (square->str[i])
			i++;
		else
		{
			j--;
			if (j >= 0)
				i = remove_square(square, j + 'A', tetri[j]);
		}
	}
	return (ERROR);
}

int		fillit2(t_type *square, char tetri[], int *j, int *i)
{
	full_square(square, tetri[*j], *j + 'A', *i);
	if (tetri[*j + 1] != 42 && check_hole(square, tetri, *j + 1) != SUCCESS)
		*i = remove_square(square, *j + 'A', tetri[*j]);
	else
	{
		*i = i_fillit_the_power(square, tetri, *j + 1);
		*j += 1;
	}
	if (tetri[*j] == 42)
	{
		print_tab(square);
		return (SUCCESS);
	}
	return (CONTINUE);
}
