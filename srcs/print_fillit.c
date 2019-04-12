/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:35:48 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/03/01 13:37:45 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_print_fillit(short tetri_nb, char tetri[tetri_nb][16])
{
	short count;
	short i;

	count = 0;
	while (count < tetri_nb)
	{
		i = 0;
		while (i < 16)
		{
			write(1, &tetri[count][i], 1);
			if (i++ % 4 == 3)
				write(1, "\n", 1);
		}
		write(1, "\n", 1);
		++count;
	}
}
