#include "main.h"

/**
 * _isdigit - is digit ?
 * @c: char
 *
 * Return: 1 | 0
 */

int _isdigit(char c)
{
        return (c >= '0' && c <= '9');
}

/**
 * _strlen - length
 * @s: string
 *
 * Return: length
 */

int _strlen(char *s)
{
        int len = 0;
        while (*s++)
                len++;
        return (len);
}

/**
 * print_number - nummm
 * @str: number
 * @params: parameters
 * Return: printed??
 */

int print_number(char *str, params_t *params)
{
        unsigned int len = _strlen(str);
        int negative = (!params->unsign && *str == '-');

        // zero case
        if (!params->precision && *str == '0' && !str[1])
                str = "";
        if (negative)
        {
                str++;
                len--;
        }

        if (params->precision != UINT_MAX)
                while (len++ < params->precision)
                        *--str = '0';
        if (negative)
                *--str = '-';

        if (!params->minus_flag)
                return (print_number_right_shift(str, params));
        else
                return (print_number_left_shift(str, params));
}


/**
 * print_number_right_shift - pad start
 * @str: string
 * @params: struct
 * Return: printed
 */

int print_number_right_shift(char *str, params_t *params)
{
        unsigned int num_of_bytes = 0, negative, t_negative, len = _strlen(str);
        char pad_char = ' ';

        if (params->zero_flag && !params->minus_flag)
                pad_char = '0';
        negative = t_negative = (!params->unsign && *str == '-');
        if (negative && len < params->width && pad_char == '0' && !params->minus_flag)
                str++;
        else
                negative = 0;
        if ((params->plus_flag && !t_negative) || (!params->plus_flag && params->space_flag && !t_negative))
                len++;
        if (negative && pad_char == '0')
                num_of_bytes += _putchar('-');
        if (params->plus_flag && !t_negative && pad_char == '0' && !params->unsign)
                num_of_bytes += _putchar('+');
        else if (!params->plus_flag && params->space_flag && !t_negative && !params->unsign && params->zero_flag)
                num_of_bytes += _putchar(' ');

        while (len++ < params->width)
                num_of_bytes += _putchar(pad_char);
        if (negative && pad_char == ' ')
                num_of_bytes += _putchar('-');
        if (params->plus_flag && !t_negative && pad_char == ' ' && !params->unsign)
                num_of_bytes += _putchar('+');
        else if (!params->plus_flag && params->space_flag && !t_negative && !params->unsign && !params->zero_flag)
                num_of_bytes += _putchar(' ');
        num_of_bytes += _puts(str);
        return (num_of_bytes);
}


/**
 * print_number_left_shift - pad end
 * @str: string
 * @params: struct
 * Return: printed
 */

int print_number_left_shift(char *str, params_t *params)
{
        unsigned int num_of_bytes = 0, negative, t_negative, len = _strlen(str);
        char pad_char = ' ';

        if (params->zero_flag && !params->minus_flag)
                pad_char = '0';
        negative = t_negative = (!params->unsign && *str == '-');
        if (negative && i < params->width && pad_char == '0' && !params->minus_flag)
                str++;
        else
                negative = 0;

        if (params->plus_flag && !t_negative && !params->unsign)
                num_of_bytes += _putchar('+'), len++;
        else if (params->space_flag && !t_negative && !params->unsign)
                num_of_bytes += _putchar(' '), len++;

        num_of_bytes += _puts(str);

        while (len++ < params->width)
                num_of_bytes += _putchar(pad_char);
        return (num_of_bytes);
}
