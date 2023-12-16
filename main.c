#include "shell.h"

/**
 * main -this is the  entry point
 * @an: responsible for arg count
 * @ap: this is the arg vector
 *
 * Return: 0 if  successful, and 1 if an error is encountered
 */
int main(int an, char **ap)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (an == 2)
	{
		fd = open(ap[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(ap[0]);
				_eputs(": 0: Sorry can't open this");
				_eputs(ap[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, ap);
	return (EXIT_SUCCESS);
}
