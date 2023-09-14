#include "shell.h"

/**
 * main - Entry Point
 *
 * @argc: argument count.
 * @argv: program arguments.
 * @env: enviroment variables.
 *
 * Return: (0) on Success.
*/
int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	char *command = NULL;
	char **args = NULL;
	size_t len = 0;
	int wcount;
	int status;
	(void) argc;
	(void) argv;

	while (1)
	{
		if (isatty(0) == 1)
			printf("$ ");
		wcount = getline(&line, &len, stdin);
		if (wcount == -1)
		{
			if (isatty(0) == 1)
				printf("exit\n");
			break;
		}
		line[strcspn(line, "\n")] = '\0';

		command = trim_spaces(line);
		if ((*command) == '\0')
		{
			free(command);
			continue;
		}
		args = command_args(args, command);

		status = excute_program(args, env);

		free(command);
		free_args(&args);
		free(args);
	}
		free(line);


	return (status);
}
