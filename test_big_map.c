#include <stdio.h>

void	print_bits(int octet)
{
	unsigned int i;

	i = 1 << 31;
	while (i)
	{
		(octet & i) ? printf("1") : printf("0");
		i >>= 1;
	}
}

/*
** cette fonction affiche un mask qui se decale le long d'un tableau d'int
** lancer avec gcc test_big_map.c puis ./a.out pour voir
*/

void	test(unsigned int map[])
{
	int 			i;
	int 			j;
	int 			k;
	int 			l;
	unsigned int	mask;

	mask = map[9];

	i = -1;
	j = 9;
	while (j >= 0)
	{
		if (!(++i % 32) && j-- && (k = -1))
		{
			while (++k < 10)
				print_bits(map[k]);
			printf("\n");
		}
		l = 0;
		while (l++ < 320 - 32 - i)
			printf(" ");
		print_bits(mask);
		printf("\n");
		mask = (mask >> 1) | (((1 << (i % 32)) & map[j]) << (31 - (i % 32)));
	}
}

int		main()
{
	unsigned int	map[10] = {1568713153, 817645681, 654186132, 538171355, 1718453135, 551286515, 1631843343, 3413834313, 1155555555, 999999999};
	int				i = 0;

	test(map);
	return (0);
}
