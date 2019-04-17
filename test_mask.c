#include "libft.h"

int		main(int ac, char **av)
{
	int	init;
	int	mask;

	mask = (1 << 4);
	if (ac == 4)
	{
		ft_putendl(ft_convertbase(av[1], av[2], av[3]));
		ft_putnbrendl(init);
		init |= mask;
		ft_putnbrendl(init);
	}
	return (0);
}
