/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:20:48 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/15 00:12:25 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*input;

	if (argc == 2)
	{
		if (!(input = read_file(argv[1])))
			print_error("Error: Could not read file.\n");
		if (check_file_errors(input))
			print_error("Error: Invalid file.\n");
		if (check_tetri_errors(input))
			print_error("Error: Tetrimino not valid.\n");
		/*
		Check if every tetrimino is valid
		Transform input to tetriminos
		Backtracking for smallest square
		Transform tetriminos with letters
		Print result
		*/
		print_test(input);
	}
	else
		print_error("Usage: Please submit a file.\n");
	return (0);
}
