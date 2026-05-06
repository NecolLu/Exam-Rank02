#include <unistd.h>

int main (int argc, char **argv)
{
    int i = 0;
    int start;
    int end;
    int already_printed_word = 0;

    if (argc == 2)
    {
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        start = i;
        while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
            i++;
        end = i;

        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;

        while(argv[1][i])
        {
            if (argv[1][i] != ' ' && argv[1][i] != '\t')
            {
                if (already_printed_word)
                    write(1, " ", 1);
            
                while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
                {
                    write(1, &argv[1][i], 1);
                    i++;
                }
                already_printed_word = 1;
            }
            else
                i++;
        }

        if (end > start)
        {
            if (already_printed_word)
                write(1, " ", 1);
            write(1, &argv[1][start], end - start);
        }
    }
    write(1, "\n", 1);
    return (0);
}