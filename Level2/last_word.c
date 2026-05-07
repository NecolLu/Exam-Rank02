/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a 
.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>

*/

#include <unistd.h>

void	last_word(char *str)
{
	int i = 0;
	int end;

	// Step 1: Find the null terminator
	while (str[i])
		i++;
	
	i--; // Move back to the last actual character
	
	// Step 2: Skip trailing spaces/tabs
	while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
		i--;
	
	end = i; // This is the end of our last word

	// Step 3: Find the beginning of the word
	while (i >= 0 && str[i] != ' ' && str[i] != '\t')
		i--;
	
	// Step 4: Move i forward by one to be on the first letter
	i++;

	// Step 5: Print the word from start (i) to end
	while (i <= end)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}