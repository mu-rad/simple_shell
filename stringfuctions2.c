#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int f = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[f])
	{
		dest[f] = src[f];
		f++;
	}
	dest[f] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int lent = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		lent++;
	ret = malloc(sizeof(char) * (lent + 1));
	if (!ret)
		return (NULL);
	for (lent++; lent--;)
		ret[lent] = *--str;
	return (ret);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 * Return: Nothing
 */
void _puts(char *str)
{
	int f = 0;

	if (!str)
		return;
	while (str[f] != '\0')
	{
		_putchar(str[f]);
		f++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @a: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char a)
{
	static int f;
	static char buf[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || f >= WRITE_BUF_SIZE)
	{
		write(1, buf, f);
		f = 0;
	}
	if (a != BUF_FLUSH)
		buf[f++] = a;
	return (1);
}
