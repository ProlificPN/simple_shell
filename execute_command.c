#include "header_shell.h"

/**
 * execute_command - executes a command in a child process
 * @argv: the array of arguments to execute
 */
void execute_command(char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* child process */
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("execve");
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
				exit(EXIT_FAILURE);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
