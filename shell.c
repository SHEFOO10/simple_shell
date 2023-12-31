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
	char *line = NULL, *command = NULL;
	char **args = NULL;
	size_t len = 0, status = 0;
	(void)argc, (void)argv;

	while (1)
	{
		if (isatty(0) == 1)
			printf("$ ");
		if (getline(&line, &len, stdin) == -1)
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
		status = execute_program(args, env);
		if (strncmp(args[0], "exit", 4) == 0)
		{
			free_args(&args, command);
			break;
		} else if (status != 0)
		{
			if (!isatty(0))
			{
				free_args(&args, command);
				break;
			}
		}
		free_args(&args, command);
	}
	free(line);
	return (status);
}
