#include "libft.h"

void	print_bits(int octet)
{
	int i;
	int j;

	i = 1 << 12;
//	i = 4096;
	while (i >>= 1)
		(octet & i) ? ft_putnbr(1) : ft_putnbr(0);
	ft_putchar('\n');
}

void	compare(int initial, int compare)
{
	compare ^= (1 << 3);
	print_bits(compare);
	ft_putchar('\n');

	/*
	// il faut utiliser le & car il transforme
	// 0+0=0 1+0=0 0+1=0 mais 1+1=1
	// donc si rien ne se superpose on obtient 0
	// et si un seul bit se superpose on obtient 1
	// (penser a l'utiliser a l'envers donc)
	*/

	while (initial & compare)
	{
		print_bits(initial);
		print_bits(compare);
		print_bits(initial & compare);
		!(initial & compare) ? ft_putendl("&: fit") : ft_putendl("&: not fit");
		compare >>= 1;
	}
	print_bits(initial);
	print_bits(compare);
	print_bits(initial & compare);
	!(initial & compare) ? ft_putendl("&: fit") : ft_putendl("&: not fit");

/*
//	j = 1 << 12;
//	while (j >>= 1)
//		(initial | compare) & j ? ft_putnbr(1) : ft_putnbr(0);
//	ft_putchar('\n');
//	(initial | compare) ? ft_putendl("|: fit") : ft_putendl("|: not fit");
//	j = 1 << 12;
//	while (j >>= 1)
//		(initial ^ compare) & j ? ft_putnbr(1) : ft_putnbr(0);
//	ft_putchar('\n');
//	(initial ^ compare) ? ft_putendl("^: fit") : ft_putendl("^: not fit");
*/
}

int		main(int ac, char **av)
{
	int i;
	int j;

//	i = 56173;
//	j = 9362;
	i = 9622;
	j = 27;
	if (ac > 0)
	{
		if (ac > 1)
			ft_putendl(ft_convertbase(av[1], "0123456789", "01"));
		print_bits(i);
		print_bits(j);
		compare(i, j);
	}
	return (0);
}

/*
**int		main(int ac, char **av)
**{
**	int	init;
**	int	mask;
**
**	mask = (1 << 4);
**	if (ac == 4)
**	{
**		ft_putendl(ft_convertbase(av[1], av[2], av[3]));
**		ft_putnbrendl(init);
**		init |= mask;
**		ft_putnbrendl(init);
**	}
**	return (0);
**}
*/
