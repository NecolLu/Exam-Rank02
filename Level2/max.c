/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/

int max(int *tab, unsigned int len)
{
    int i = 0;
    int result = 0;

    while (i <= len)
    {
        if (tab[i] > result)
            result = tab[i];
        i++;
    }
    return(result);
}

#include <stdio.h>

int	main(void)
{
	int	tab[] = {2, 0, 1, 4, 4, 763, 2937};

	printf("%i\n", max(tab, 7));
	return (0);
}