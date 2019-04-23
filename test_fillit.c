/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:05:59 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/23 13:57:22 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h> // for system call write
#include <fcntl.h> // for system call open
#include <string.h> // for memmove and strlen
#include <stdio.h> // for debug printf
#include <stdbool.h> // to use bool type

#include "libft/includes/libft.h"

/*
**	STRUCTURE
*/

typedef struct			s_fillist
{
	int					tetribit;
	int					position;
	struct s_fillist	*next;
}						t_fillist;

/*
** Function that display error message *s on fd and exit program
*/

void	print_error(char *s)
{
	write(2, s, strlen(s));
	exit(1);
}

/*
** Function that read file
*/

char	*read_file(char *file)
{
	char	buf[BUFF_SIZE];
	int		fd;
	int		rv;
	int		i;
	char	*result;

	if (((fd = open(file, O_RDONLY)) < 0) \
		|| ((rv = read(fd, &buf, BUFF_SIZE)) < 0) \
		|| !(result =  malloc(sizeof(char) * rv)))
		return (NULL);
	buf[rv] = '\0';
	i = -1;
	while (buf[++i])
		result[i] = buf[i];
	result[i] = '\0';
	close(fd);
	return (result);
}

/*
** Function to see if there if an error if the file
** - less than 4 lines
** - more than 104 (26 tetri) + 25 (\n) = 129 lines
** - two \n in a row
*/

int		check_file_errors(char *file)
{
	int		i;
	int		line_nbr;

	i = 0;
	line_nbr = 0;
	while (file[i])
	{
		if (file[i] != '.' && file[i] != '#' && file[i] != '\n')
			return (1);
		if (file[i] == '\n')
			line_nbr++;
		if (file[i] == '\n' && file[i+1] != '\0' && \
			file[i+2] != '.' && file[i+2] != '#')
			return (1);
		i++;
	}
	if (line_nbr < 4 || line_nbr > 129)
		return (1);
	return (0);
}

/*
** Function that check if tetrimino parts are linked
*/

int		check_tetri_errors2(char *tetri)
{
	int		i;

	i = 0;
	while (tetri[i])
	{
		if (tetri[i] == '.' || tetri[i] == '\n')
			i++;
		else if (tetri[i] == '#' && (tetri[i + 1] == '#' || tetri[i - 1] == '#'
				|| tetri[i + 5] == '#' || tetri[i - 5] == '#'))
			i++;
		else
			return (1);
	}
	return (0);
}

/*
** Function that check if tetrimino square contains:
** - 4 '#'
** - 12 '.'
*/

int		check_tetri_errors(char *tetri)
{
	int		i;
	int		htg;
	int		dot;

	i = 0;
	htg = 0;
	dot = 0;
	while (tetri[i])
	{
		if (tetri[i] == '#')
			htg++;
		else if (tetri[i] == '.')
			dot++;
		i++;
	}
	if (htg != 4 || dot != 12 || check_tetri_errors2(tetri))
		return (1);
	return (0);
}

/*
** Function that take char * tetri and convert to short and put it in a list
*/

int		fill_list(char *line, t_fillist *list)
{
	short	tmp;
	short	tet;
	int		i;

	i = -1;
	tet = 0;
	while (line[++i])
	{
		tet <<= 1;
		if (line[i] == '\n')
			i++;
		if (line[i] == '#')
			tet |= 1;
	}
	return (0);
}

/*
** this function create the linked list and add a new structure linked each time needed
*/

int		add_to_list(char *line, t_fillist **list)
{
	t_fillist	*tmp;

	if (!(tmp = (t_fillist*)malloc(sizeof(*tmp))))
		return (0);
	if (!(*list))
		tmp->next = NULL;
	else
		tmp->next = *list;
	*list = tmp;
	fill_list(line, *list);
	return (1);
}

/*
** Function that parse a file and put each tetrimino in a linked list
*/

int		parse_input(char *input, t_fillist list)
{
	//static t_fillist	*list = NULL;
	static int			size;
	char				tetri[20];
	int					i;
	int					j;

	i = 0;
	size = 0;
	while (input[i])
	{
		j = 0;
		while (j < 19)
			tetri[j++] = input[i++];
		tetri[19] = '\0';
		if (check_tetri_errors(tetri))
			print_error("Error: Tetrimino not valid.");
		add_to_list(tetri, &list);
		while (input[i] == '\n')
			i++;
		size++;
	}
	printf("%i\n", size);
	return (size);
}

/* *****************************************************************************
** Function that brute force with backtracking for smallest square with tetris
***************************************************************************** */

int		get_smallest_square(t_fillist list, int size, unsigned int map[])
{
	unsigned int	mask;
	int				i;
	int				j;

	i = 0;
	j = 0;
	mask = map[size];
	while (list.next != NULL)
	{
		mask = (mask >> 1) | (((1 << (i % 32)) & map[j]) << (31 - (i % 32)));
		if (!(list.tetribit & mask))
			return (1);
		i++;
	}
	return (0);
}

/* *****************************************************************************
** MAIN
***************************************************************************** */

int		main(int argc, char **argv)
{
	char		*input;
	int			map;
	int			size;
	t_fillist	list;

	if (argc == 2)
	{
		if (!(input = read_file(argv[1])))
			print_error("Error: Could not read file.\n");
		if (check_file_errors(input))
			print_error("Error: Invalid file.\n");
		size = parse_input(input, list);
		get_smallest_square(list, size, map);
		/*
		Backtracking for smallest square
		Transform tetriminos with letters
		Print result
		*/
	}
	else
		print_error("Usage: Please submit a file.\n");
	return (0);
}
