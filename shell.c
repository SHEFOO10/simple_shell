#include "shell.h"

/**
 * main - Entry Point
 *
 * Return: (0) on Success.
*/
int main(void)
{
	char *line = NULL;
	char *command = NULL;
	char **argv = NULL;
	size_t len = 0;
	int wcount;
	int status;
	int child_status;

	while (1)
	{
		if (isatty(0) == 1)
			printf("$ ");
		wcount = getline(&line, &len, stdin);
		if (wcount == -1)
			break;
		line[strcspn(line, "\n")] = '\0';

		command = trim_spaces(line);
		if ((*command) == '\0')
		{
			free(command);
			break;
		}
		argv = command_args(argv, command);
		if (fork() == 0)
		{
			status = execve(argv[0], argv, environ);
			if (status == -1)
				perror("execve");
		}
		else
			wait(&child_status);
		free(command);
		free_args(&argv);
		free(argv);
	}
		free(line);


	return (0);
}
