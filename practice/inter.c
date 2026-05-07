#include <unistd.h>

int already_seen(char *str, int index)
{
    int i = 0;

    while (i < index)
    {
        if (str[i] == str[index])
            return (1);
        i++;
    }
    return (0);
}

int in_str(char c, char *str)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] == c)
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
        while (argv[1][i])
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