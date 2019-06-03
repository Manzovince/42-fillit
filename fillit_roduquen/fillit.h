/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:28:32 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/01 19:01:09 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
** MACROS
*/

# define SUCCESS 0
# define ERROR -1
# define READ_ERROR -2
# define OPEN_ERROR -3
# define FILE_ERROR -4
# define CONTINUE 1
# define BUFF_SIZE 2372

/*
** TYPEDEF && STRUCTURES
*/

typedef struct		s_type
{
	int		size;
	int		hole;
	char	*str;
	char	isl[170];
}					t_type;

/*
** PROTOTYPES
*/

int					fillit(char tetri[], t_type *square);
int					fillit2(t_type *square, char tetri[], int *j, int *i);
void				full_square(t_type *square, char tetri, char nbr, int pos);
void				full_square2(t_type *square, char tetri, char nbr, int pos);
void				full_square3(t_type *square, char tetri, char nbr, int pos);
void				full_square4(t_type *square, char tetri, char nbr, int pos);
void				full_square5(t_type *square, char tetri, char nbr, int pos);
void				full_square6(t_type *square, char tetri, char nbr, int pos);
int					check_square(t_type *square, char tetri, int pos);
int					check_square2(t_type *square, char tetri, int pos);
int					check_square3(t_type *square, char tetri, int pos);
int					check_square4(t_type *square, char tetri, int pos);
int					check_square5(t_type *square, char tetri, int pos);
int					check_square6(t_type *square, char tetri, int pos);
int					check_square7(t_type *square, char tetri, int pos);
int					remove_square(t_type *square, char nbr, char type);
int					i_fillit_the_power(t_type *square, char tetri[], int pos);
int					i_got_a_fillit(int check_fd);
int					check_file(char bufftest[], char tetri[], char buffer[],
		int fd);
int					free_error(void *ptr);
int					do_i_fillit(char tetri[], int nbr);
int					do_i_fillit2(char tetri[], t_type *square);
void				print_tab(t_type *square);
int					full_tetri(char tetri[], char buffer[], char bufftest[],
		int fd);
int					full_tetri2(int i, char tetri[], int fd);
int					full_tetri3(int i, char tetri[], int fd);
int					ft_strstr(char haystack[], char needle[]);
int					chose_type(char type, int ret);
int					check_hole(t_type *square, char tetri[], int to_test);
void				full_square_hole(t_type *square, int nbr);
int					ft_check_square(int i, t_type *square, char nbr);
int					ft_check_square2(int i, t_type *square, char nbr);
int					ft_check_square3(int i, t_type *square, char nbr);
int					ft_check_square4(int i, t_type *square, char nbr);
int					ft_check_square5(int i, t_type *square, char nbr);
int					ft_check_square6(int i, t_type *square, char nbr);
int					count_island(t_type *square, int i, char tetri[],
		int to_test);
void				full_count_island_square(t_type *square, char nbr);
int					count_hole(t_type *square, char nbr, char tetri[],
		int to_test);
void				ft_memset(void	*ptr, char c, int len);
int					check_new_possibility(t_type *square, char nbr,
		char tetri[], int to_test);

#endif
