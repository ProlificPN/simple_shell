#include "header_shell.h"

/**
 * execute_command - executes a command in a child process
 * @argv: the array of arguments to execute
 */
void execute_command(char **argv)
{
	pid_t pid;
	int status;
	char *command_path = argv[0];

	if (_strncmp(argv[0], "exit", 4) == 0)
		exit(EXIT_SUCCESS);

	if (command_path[0] != '/')
	{
		command_path = get_path(argv[0]);

		if (command_path == NULL)
		{
			printf("Command not found: %s\n", argv[0]);
			return;
		}
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		if (command_path != argv[0])
			free(command_path);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* child process */
		if (execve(command_path, argv, environ) == -1)
		{
			perror("execve");
			if (command_path != argv[0])
				free(command_path);
			exit(EXIT_FAILURE);
		}
		_exit(EXIT_SUCCESS);
	}
	else
	{
		/* parent process */
		do {
			if (waitpid(pid, &status, WUNTRACED) == -1)
			{
				perror("waitpid");
				if (command_path != argv[0])
					free(command_path);
				exit(EXIT_FAILURE);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
