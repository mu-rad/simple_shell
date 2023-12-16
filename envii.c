#include "shell.h"

/**
 * _myenv - responsible for printing the current environment
 * @info: Structure holding potential arguments used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
        print_list_str(info->env);
        return (0);
}

/**
 * _getenv - this gets the value of an environment variable
 * @info: Structure holding potential arguments, used to maintain
 * @name: environment variable name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
        list_t *node = info->env;
        char *c;

        while (node)
        {
                c = starts_with(node->str, name);
                if (c && *c)
                        return (c);
                node = node->next;
        }
        return (NULL);
}

/**
 * _mysetenv - this initializes a new environment variable,
 *             or modifies an existing one
 * @info: Structure holding potential arguments, used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
        if (info->argc != 3)
        {
                _eputs("Number of arguments entered is incorrect\n");
                return (1);
        }
        if (_setenv(info, info->argv[1], info->argv[2]))
                return (0);
        return (1);
}

/**
 * _myunsetenv - this removes an environment variable
 * @info: Structure holding potential arguments, used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
        int f;

        if (info->argc == 1)
        {
                _eputs("Too few arguements entered.\n");
                return (1);
        }
        for (f = 1; f <= info->argc; f++)
                _unsetenv(info, info->argv[f]);

        return (0);
}

/**
 * populate_env_list - this populates environment linked list
 * @info: the structure holding potential arguments, used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
        list_t *node = NULL;
        size_t f;

        for (f = 0; environ[f]; f++)
                add_node_end(&node, environ[f], 0);
        info->env = node;
        return (0);
}

