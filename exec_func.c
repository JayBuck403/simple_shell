#include "main.h"

/**
 * exec_func - Implements the execve function
 * @argv - pointer to pointer
 *
 * Return: void
 */

void exec_func(char **argv)
{
	char *command = NULL;
	char *_command = NULL;

	if (argv)
	{
		command = argv[0];
		_command = get_location(command);

		if (execve(_command, argv, NULL) == -1)
		{
			perror("Error");
		}
	}
}
