#include "header_shell.h"

/**
 * execute_command - executes a command in a child process
 * @argv: the array of arguments to execute
 */
void execute_command(char **argv)
{
	if (built_in(argv))
		return;

	char *command_path = get_command_path(argv[0]);

	if (command_path == NULL)
	{
		printf("Command not found: %s\n", argv[0]);
		return;
	}

	int status = execute_command_path(command_path, argv);

	if (command_path != argv[0])
		free(command_path);

	if (status == -1)
	{
		perror("execute_command_path");
		exit(EXIT_FAILURE);
	}
}

/**
 * get_command_path - searches for the command path
 * @command: the command to search for
 * Return: the path to the command, or NULL if not found
 */
char *get_command_path(char *command)
{
	char *command_path = command;

	if (command_path[0] != '/')
	{
		command_path = search_path(command_path);

		if (command_path == NULL)
			return (NULL);
	}

	return (command_path);
}

/**
 * execute_command_path - forks and executes the command
 * @command_path: the path to the command to execute
 * @argv: the array of arguments to pass to the command
 * Return: the exit status of the command, or -1 on error
 */
int execute_command_path(char *command_path, char **argv)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
		return (-1);
	else if (pid == 0)
	{
		/* child process */
		if (execve(command_path, argv, environ) == -1)
			return (-1);
		_exit(EXIT_SUCCESS);
	}
	else
	{
		/* parent process */
		do {
			if (waitpid(pid, &status, WUNTRACED) == -1)
				return (-1);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (status);
}
