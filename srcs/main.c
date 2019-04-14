/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:20:48 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/14 14:39:28 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	char	*input;

	if (argc == 2)
	{
		if (!(input = read_file(argv[1])))
			print_error("Error: Could not read file.\n");
		else if (ft_file_errors(input))
			print_error("Error: Invalid file.\n");
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
		print_error("Error: Please submit a file.\n");
	return (0);
}
