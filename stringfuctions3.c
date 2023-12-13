#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@P: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int P)
{
	int f, g;
	char *s = dest;

	f = 0;
	while (src[f] != '\0' && f < p - 1)
	{
		dest[f] = src[f];
		f++;
	}
	if (f < p)
	{
		g = f;
		while (g < p)
		{
			dest[g] = '\0';
			g++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@p: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int p)
{
	int f, g;
	char *s = dest;

	f = 0;
	g = 0;
	while (dest[f] != '\0')
		f++;
	while (src[g] != '\0' && g < p)
	{
		dest[f] = src[g];
		f++;
		g++;
	}
	if (g < p)
		dest[f] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@a: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char a)
{
	do {
		if (*s == a)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
