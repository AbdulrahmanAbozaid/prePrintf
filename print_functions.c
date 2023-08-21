#include "main.h"

/**
 * print_char - char
 * @ap: args
 * @params: paras
 * Return: length
 */

int print_char(va_list ap, params_t *params)
{
        char pad_char = ' ';
        unsigned int padding = 1, num_of_bytes = 0, c = va_arg(ap, int);

        // minus for pad end
        if (params->minus_flag)
                num_of_bytes += _putchar(c);
        while (padding++ < params->width)
                num_of_bytes += _putchar(pad_char);
        if (!params->minus_flag)
                num_of_bytes += _putchar(c);
        return (num_of_bytes);
}

/**
 * print_int - int
 * @ap: args
 * @params: paras
 * Return: length
 */

int print_int(va_list ap, params_t *params)
{
        long i_num;

        // convert func to convert between all raidces

        if (params->l_modifier)
                i_num = va_arg(ap, long);
        else if (params->h_modifier)
                i_num = (short int)va_arg(ap, int);
        else
                i_num = (int)va_arg(ap, int);
        return (print_number(convert(i_num, 10, 0, params), params));
}


/**
 * print_string - string
 * @ap: args
 * @params: paras
 * Return: length
 */

int print_string(va_list ap, params_t *params)
{
        char *str = va_arg(ap, char *), pad_char = ' ';
        unsigned int padding = 0, num_of_bytes = 0, i = 0, j;

        UNUSED(params);

        str = ((int)(!str)) ? NULL_STRING : str;
        j = padding = _strlen(str);
        if (params->precision < padding)
                j = padding = params->precision;
        if (params->minus_flag)
        {
                if (params->precision != UINT_MAX)
                        for (i = 0; i < padding; ++i)
                                num_of_bytes += _putchar(*str++);
                else
                        num_of_bytes += _puts(str);
        }
        while (j++ < params->width)
                num_of_bytes += _putchar(padding_char);
        if (!params->minus_flag)
        {
                if (params->precision != UINT_MAX)
                        for (i = 0; i < padding; ++i)
                                num_of_bytes += _putchar(*str++);
                else
                        num_of_bytes += _puts(str);
        }
        return (num_of_bytes);
}


/**
 * print_percent - %
 * @ap: args
 * @params: paras
 * Return: length
 */

int print_percet(va_list ap, params_t *params)
{
        (void)ap;
        (void)params;
        return (_putchar('%'));
}

/**
 * print_S - custom spec
 * @ap: args
 * @params: paras
 * Return: length
 */

int print_S(va_list ap, params_t *params)
{
        char *str = va_arg(ap, char *);
        char *hex;
        int num_of_bytes = 0;

        if ((int)(!str))
                return (_puts(NULL_STRING));
        for (; *str; str++)
        {
                if ((*str > 0 && *str < 32) || *str >= 127)
                {
                        num_of_bytes += _putchar('\\');
                        num_of_bytes += _putchar('x');
                        hex = convert(*str, 16, 0, params);
                        if (!hex[1])
                                num_of_bytes += _putchar('0');
                        num_of_bytes += _puts(hex);
                }
                else
                {
                        num_of_bytes += _putchar(*str);
                }
        }

        return (num_of_bytes);
}
