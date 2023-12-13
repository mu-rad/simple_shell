#include "shell.h"

/**
 * list_len - determines length of linked list
 * @c: pointer to first node
 * Return: size of list
 */
size_t list_len(const list_t *c)
{
	size_t f = 0;

	while (c)
	{
		c = h->next;
		f++;
	}
	return (f);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t f = list_len(head), g;
	char **strs;
	char *str;

	if (!head || !f)
		return (NULL);
	strs = malloc(sizeof(char *) * (f + 1));
	if (!strs)
		return (NULL);
	for (f = 0; node; node = node->next, f++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (g = 0; j < f; g++)
				free(strs[g]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[f] = str;
	}
	strs[f] = NULL;
	return (strs);
}


/**
 * print_list - prints all elements of a list_t linked list
 * @b: pointer to first node
 * Return: size of list
 */
size_t print_list(const list_t *b)
{
	size_t f = 0;

	while (b)
	{
		_puts(convert_number(b->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(b->str ? b->str : "(nil)");
		_puts("\n");
		b = b->next;
		f++;
	}
	return (f);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @a: the next character after prefix to match
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char a)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((a == -1) || (*p == a)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t f = 0;

	while (head)
	{
		if (head == node)
			return (f);
		head = head->next;
		f++;
	}
	return (-1);
}
