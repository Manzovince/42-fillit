/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_with_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:27:22 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/04 19:08:25 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putchar_red(char c)
{
	write(1, RED, 5);
	ft_putchar(c);
	write(1, RESET, 5);
}

void ft_putchar_blue(char c)
{
	write(1, BLU, 5);
	ft_putchar(c);
	write(1, RESET, 5);
}

void ft_putchar_green(char c)
{
	write(1, GRN, 5);
	ft_putchar(c);
	write(1, RESET, 5);
}

void ft_putchar_yellow(char c)
{
	write(1, YEL, 5);
	ft_putchar(c);
	write(1, RESET, 5);
}

void ft_putchar_magenta(char c)
{
	write(1, MAG, 5);
	ft_putchar(c);
	write(1, RESET, 5);
}

void ft_putchar_cyan(char c)
{
	write(1, CYN, 5);
	ft_putchar(c);
	write(1, RESET, 5);
}

void	ft_put_tetri_color(char c)
{
	if (c == 'A' || c == 'I' || c == 'O' || c == 'U')
		ft_putchar_red(c);
	else if (c == 'B' || c == 'J' || c == 'P' || c == 'V')
		ft_putchar_blue(c);
	else if (c == 'C' || c == 'K' || c == 'Q' || c == 'W')
		ft_putchar_green(c);
	else if (c == 'D' || c == 'L' || c == 'R' || c == 'X')
		ft_putchar_yellow(c);
	else if (c == 'E' || c == 'M' || c == 'S' || c == 'Y')
		ft_putchar_magenta(c);
	else if (c == 'F' || c == 'N' || c == 'T' || c == 'Z')
		ft_putchar_cyan(c);
	else
		ft_putchar(c);
}
