#include <stdio.h>

void	print_bits(int octet)
{
	int i;

	i = 1 << 30;
	while (i)
	{
		(octet & i) ? printf("1") : printf("0");
		i >>= 1;
	}
	printf("\n");
}

void	test(int map[])
{
	int i;

	i = 0;
	print_bits(map[0]);
	printf("\n");
	while (i <= 30)
	{
		print_bits(map[1]);
	//	print_bits(((1 << i) & map[0]) << (30 - i));
		map[1] = (map[1] >> 1) | (((1 << i) & map[0]) << (30 - i)); // cette ligne vient ajouter a la fin de map[1] le debut de map[0]
		i++;														// c'est brouillon mais ca permettrait de faire "tourner" sur une
	}																// seule petite map le contenu de la grande map divisee en tab de int
}

int		main()
{
	int		map[10] = {456873153, 1687645681, 2, 3, 4, 5, 6, 7, 8, 9};
	int		i = 0;

	while (i < 10)
		printf("%d\n", map[i++]);
	test(map);
	return (0);
}
