/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:20:48 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/14 12:13:42 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	char	*input;
	short	i;

	if (argc == 2)
	{
		if (!(input = read_file(argv[1])))
			ft_display_error("Error: Could not read file.\n", 2);
//		else if (/*Elements in file not valid*/)
//			ft_display_error("Error: Invalid file.\n", 2);
		/*
		Transform input to tetriminos
		Check if every tetrimino is valid
		Backtracking for smallest square
		Transform tetriminos with letters
		Print result
		*/
		print_test(input);
	}
	else
		ft_display_error("Error: Please submit a file.\n", 2);
	return 0;
}
