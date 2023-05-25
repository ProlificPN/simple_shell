#include "header_shell.h"

/**
 * prompt - displays the prompt for the shell
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}
