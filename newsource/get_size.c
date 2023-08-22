#include "main.h"

/**
 * get_size - size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */


int get_size(const char *format, int *i) {
    int it = *i + 1;
    int size = 0;

    if (format[it] == 'l')
        size = S_LONG;
    else if (format[it] == 'h')
        size = S_SHORT;

    if (size == 0)
        *i = it - 1;
    else
        *i = it;

    return (size);
}