#include "main.h"

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
