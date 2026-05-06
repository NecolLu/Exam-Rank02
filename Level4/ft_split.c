/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

#include <stdlib.h>

int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int count_words(char *str)
{
    int i = 0;
    int count = 0;

    while(str[i])
    {
        while (str[i] && is_space(str[i]))    // skip space
            i++;
        if (str[i])                           // found start of word
            count++;
        while(str[i] && !is_space(str[i]))    // find end of word
            i++;
    }
    return (count);
}

char *word_dup(char *str, int start, int end)
{
    int i = 0;
    char *word = malloc(end - start + 1);

    while (start < end)
        word[i++] = str[start++];
    word[i] = '\0';
    return (word);
}

char **ft_split(char *str)
{
    char **result;
    int i = 0;
    int j = 0;
    int start;

    result = malloc(sizeof(char *) * (count_words(str) + 1));
    if (!result)
        return (NULL);

    while (str[i])
    {
        // 1. Skip the spaces to find the beginning of a word
        while (str[i] && is_space(str[i]))
            i++;
        
        start = i; // Mark the start of the actual word

        // 2. Skip the non-spaces to find the end of that word
        while (str[i] && !is_space(str[i]))
            i++;

        // 3. If we actually moved forward, we found a word
        if (i > start)
            result[j++] = word_dup(str, start, i);
    }
    result[j] = NULL;
    return(result);
}