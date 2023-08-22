#include "main.h"


/**
 * print_hex - prints hexadecimal
 * @params: paras
 * @ap: args
 * Return: num of byes
 */

int print_hex(va_list ap, params_t *params)
{
        unsigned long num;
        int num_of_bytes = 0;
        char *str;

        if (params->l_modifier)
                num = (unsigned long int)va_arg(ap, unsigned long);
        else if (params->h_modifier)
                num = (unsigned short int)va_arg(ap, unsigned int);
        else
                num = (unsigned int)va_arg(ap, unsigned int);

        str = convert(num, 16, CONVERT_LOWERCASE | CONVERT_UNSIGNED, params);
        if (params->hashtag_flag && l)
        {
                *--str = 'x';
                *--str = '0';
        }
        params->unsign = 1;
        return (num_of_bytes += print_number(str, params));
}


/**
 * print_HEX - prints hexadecimal Upper
 * @params: paras
 * @ap: args
 * Return: num of byes
 */


int print_HEX(va_list ap, params_t *params)
{
        unsigned long num;
        int num_of_bytes = 0;
        char *str;

        if (params->l_modifier)
                num = (unsigned long int)va_arg(ap, unsigned long);
        else if (params->h_modifier)
                num = (unsigned short int)va_arg(ap, unsigned int);
        else
                num = (unsigned int)va_arg(ap, unsigned int);

        // not LOWER
        str = convert(num, 16, CONVERT_UNSIGNED, params);
        if (params->hashtag_flag && l)
        {
                *--str = 'X';
                *--str = '0';
        }
        params->unsign = 1;
        return (num_of_bytes += print_number(str, params));
}


/**
 * print_binary - prints binary
 * @params: paras
 * @ap: args
 * Return: num of byes
 */


int print_binary(va_list ap, params_t *params)
{
        unsigned int bin = va_arg(ap, unsigned int);
        char *str = convert(bin, 2, CONVERT_UNSIGNED, params);
        int num_of_bytes = 0;

        if (params->hashtag_flag && bin)
                *--str = '0';
        params->unsign = 1;
        return (num_of_bytes += print_number(str, params));
}


/**
 * print_octal - prints base 8
 * @params: paras
 * @ap: args
 * Return: num of byes
 */


int print_octal(va_list ap, params_t *params)
{
        unsigned long num;
        int num_of_bytes = 0;
        char *str;

        if (params->l_modifier)
                num = (unsigned long int)va_arg(ap, unsigned long);
        else if (params->h_modifier)
                num = (unsigned short int)va_arg(ap, unsigned int);
        else
                num = (unsigned int)va_arg(ap, unsigned int);

        // not LOWER
        str = convert(num, 8, CONVERT_UNSIGNED, params);
        if (params->hashtag_flag && l)
        {
                *--str = '0';
        }
        params->unsign = 1;
        return (num_of_bytes += print_number(str, params));
}
