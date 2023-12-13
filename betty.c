#include "shell.h"

/**
* string_toupper - convert lowercase to upper case
* @s: string to covert to upper case
* Return: s
*/

char *string_toupper(char *s)
{
        int f;

        for (f = 0 ; s[f] != '\0' ; f++)
        {
                if (s[f] >= 'a' && s[f] <= 'z')
                        s[f] = s[f] - 32;
        }
}       return (s);
