/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:24:28 by hulamy            #+#    #+#             */
/*   Updated: 2019/05/02 00:39:56 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** DELETE BEFORE EVAL - TEST FUNCTION
** Prints a ligne of size bits
*/

void    print_bits(unsigned int bits, int size)
{
    unsigned int    mask;

    mask = 1 << (size - 1);
    while (mask)
    {
        (bits & mask) ? write(1, "#", 1) : write(1, ".", 1);
        write(1, " ", 1);
        mask >>= 1;
    }
    write(1, "\n", 1);
}

/*
** DELETE BEFORE EVAL - TEST FUNCTION
** Print a map of height and width
*/

void    print_map(unsigned int *tab, int width, int height)
{
    int             i;
    unsigned int    mask;

    i = 0;
    mask = 0;
    while (i++ < width)
        mask = (mask >> 1) | ((mask | 1) << 31);
    i = 0;
    while (i < width * height)
    {
        if (i && !(i % width))
            ft_putchar('\n');
        tab[i / 32] & (1 << (31 - i % 32)) ? ft_putchar('#') : ft_putchar('.');
        ft_putchar(' ');
        i++;
    }
    write(1, "\n", 1);
}

