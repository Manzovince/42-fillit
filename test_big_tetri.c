#include "./libft/includes/libft.h"

void	print_bits(unsigned int bits, int size)
{
	unsigned int	mask;

	mask = 1 << (size - 1);
	while (mask)
	{
		(bits & mask) ? write(1, "#", 1) : write(1, ".", 1);
		write(1, " ", 1);
		mask >>= 1;
	}
	write(1, "\n", 1);
}

void	print_map(unsigned int *tab, int s)
{
	int				i;
	unsigned int	m;
	unsigned int	tmp;

	i = 0;
	m = 0;
	// creer un mask avec les size bits de gauche a 1 (ex: 11111110000000000000000000000000)
	while (i++ < s)
		m = (m >> 1) | ((m | 1) << 31);
	write(1, "\n", 1);
	i = 0;
	while (i < s * s)
	{
//		/*
//		** first version :
//		**
//		** tmp = ((m >> i) & tab[i / 32]) << i;
//		** tmp |= ((m << (32 - i)) & tab[(i + s) / 32]) >> (32 - i);
//		** tmp >>= 32 - s;
//		** print_bits(tmp, s);
//		** i += s;
//		*/
//
//		tmp = (m & (tab[i / 32] << i)) | (m & (tab[(i + s) / 32] >> (32 - i)));
//		print_bits(tmp >> (32 - s), s);
//		i += s;

		/*
		** second version :
		** n'utilise pas le mask m et le tmp
		*/
		if (!(i % s))
			ft_putchar('\n');
		tab[i / 32] & (1 << (31 - i % 32)) ? ft_putchar('#') : ft_putchar('.');
		ft_putchar(' ');
		i++;
	}
	write(1, "\n", 1);
}

void	find_place(unsigned int *tab, char *line, int s)
{
	unsigned short	tetri;
	int				i;
	unsigned int	m;
	unsigned int	tmp;

	ft_putendl("# . . # # # # T T # . # . # # # # # . . # # . # T # . # # # # . . # . # . . # # T . . # # # . # # . # # # . . . # # # # . . # . . # . # # . . # . . . # . . . . # . . . # # . # . . . # . # # .");
	// create tetri
	i = 0;
	while (line[i])
	{
		tetri <<= 1;
		if (line[i] == '\n')
			i++;
		if (line[i++] == '#')
			tetri |= 1;
	}
	while (!(tetri & (1 << 15)))
		tetri <<= 1;
	print_bits(tetri, 16);
	write(1, "\n", 1);

	m = 15 << (32 - 4);
	i = 0;
	while (i < 20)
	{
		while (i < 4 * s)
		{
			tmp = (m & (tab[i / 32] << i)) | (m & (tab[(i + s) / 32] >> (32 - i)));
			print_bits(tmp, 32);
			i += s;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	unsigned int	tab[8];

	// ce tableau permet de monter jusqu'a une map de 16*16
	tab[0] = 2656554334;
	tab[1] = 1394456818;
	tab[2] = 1494256918;
	tab[3] = 2656554334;
	tab[4] = 1592453883;
	tab[5] = 1444352908;
	tab[6] = 2154339230;
	tab[7] = 1576493154;
	print_bits(tab[0], 32);
	print_bits(tab[1], 32);
	print_bits(tab[2], 32);
	print_bits(tab[3], 32);
	print_bits(tab[4], 32);
	print_bits(tab[5], 32);
	print_bits(tab[6], 32);
	print_bits(tab[7], 32);
	if (ac > 1)
	{
		++av;
		// mettre l'option "b" pour afficher la troisieme argument en binaire
		if (av[0][0] == 'b' && ac > 2)
			ft_putendl(ft_convertbase(av[1], "01", "0123456789"));
		print_map(tab, 16);
		write(1, "\n", 1);
		if (av[0][0] == 't' && ac > 2)
			find_place(tab, av[1], 16);
	}
	return (0);
}

