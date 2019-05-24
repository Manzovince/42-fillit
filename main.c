/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:20:48 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/24 18:02:29 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** function that put the flags for bonus into a tab of int
**
** d : debug print (print the map during the backtracking)
** o : optimisation ultra fast but with some errors still
** p : print extended (print the tetri and the map in different formats)
** e : error extended (error message more precise AND no error for too much tetri)
*/

int		*create_dope(char *av)
{
	char	*comp;
	int		*dope;
	int		i;
	int		j;

	comp = "dope";
	if (!(dope = (int*)malloc(sizeof(*dope) * 4)))
		return (NULL);
	i = 0;
	while (i < 4)
		dope[i++] = 0;
	i = -1;
	while (++i < 4 && (j = -1))
		while (av[++j])
			if (comp[i] == av[j])
				dope[i] = 1;

	ft_putendl(av);
	i = -1;
	while (++i < 4)
		ft_putnbr(dope[i]);
	ft_putchar('\n');
	return (dope);
}

/*
** function that check if the password is good to unlock the flags
*/

int		is_mdp(int ac, char **av)
{
	char	*mdp;
	int		i;

	if (ac != 4)
		return (0);
	mdp = "trompette";
	i = 0;
	while (av[2][i] && mdp[i] && mdp[i] == av[2][i])
		i++;
	if (av[2][i] || mdp[i])
		return (0);
	return (1);
}

/*
** main function
*/

int		main(int ac, char **av)
{
	t_fillist	*list;
	char		*input;
	int			*dope;
	int			size;

	list = NULL;
	if (ac == 2 || is_mdp(ac, av))
	{
		dope = create_dope(av[3]);
		if (!(input = read_file(av[1])))
		{
			if (dope[3])
				print_error("error: Could not read file.\n");
			else
				print_error("error\n");
		}
		check_file_errors(input, dope);
		size = parse_input(input, &list, dope);

		ft_putchar('\n');						// DEBUG
		ft_putendl("result for humans :");		// DEBUG
		print_final_map(list, size, 1);			// DEBUG
		ft_putchar('\n');						// DEBUG
		ft_putendl("result for moulinette :");	// DEBUG

		print_final_map(list, size, 0);
	}
	else
		print_error("usage: Please submit a file.\n> ./fillit file.fillit\n");
	return (0);
}
