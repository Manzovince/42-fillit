/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:20:48 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/20 15:51:50 by hulamy           ###   ########.fr       */
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
//			print_error("error: Could not read file.\n");
		if (check_file_errors(input))
			print_error("error\n");
//			print_error("error: Invalid file.\n");
//			print_error_extended(check_file_errors(input));
		size = parse_input(input, &list);
		ft_putchar('\n');
		ft_putendl("result for humans :");
		print_final_map(list, size, 1);			// DEBUG
		ft_putchar('\n');
		ft_putendl("result for moulinette :");
		print_final_map(list, size, 0);			// DEBUG
	}
	else
		print_error("usage: Please submit a file.\n> ./fillit file.fillit\n");
	return (0);
}
