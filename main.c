/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:20:48 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/20 13:41:00 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_fillist	*list;
	char		*input;
	int			size;

	list = NULL;
	if (argc == 2)
	{
		if (!(input = read_file(argv[1])))
			print_error("error\n");
		if (check_file_errors(input))
			print_error("error\n");
		size = parse_input(input, &list);
		ft_putnbrendl(size);
		print_final_map(list, size, 1);			// DEBUG
		print_final_map(list, size, 0);			// DEBUG
	}
	else
		print_error("usage: Please submit a file.\n> ./fillit file.fillit\n");
	return (0);
}
