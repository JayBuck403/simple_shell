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
	char *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int number_of_tokens = 0;
	char *token;
	int i;
	(void)argc;

	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);

		if (nchars_read == -1)
		{
			printf("exit\n");
			return (-1);
		}

		lineptr_copy = malloc(sizeof(char) * nchars_read);
		if (lineptr_copy == NULL)
		{
			perror("Tsh_: memory allocation error");
			return (-1);
		}

		strcpy(lineptr_copy, lineptr);

		token = strtok(lineptr, delim);

		while (token != NULL)
		{
			number_of_tokens++;
			token = strtok(NULL, delim);
		}
		number_of_tokens++;

		argv = malloc(sizeof(char *) * number_of_tokens);
		token = strtok(lineptr_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		exec_func(argv);
	}
	free(lineptr_copy);
	free(lineptr);

	return (0);
}
