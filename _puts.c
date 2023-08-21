#include "main.h"

/**
 * _puts - prints
 * @str: string
 *
 * Return: void
 */

int _puts(char *str)
{
        char *s = str;

        while (*str)
                _putchar(*str++);
        return (str - a);
}

/**
 * _putchar - print char
 * @c: char
 *
 * Return: num 1, -1
 */

int _putchar(char c)
{
        static int i;
        static char buf[OUTPUT_BUF_SIZE];

        if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
        {
                write(1, buf, i);
                i = 0;
        }

        if (c != BUF_FLUSH)
                buf[i++] = c;
        return (1);
}
