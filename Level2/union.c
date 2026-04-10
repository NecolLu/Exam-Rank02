/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/
// How it works
// First string
// print everything once
// (remove duplicates)
// Second string
// print only if:
// - not duplicate in itself

#include <unistd.h>

int in_str(char c, char *str) // to check if in other str 
{
    int i = 0;

    while(str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return(0);
}

int already_seen(char *str, int index) // to check duplicates
{
    int i = 0;

    while(i < index)
    {
        if (str[i] == str[index])
            return (1);
        i++;
    }
    return (0);
}

int main(int argc, char ** argv)
{
    int i = 0;
    char c;

    if (argc == 3)
    {
        while (argv[1][i])
        {
            c = argv[1][i];

            if (!already_seen(argv[1], i))
                write(1, &c, 1);
            i++;
        }

        i = 0;
        while(argv[2][i])
        {
            c = argv[2][i];

            if (!already_seen(argv[2], i) && !in_str(c, argv[1]))
                write(1, &c, 1);
            i++;
        }
        write(1, "\n", 1);
        return (0);
    }
}