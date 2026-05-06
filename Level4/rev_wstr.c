#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	end;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
			i++;
		i--; // go to last char

		while (i >= 0)
		{
			while (i >= 0 && (av[1][i] == ' ' || av[1][i] == '\t')) // skip whitespace (its either a space or tab)
				i--;

			end = i; // mark the end of a word

			while (i >= 0 && av[1][i] != ' ' && av[1][i] != '\t') // find start of word
				i--; // i stops at space, so must i+1

			if (i < end) // write the word
			{
				write(1, &av[1][i + 1], end - i);
				if (i > 0)
					write(1, " ", 1);
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}