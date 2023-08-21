#include "main.h"

/**
 * _puts - prints a string passed
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
        // static fields to track any function call
        static int i;
        // collect 1024 byte and print then again
        static char buf[OUTPUT_BUF_SIZE];

        if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
        {
                // 1 -> stdout, buf: string, i: char count
                write(1, buf, i);
                // write again
                i = 0;
        }
        // BUF_FLUSH to end output buffer and start new one

        if (c != BUF_FLUSH)
                buf[i++] = c;
        return (1);
}
