#include "main.h"

/**
 * get_width - width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width
 */

int get_width(const char *format, int *i, va_list list)
{
    int it;
    int width = 0;

    for (it = *i + 1; format[it] != '\0'; it++)
    {
        if (is_digit(format[it]))
        {
            width *= 10;
            width += format[it] - '0';
        }
        else if (format[it] == '*')
        {
            it++;
            width = va_arg(list, int);
            break;
        }
        else
            break;
    }

    *i = it - 1;

    return (width);
}