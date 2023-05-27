#include "header_shell.h"

/**
 * main - entry point for the shell program
 *
 * Return: always returns 0
 */
int main(void)
{
	char *command = NULL;
	size_t command_size = 0;
	char *args[MAX_COMMAND_LENGTH];
	int arg_count;
	/* check if running in non-interactive mode */
	if (!isatty(STDIN_FILENO))
	{
		/* read command from standard input */
		if (getline(&command, &command_size, stdin) == -1)
		{
			perror("getline");
			return (EXIT_FAILURE);
		}
		/* parse and execute command */
		arg_count = parse_command(command, args, MAX_COMMAND_LENGTH);
		if (arg_count > 0)
		{
			execute_command(args);
		}
		free(command);
		return (EXIT_SUCCESS);
	}
	/* interactive mode: read commands from user */
	while (1)
	{
		prompt();
		if (read_command(&command, &command_size) == -1)
		{
			break;
		}
		arg_count = parse_command(command, args, MAX_COMMAND_LENGTH);
		if (arg_count > 0)
		{
			execute_command(args);
		}
		free(command);
		command = NULL;
	}
	return (EXIT_SUCCESS);
}
