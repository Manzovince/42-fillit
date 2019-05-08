/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_with_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:27:22 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/08 09:02:39 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putchar_color(char c, char color)
{
	if (color == 'R')
		write(1, RED, 5);
	else if (color == 'B')
		write(1, BLU, 5);
	else if (color == 'G')
		write(1, GRN, 5);
	else if (color == 'Y')
		write(1, YEL, 5);
	else if (color == 'M')
		write(1, MAG, 5);
	else if (color == 'C')
		write(1, CYN, 5);
	else if (color == 'W' || !c)
		write(1, RESET, 5);
	ft_putchar(c);
	write(1, RESET, 5);
}

void	ft_put_tetri_color(char c)
{
	if (c == 'A' || c == 'G' || c == 'M' || c == 'S' || c == 'Y')
		ft_putchar_color(c, 'R');
	else if (c == 'B' || c == 'H' || c == 'N' || c == 'T' || c == 'Z')
		ft_putchar_color(c, 'B');
	else if (c == 'C' || c == 'I' || c == 'O' || c == 'U')
		ft_putchar_color(c, 'G');
	else if (c == 'D' || c == 'J' || c == 'P' || c == 'V')
		ft_putchar_color(c, 'Y');
	else if (c == 'E' || c == 'K' || c == 'Q' || c == 'W')
		ft_putchar_color(c, 'M');
	else if (c == 'F' || c == 'L' || c == 'R' || c == 'X')
		ft_putchar_color(c, 'C');
	else
		ft_putchar(c);
}
