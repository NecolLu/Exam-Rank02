/*

Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$

*/

#include <unistd.h>

//Check if char exists in string2
int in_str(char c, char *str)
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

// Check if already appeared before in string1
int already_seen(char *str, int index)
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

int main(int argc, char **argv)
{   
    int i = 0;
    char c;

    if (argc == 3)
    {
        while(argv[1][i])
        {
           c = argv[1][i];

            if (in_str(c, argv[2]) && !already_seen(argv[1], i))
                write(1, &c, 1);

            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}