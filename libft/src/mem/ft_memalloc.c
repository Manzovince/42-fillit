/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:11:58 by hulamy            #+#    #+#             */
/*   Updated: 2019/04/03 15:42:06 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocate size byte of memory and return a pointer to the allocated memory
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tmp;

	if (!(tmp = malloc(size)))
		return (NULL);
	ft_bzero(tmp, size);
	return (tmp);
}
