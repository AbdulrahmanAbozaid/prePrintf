#include "main.h"

/**
 * _printf - prints all
 * @format: assfsg
 * @...: params
 * Return: num of printed bytes
 */

int _printf(const char *format, ...)
{
        int num_of_bytes = 0;
        va_list args;
        char *str, *start_specs;
        params_t params = PARAMS_INIT;

        va_start(args, format);

        if (!format || (format[0] == '%' && !format[1]))
                return (-1);
        if (format[0] == '%' && format[1] == ' ' && !format[2])
                return (-1);
        // Returns negative value in case of Unexpected error
        for (str = (char *)format; *str; str++)
        {
                init_params(&params, args);
                // if it is a normal string
                if (*str != '%')
                {
                        num_of_bytes += _putchar(*str);
                        continue;
                }
                start_specs = str;
                str++;

                // checks for any falgs added or width || precision
                while (get_flag(str, &params))
                {
                        str++;
                }
                str = get_width(str, args, &params);
                str = get_precision(str, &params, args);
                if (get_modifier(str, &params))
                        str++;
                // if not found a specifier or a normal string
                if (!get_specifier(str))
                        num_of_bytes += print_from_to(start_specs, str, params.l_modifier || params.h_modifier ? str - 1 : 0);
                else
                        num_of_bytes += get_print_func(str, args, &params);
        }
        _putchar(BUF_FLUSH);
        va_end(args);
        return (num_of_bytes);
}
