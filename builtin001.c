#include "shell.h"

/**
 * _erratoi - responsible for converting a string to an integer
 * @s: this is the string to be converted
 * Return: 0 if no numbers in the string, otherwise return the converted number and
 *       -1 on error
 */
int _erratoi(char *s)
{
        int f = 0;
        unsigned long int rest = 0;

        if (*s == '+')
                s++;  /* TODO: why does this make main return 255? */
        for (f = 0;  s[f] != '\0'; f++)
        {
                if (s[f] >= '0' && s[f] <= '9')
                {
                        rest *= 10;
                        rest += (s[f] - '0');
                        if (rest > INT_MAX)
                                return (-1);
                }
                else
                        return (-1);
        }
        return (rest);
}

/**
 * print_error - responsible for printing an error message
 * @info: this is the parameter and return info struct
 * @estr: the string holding specified error type
 * Return: 0 if no numbers in the string, return converted number otherwise
 *       and -1 on error
 */
void print_error(info_t *info, char *estr)
{
        _eputs(info->fname);
        _eputs(": ");
        print_d(info->line_count, STDERR_FILENO);
        _eputs(": ");
        _eputs(info->argv[0]);
        _eputs(": ");
        _eputs(estr);
}
/**
 * print_d - the function prints a decimal that is an integer number (base 10)
 * @inpt: this is the input
 * @fd: the filedescriptor to write to
 *
 * Return: this shows the number of characters printed
 */
int print_d(int inpt, int fd)
{
        int (*__putchar)(char) = _putchar;
        int f, count = 0;
        unsigned int _abs, currt;

        if (fd == STDERR_FILENO)
                __putchar = _eputchar;
        if (inpt < 0)
        {
                _abs = -inpt;
                __putchar('-');
                count++;
        }
        else
                _abs = inpt;
        currt = _abs;
        for (f = 1000000000; f > 1; f /= 10)
        {
                if (_abs / f)
                {
                        __putchar('0' + currt / f);
                        count++;
                }
                currt %= f;
        }
        __putchar('0' + currt);
        count++;

        return (count);
}
/**
 * convert_number - this is the converter function, a clone of the itoa
 * @num: the number
 * @base: the base
 * @flags: the argument flags
 *
 * Return: a string
 */
char *convert_number(long int num, int base, int flags)
{
        static char *array;
        static char buffer[50];
        char sign = 0;
        char *ptr;
        unsigned long a = num;

        if (!(flags & CONVERT_UNSIGNED) && num < 0)
        {
                a = -num;
                sign = '-';

        }
        array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
        ptr = &buffer[49];
        *ptr = '\0';

        do      {
                *--ptr = array[a % base];
                a /= base;
        } while (a != 0);

        if (sign)
                *--ptr = sign;
        return (ptr);
}

/**
 * remove_comments - this function replaces first instance of '#' with '\0'
 * @buf: this is the address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
        int f;

        for (f = 0; buf[f] != '\0'; f++)
                if (buf[f] == '#' && (!f || buf[f - 1] == ' '))
                {
                        buf[f] = '\0';
                        break;
                }
}

