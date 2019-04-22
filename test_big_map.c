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

void	print_short(short octet)
{
	unsigned int i;

	i = 1 << 15;
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
	short			tetri;

	tetri = (1 << 4) | (1 << 5) | (1 << 6);
	mask = map[9];
	i = -1;
	j = 9;
	while (j >= 0)
	{
		// a chaque fois que mask s'est decale jusqu'au int precedant du tableau, le if suivant reaffiche le tableau en une ligne
		if (!(++i % 32) && j-- && (k = -1))
		{
			while (++k < 10)
				print_bits(map[k]);
			printf("\n");
		}
		// imprime le bon nombre d'espaces pour que le mask s'imprime pile sous le tableau d'int a la position ou il en est
		l = 0;
		while (l++ < 320 - 32 - i)
			printf(" ");
		// imprime le mask
		print_bits(mask);
		printf("\n");
		// compare le mask (int) avec le short et l'imprime s'ils sont compatibles
		if (!(tetri & mask))
		{
			l = 0;
			printf(">>>>>");
			while (l++ < 320 - 32 + 16 - i - 5)
				printf(" ");
			print_short(tetri);
			printf("\n");
		}
		// fait tourner le mask le long du tableau d'int
		// (mask >> 1) decale le mask vers la droite (perd le bit le plus a droite et insere un bit a gauche)
		// (1 << (i % 32)) creer un mask avec un 1 a la premiere place a droite, puis a la deuxieme, puis la troisieme, etc.. jusqu'a 32, et recommence
		// (0000000000000010000000 & map[j]) recupere la valeur du bit de map[j] (qui est la map precedante sur le tableau d'int) a la position du 1
		// (0000000000000010000000 << (31 - (i % 32))) = 100000000000000000000
		// (mask >> 1) | 1000000000000000000000 = insere le 32eme bit dans mask
		mask = (mask >> 1) | (((1 << (i % 32)) & map[j]) << (31 - (i % 32)));
	}
}

int		main()
{
	unsigned int	map[10] = {1568713153, 817645681, 654186132, 538171355, 1718453135, 551286515, 1631843343, 3413834313, 1155555555, 999999999};
	int i;

	//while (i < 10)
	//	printf("%d\n", map[i++]);
	test(map);
	return (0);
}
