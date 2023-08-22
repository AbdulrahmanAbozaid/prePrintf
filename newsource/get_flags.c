#include "main.h"

/**
 * get_flags - active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */


int get_flags(const char *format, int *i)
{
    int j, it;
    int flags = 0;
    const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

    for (it = *i + 1; format[it] != '\0'; it++)
    {
        for (j = 0; FLAGS_CH[j] != '\0'; j++)
            if (format[it] == FLAGS_CH[j])
            {
                flags |= FLAGS_ARR[j];
                break;
            }

        if (FLAGS_CH[j] == 0)
            break;
    }

    *i = it - 1;

    return (flags);
}