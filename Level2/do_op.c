/*
Assignment name  : do_op
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-1i signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56i88$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$
*/

#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int first;
    int second;
    int result;

    if (ac == 4)
    {
        first = atoi(av[1]);
        second = atoi(av[3]);

        if (av[2][0] == '+')
            result = first + second;
        else if (av[2][0] == '-')
            result = first - second;
        else if (av[2][0] == '*')
            result = first * second;
        else if (av[2][0] == '/')
            result = first / second;
        else if (av[2][0] == '%')
            result = first % second;

        printf("%d\n", result);
    }
    else
        printf("\n");

    return 0;
}