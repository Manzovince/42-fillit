/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:34:46 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/03/01 13:35:08 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h> // for system call write
#include <fcntl.h> // for system call open
#include <string.h> // for memmove and strlen
#include <stdio.h> // for debug printf
#include <stdbool.h> // to use bool type

# define BUFFER_SIZE 1024
