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

	if (argv)
	{
		command = argv[0];

		if (execve(command, argv, NULL) == -1)
		{
			perror("Error");
		}
	}
}
