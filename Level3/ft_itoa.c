/*
==================================================
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char    *ft_itoa(int nbr);

==================================================
*/

#include <stdlib.h>

int getlen(long n)
{
    int len = 0;

    if (n < 0)
        len++;

    while (n != 0)
    {
        n /= 10;
        len++;
    }
    return(len);
}

char *ft_itoa(int nbr)
{
    char *str;
    long n;
    int len;

    n = nbr;
    len = getlen(n);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);

    str[len] = '\0';
    if (n == 0)
        str[0] = '0';

    if (n < 0)
    {
        str[0] = '-';
        n = -n;
    }

    while (n > 0)
    {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    return(str);
}