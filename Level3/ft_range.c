/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.

The Strategy
1. Calculate Size: The number of integers needed is the distance between start and end, plus one (to include both).
2. Malloc: Create the array.
3. Fill: Use a loop to fill the array. If start is smaller than end, you increment ($+1$); if start is larger, you decrement ($-1$).
*/

#include <stdlib.h>

int *range(int start, int end)
{
    int *range;
    int size;
    int i;

    if (start <= end)
        size = end - start + 1;
    else
        size = start - end + 1;

    range = (int *)malloc(sizeof(int) * size);

    i = 0;
    while (i < size)
    {
        range[i] = start;

        if (start <= end)
            start++;
        else
            start--;
        i++;
    }
    return(range);
}