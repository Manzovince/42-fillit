/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:29:05 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/03/01 13:39:00 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_display_error(char *s, int fd)
{
	write(fd, s, strlen(s));
}

static	bool	ft_tetri_errors(char tetri[16])
{
	short	i;
	short	links_nb;
	short	tetri_blocks;
	bool	all_blocks_connected;

	i = 0;
	tetri_blocks = 0;
	while (i < 16)
	{
		if (tetri[i] == '#')
		{
			links_nb = 0; // reset links_nb to 0
			links_nb += (i % 4 != 0 && (tetri[i - 1] == '#')); // if not first column
			links_nb += (i % 4 != 3 && (tetri[i + 1] == '#')); // if not last column
			links_nb += (i / 4 != 0 && (tetri[i - 4] == '#')); // if not first row
			links_nb += (i / 4 != 3 && (tetri[i + 4] == '#')); // if not last row
			if (links_nb == 0)
				return false;
			if (links_nb > 1)
				all_blocks_connected = true;
			++tetri_blocks;
		}
		++i;
	}
	return (tetri_blocks == 4 && all_blocks_connected);
}

bool	ft_check_tetri(short tetri_nb, char tetri[tetri_nb][16])
{
	short 	count;

	count = 0;
	while (count < tetri_nb)
	{
		if (ft_tetri_errors(tetri[count++]) == false)
		{
			ft_display_error("Tetriminos is invalid.\n", 2);
			return false;
		}
	}
	return true;
}
