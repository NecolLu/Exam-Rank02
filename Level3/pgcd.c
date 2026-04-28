/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$
*/

#include <stdlib.h>
#include <stdio.h>

void	pgcd(int a, int b)
{
	int	result;
	int	div;

	if (a < 0 || b < 0)
		return ;
	div = 1;
	result = 0;
	while (div <= a && div <= b)
	{
		if (a % div == 0 && b % div == 0)
			result = div;
		div++;
	}
	printf("%d", result);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		pgcd(atoi(argv[1]), atoi(argv[2]));
	printf("\n");
	return (0);
}