#include "shell.h"

/**
 * execute_program - function to excute the program.
 *
 * @args: command args with command included.
 * @env: enviroment variables.
 *
 * Return: (1) on success, (0) on failure.
 */
int execute_program(char **args, char **env)
{
	int status, child_status, program_exist, index;

	if (strncmp(args[0], "exit", 4) == 0)
	{
		if (args[1] != NULL)
			return (__exit(args[1], args[0]));
		return (0);
	}
	if (strncmp(args[0], "env", 3) == 0)
		return (handle_env(env));

	program_exist = _path(args, env);
	if (program_exist == 0 && access(args[0], X_OK) == 0)
		if (strncmp(args[0], "/", 1) != 0 && strncmp(args[0], "./", 2) != 0 &&
			strncmp(args[0], "../", 3))
		{
			fprintf(stderr, "./hsh: %d: %s: not found\n", 1, args[0]);
			return (127);
		}
	if (access(args[0], X_OK) != 0)
	{
		fprintf(stderr, "./hsh: %d: %s: not found\n", 1, args[0]);
		return (127);
	}
	if (fork() == 0)
	{
		status = execve(args[0], args, env);
		if (status == -1)
			perror("execve");
	}
	else
	{
		wait(&child_status);
		if (WIFEXITED(child_status))
			child_status = WEXITSTATUS(child_status);
	}
	for (index = 0; args[index] != NULL; index++)
		if (strcmp(args[index], "exit") == 0 && args[index + 1] != NULL)
			return (__exit(args[index + 1], args[index]));
	return (child_status);
}
