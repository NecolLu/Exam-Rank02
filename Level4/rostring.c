/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/

#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    int start;
    int end;
    int first_word_printed = 0;

    if (argc > 1)
    {
        // 1. Identify the first word
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        start = i;
        while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
            i++;
        end = i;

        // 2. Skip spaces after the first word
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;

        // 3. Print the remaining words
        while (argv[1][i])
        {
            // If we find a non-space character
            if (argv[1][i] != ' ' && argv[1][i] != '\t')
            {
                // Print a space only if we are starting a new word in the "rest" section
                if (first_word_printed)
                    write(1, " ", 1);
                
                // Print the current word
                while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
                {
                    write(1, &argv[1][i], 1);
                    i++;
                }
                first_word_printed = 1;
            }
            else
                i++;
        }

        // 4. Print the first word at the end
        if (end > start)
        {
            // If we already printed other words, we need a space before the first word
            if (first_word_printed)
                write(1, " ", 1);
            write(1, &argv[1][start], end - start);
        }
    }
    write(1, "\n", 1);
    return (0);
}

// The Logical Flow
// The if statement checks: "Am I looking at a character that belongs to a word?" If yes, the while loop inside takes over and says: "Keep printing until I hit the next gap or the end of the string."

// A Step-by-Step Walkthrough
// Imagine the input is: argv[1] = "  world   next" (and we already skipped the first word "hello").

// Scanning Spaces: i starts at the spaces before "world". The if condition is false, so it hits the else { i++; }. It keeps moving until it hits 'w'.

// Word Detected: Now argv[1][i] is 'w'. The if is true.

// The Space Guard: It checks if (first_word_printed).

// If we just finished printing a previous word, it prints one space. This ensures words are separated, but we never get double spaces or leading spaces.

// Printing the Block: The inner while loop runs. It prints 'w', then 'o', 'r', 'l', 'd'. It stops when it hits the space after 'd'.

// Setting the Flag: first_word_printed becomes 1 (true). We now know that any future words need a space in front of them.

// Repeat: The outer loop continues, skipping the extra spaces until it hits 'n' in "next".