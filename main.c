/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:20:48 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/09 11:45:36 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char				*input;

	if (argc == 2)
	{
		if (!(input = read_file(argv[1])))
			print_error("error\n");
//			print_error("error: Could not read file.\n");
		if (check_file_errors(input))
			print_error("error\n");
//			print_error("error: Invalid file.\n");
//			print_error_extended(check_file_errors(input));
		parse_input(input);
	}
	else
		print_error("usage: Please submit a file.\n> ./fillit file.fillit\n");
	return (0);
}
