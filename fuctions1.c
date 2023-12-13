#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @a: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char a, char *delim)
{
	while (*delim)
		if (*delim++ == a)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@t: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int t)
{
	if ((t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@t: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *t)
{
	int f, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (f = 0;  t[f] != '\0' && flag != 2; f++)
	{
		if (t[f] == '-')
			sign *= -1;

		if (t[f] >= '0' && t[f] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (t[f] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
