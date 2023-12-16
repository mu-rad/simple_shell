#include "shell.h"

/**
 *_eputs - Responsible for printing an input string
 * @str: this is the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
        int f = 0;

        if (!str)
                return;
        while (str[f] != '\0')
        {
                _eputchar(str[f]);
                f++;
        }
}

/**
 * _eputchar - this writes the character e to stderr
 * @e: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char e)
{
        static int f;
        static char buf[WRITE_BUF_SIZE];

        if (e == BUF_FLUSH || f >= WRITE_BUF_SIZE)
        {
                write(2, buf, f);
                f = 0;
        }
        if (e != BUF_FLUSH)
                buf[f++] = e;
        return (1);
}
/**
 * _putfd - this writes the character e to given fd
 * @e: The character to print
 * @fd: This is the filedescriptor to write to
 *
 * Return: 1 On success and
 * On error, -1 is returned, and errno is set correctly.
 */
int _putfd(char e, int fd)
{
        static int f;
        static char buf[WRITE_BUF_SIZE];

        if (e == BUF_FLUSH || f >= WRITE_BUF_SIZE)
        {
                write(fd, buf, f);
                f = 0;
        }
        if (e != BUF_FLUSH)
                buf[f++] = e;
        return (1);
}

/**
 *_putsfd - this prints an input string
 * @str: this is the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
        int f = 0;

        if (!str)
                return (0);
        while (*str)
        {
                f += _putfd(*str++, fd);
        }
        return (f);
}

