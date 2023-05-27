#include "header_shell.h"

/**
 * _getline - reads input from stdin into a buffer and returns a null-terminated string
 *
 * Return: a pointer to the line read from stdin, or NULL if there is no more input
 */
char *_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_index = 0;
	static int buffer_size = 0;
	char *line = NULL;
	int line_size = 0;

	while (1)
	{
		/* Check if we need to read more data into the buffer */
		if (buffer_index >= buffer_size)
		{
			buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (buffer_size == -1)
			{
				perror("read");
				exit(EXIT_FAILURE);
			}
			if (buffer_size == 0)
			{
				/* End of input */
				return NULL;
			}
			buffer_index = 0;
		}

		/* Check if we need to allocate more memory for the line */
		if (line_size == 0)
		{
			line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
			if (line == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
		}
		else if (line_size % BUFFER_SIZE == 0)
		{
			line = realloc(line, sizeof(char) * (line_size + BUFFER_SIZE + 1));
			if (line == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}

		/* Copy characters from the buffer to the line */
		while (buffer_index < buffer_size)
		{
			if (buffer[buffer_index] == '\n')
			{
				/* End of line */
				line[line_size] = '\0';
				buffer_index++;
				return line;
			}
			else
			{
				line[line_size] = buffer[buffer_index];
				line_size++;
				buffer_index++;
			}
		}
	}
}
