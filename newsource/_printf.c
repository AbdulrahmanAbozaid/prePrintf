#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Print function
 * @format: format
 * Return: Printed chars
 */

int _printf(const char *format, ...)
{
    int it, printed = 0, printed_chars = 0;
    int flags, width, precision, size, buff_ind = 0;
    va_list list;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(list, format);

    for (it = 0; format && format[it] != '\0'; it++)
    {
        if (format[it] != '%')
        {
            buffer[buff_ind++] = format[it];
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);
            printed_chars++;
        }
        else
        {
            print_buffer(buffer, &buff_ind);
            flags = get_flags(format, &it);
            width = get_width(format, &it, list);
            precision = get_precision(format, &it, list);
            size = get_size(format, &it);
            ++it;
            printed = handle_print(format, &it, list, buffer,
                                   flags, width, precision, size);
            if (printed == -1)
                return (-1);
            printed_chars += printed;
        }
    }

    print_buffer(buffer, &buff_ind);

    va_end(list);

    return (printed_chars);
}


/**
 * print_buffer - contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
        write(1, &buffer[0], *buff_ind);

    *buff_ind = 0;
}