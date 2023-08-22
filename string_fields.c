#include "main.h"

/**
 * get_precision - get precision from fmt
 * @p: fmt string
 * @ap: args
 * @params: parameters
 * Return: num of byes
 */

char *get_precision(char *p, params_t *params, va_list ap)
{
        int pn = 0;

        if (*p != '.')
                return (p);
        pn++;
        if (*p == '*')
        {
                pn = va_arg(ap, int);
                p++;
        }
        else
        {
                while (_isdigit(*p))
                        pn = pn * 10 + (*p++ - '0');
        }
        params->precision = pn;
        return (p);
}
