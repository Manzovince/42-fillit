/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_othermethod_fillit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:25:46 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/01 20:07:41 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

typedef struct			s_fillist
{
	unsigned int		tetribit;
	int					position;
	struct s_fillist	*next;
}						t_fillist;

/* *****************************************************************************
**								TEST FUNCTION
***************************************************************************** */

void    print_bits(char *str, unsigned int bits, int size)
{
	unsigned int    mask;

	ft_putstr(str);
	mask = 1 << (size - 1);
	while (mask)
	{
		(bits & mask) ? write(1, "1", 1) : write(1, "0", 1);
		mask >>= 1;
	}
	write(1, "\n", 1);
}

void    print_tetri(unsigned int bits, int size)
{
	unsigned int    mask;
	short			i;

	i = 0;
	mask = 1 << (size - 1);
	while (mask)
	{
		if (i % 4 == 0)
			write(1, "\n", 1);
		(bits & mask) ? write(1, "#", 1) : write(1, ".", 1);
		mask >>= 1;
		i++;
	}
	write(1, "\n", 1);
}

/* *****************************************************************************
**									PROGRAM
***************************************************************************** */

void	error(char *str)
{
	ft_putstr(str);
	exit(0);
}

char	*read_file(char *file)
{
	char	buf[130];
	int	fd;
	int	rv;
	int	i;
	char	*result;

	if (((fd = open(file, O_RDONLY)) < 0) \
		|| ((rv = read(fd, &buf, 130)) < 0) \
		|| !(result =  malloc(sizeof(char) * rv)))
		return (NULL);
	buf[rv] = '\0';
	i = -1;
	while (buf[++i])
		result[i] = buf[i];
	close(fd);
	return (result);
}

unsigned int	tetribit_resize(unsigned int tetribit,
								unsigned int from_size,
								unsigned int to_size)
{
	unsigned int	mask;
	unsigned int	i;
	unsigned int	j;
	unsigned int	ret;
	unsigned int	new_tet;

	i = from_size;
	mask = 0;
	while (i--)
		mask |= (1 << i) + 1; //Cree un mask de from_size en bit
//	print_bits("tet: ", tetribit, 32);
//	print_bits("mak: ", mask, 32);
	new_tet = tetribit & mask; //initialise new_tet avec la ligne du bas de tetribit
//	print_bits("new: ", new_tet, 32);
//	ft_putstr("while\n");
	j = 0;
	while (j < from_size - 1) //pour chaque ligne du tetribit
	{
		i = 0;
		mask = 0;
		while (i != from_size) //on fait un mask sur chaque ligne
			mask |= 1 << (from_size + (from_size * j) + i++);
//		print_bits("tet: ", tetribit, 32);
//		print_bits("mak: ", mask, 32);
		ret = (tetribit & mask);
//		print_bits("rbf: ",ret, 32);
		ret = ret << (to_size - from_size + (j * (to_size - from_size)));
//		print_bits("raf: ",ret, 32);
		new_tet |= ret;
//		print_bits("new: ",new_tet, 32);
		j++;
	}
	return (new_tet);
}

unsigned int	tetri_to_binary(char line[])
{
	unsigned int	tmp;
	int				i;
	unsigned int	mask;

	i = 0;
	tmp = 0;
	while (line[i])
	{
		tmp <<= 1;
		if (line[i] == '\n')
			i++;
		if (line[i++] == '#')
			tmp |= 1;
	}
	mask = (1 << 3 | 1 << 2 | 1 << 1) + 1;
//	while ((tmp & mask) < 8) //place le tetri le plus en bas a droite possible sans le casser
//		tmp /= 2;
	print_bits("before\n", tmp, 32);
	print_bits("after\n", tetribit_resize(tmp, 4, 5), 32);
	return (tmp);
}

int		add_to_list(char *line, t_fillist **list)
{
	t_fillist	*tmp;
	t_fillist	*test;

	if (!(tmp = (t_fillist*)malloc(sizeof(*tmp))))
		return (0);
	tmp->next = NULL;
	test = *list;
	if (!test)
		*list = tmp;
	else
	{
		while(test->next)
			test = test->next;
		test->next = tmp;
	}
	tmp->tetribit = tetri_to_binary(line);
	return (1);
}

void	parse_file(char *file)
{
	static t_fillist	*list = NULL;
	char				tetri[20];
	int					i;
	int					j;

	i = 0;
	while (file[i])
	{
		if (file[i] != '.' && file[i] != '#' && file[i] != '\n')
			error("error.\n");
		j = 0;
		while (j < 19)
			tetri[j++] = file[i++];
		tetri[19] = '\0';
		add_to_list(tetri, &list);
		while (file[i] && file[i] != '.' && file[i] != '#')
			i++;
	}
}

int		solve(char *file)
{
	parse_file(read_file(file));
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		solve(av[1]);
	else
		error("usage: ./fillit [file]\n");
}
