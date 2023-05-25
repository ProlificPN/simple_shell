#include "header_shell.h"

/**
 * execute_command - executes a command
 * @command: the command to execute
 * Return: 0 on success, or -1 on failure
 */
int execute_command(char *command)
{
	char *args[MAX_COMMAND_LENGTH];
	char *token;
	int i = 0;
	char *cmd;

	token = strtok(command, " ");

	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;

	if (_strncmp(args[0], "exit", 4) == 0)
		exit(EXIT_SUCCESS);
	if (_strncmp(args[0], "env", 3) == 0)
	{
		print_env();
		return (0);
	}

	cmd = search_command(args[0]);
	if (cmd == NULL)
	{
		printf("%s: command not found\n", args[0]);
		return (-1);
	}
	if (fork() == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
	return (0);
}
