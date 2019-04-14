/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:35:48 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/14 14:27:47 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
void ft_print_fillit()
{

}
*/

void	print_test(char *test)
{
	write(1, test, strlen(test));
	write(1, "\n", 1);
}
