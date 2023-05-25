#include "header_shell.h"

/**
 * simple_shell - displays a prompt andwaits for the user to type a command
 */
void simple_shell(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t nread;

	while (1)
	{
		nread = read_command(&command, &bufsize);
		if (nread == -1)
			break;
		if (command[0] == '\0')
			continue;
		if (execute_command(command) == -1)
			break;
		free(command);

		command = NULL;
		bufsize = 0;
	}

	free(command);
}
