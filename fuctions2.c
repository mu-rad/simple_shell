#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 * -1 on error
 */
int _erratoi(char *s)
{
	int f = 0;
	unsigned long int outcome = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (f = 0;  s[f] != '\0'; f++)
	{
		if (s[f] >= '0' && s[f] <= '9')
		{
			outcome *= 10;
			outcome += (s[f] - '0');
			if (outcome > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (outcome);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 * -1 on error
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
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int f, cnt = 0;
	unsigned int _abs, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs = -input;
		__putchar('-');
		cnt++;
	}
	else
		_abs = input;
	current = _abs;
	for (f = 1000000000; f > 1; f /= 10)
	{
		if (_abs_ / f)
		{
			__putchar('0' + current / f);
			cnt++;
		}
		current %= f;
	}
	__putchar('0' + current);
	cnt++;

	return (cnt);
}

/**
 * convert_number - converter function, a clone of itoa
 * @nb: number
 * @base: base
 * @flags: argument flags
 * Return: string
 */
char *convert_number(long int nb, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long l = nb;

	if (!(flags & CONVERT_UNSIGNED) && nb < 0)
	{
		l = -nb;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[l % base];
		l /= base;
	} while (l != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
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
