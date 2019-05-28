/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:20:48 by vmanzoni          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/05/20 13:41:00 by vmanzoni         ###   ########.fr       */
=======
/*   Updated: 2019/05/27 18:21:58 by hulamy           ###   ########.fr       */
>>>>>>> master
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

int		*create_dope(char *av, int mdp)
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
	if (!mdp)
		return (dope);
	i = -1;
	while (++i < 4 && (j = -1))
		while (av[++j])
			if (comp[i] == av[j])
				dope[i] = 1;
	return (dope);
}

/*
** function that check if the password is good to unlock the flags
*/

int		is_mdp(int ac, char **av)
{
	char	*mdp;
	int		i;

	if (ac < 3 || ac > 4)
		return (0);
	mdp = "trompette";
	i = 0;
	while (av[2][i] && mdp[i] && mdp[i] == av[2][i])
		i++;
	if (av[2][i] || mdp[i])
		return (0);
	if (ac == 3)
		return (print_flags_usage());
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
	int			mdp;

	list = NULL;
	dope = create_dope(av[3], (mdp = is_mdp(ac, av)));
	if (ac == 2 || mdp)
	{
<<<<<<< HEAD
		if (!(input = read_file(argv[1])))
			print_error("error\n");
		if (check_file_errors(input))
			print_error("error\n");
		size = parse_input(input, &list);
		ft_putnbrendl(size);
		print_final_map(list, size, 1);			// DEBUG
		print_final_map(list, size, 0);			// DEBUG
=======
		if (!(input = read_file(av[1])))
		{
			if (dope[3])
				print_error("error: Could not read file.\n");
			else
				print_error("error\n");
		}
		check_file_errors(input, dope);
		size = parse_input(input, &list, dope);
		print_final_map(list, size);
>>>>>>> master
	}
	else
		print_error("usage: Please submit a file.\n> ./fillit file.fillit\n");
	return (0);
}
