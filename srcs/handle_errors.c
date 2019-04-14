/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:29:05 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/14 12:06:40 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_display_error(char *s, int fd)
{
	write(fd, s, strlen(s));
}

/*
int		ft_tetri_erros()
{

}
*/
