#include "shell.h"

/**
 * interactive - this  returns true if shell is interactive mode
 * @info: the struct address
 *
 * Return: 1 if is interactive mode and 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - responsible for checking if character is a delimeter
 * @a: this is the char to the character to check
 * @delim:this is the delimeter string
 * Return: 1 if true and 0 if false
 */
int is_delim(char a, char *delim)
{
	while (*delim)
		if (*delim++ == a)
			return (1);
	return (0);
}

/**
 *_isalpha - responsibel for checking for alphabetic character
 *@c:shows The character to input
 *Return: 1 if a is alphabetic, and 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi -this  converts a string to an integer
 *@s: shows the string to be converted
 *Return: 0 if no numbers in a string and return converted number otherwise
 */

int _atoi(char *s)
{
	int f, sign = 1, flag = 0, output;
	unsigned int rest = 0;

	for (f = 0;  s[f] != '\0' && flag != 2; f++)
	{
		if (s[f] == '-')
			sign *= -1;

		if (s[f] >= '0' && s[f] <= '9')
		{
			flag = 1;
			rest *= 10;
			rest += (s[f] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -rest;
	else
		output = rest;

	return (output);
}
