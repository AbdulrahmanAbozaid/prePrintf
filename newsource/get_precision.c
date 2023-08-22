#include "main.h"

/**
 * get_precision - precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */


int get_precision(const char *format, int *i, va_list list)
{
    int it = *i + 1;
    int precision = -1;

    if (format[it] != '.')
        return (precision);

    precision = 0;

    for (it += 1; format[it] != '\0'; it++)
    {
        if (is_digit(format[it]))
        {
            precision *= 10;
            precision += format[it] - '0';
        }
        else if (format[it] == '*')
        {
            it++;
            precision = va_arg(list, int);
            break;
        }
        else
            break;
    }

    *i = it - 1;

    return (precision);
}