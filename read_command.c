#include "header_shell.h"

/**
 * read_command - reads a command from stdin
 * @command: a pointer to a buffer to store the command
 * @bufsize: the size of the buffer
 * Return: the number of characters read, or -1 on failure
 */
ssize_t read_command(char **command, size_t *bufsize)
{
	ssize_t nread;

	nread = getline(command, bufsize, stdin);
	if (nread == -1)
	{
		if (errno == EOF)
			printf("\n");
		else
			perror("getline");
	}
	else if ((*command)[nread - 1] == '\n')
		(*command)[nread - 1] = '\0';

	return (nread);
}
