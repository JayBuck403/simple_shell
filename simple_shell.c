#include "main.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument value
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	char *prompt = "Tsh_$ ";
	char *lineptr;
	size_t n = 0;
	(void)argc;
	(void)argv;

	while (1)
	{
		printf("%s", prompt);
		getline(&lineptr, &n, stdin);
		printf("%s\n", lineptr);

		free(lineptr);
	}
	return (0);
}
