/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:20:48 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/03 19:12:47 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char				*input;

	if (argc == 2)
	{
		if (!(input = read_file(argv[1])))
			print_error("error: Could not read file.\n");
		if (check_file_errors(input))
			print_error_extended(check_file_errors(input));
//		print_error("error: Invalid file.\n");
		parse_input(input);
		/*
		Backtracking for smallest square
		Transform tetriminos with letters & Print result
		*/
	}
	else
		print_error("usage: Please submit a file.\n> ./fillit file.fillit\n");
	return (0);
}
