#include "shell.h"

/**
 * excute_program - function to excute the program.
 *
 * @args: command args with command included.
 * @env: enviroment variables.
 *
 * Return: (1) on success, (0) on failure.
*/
int excute_program(char **args, char **env)
{
	int status;
	int child_status;
	int program_exist = _path(args, env);
	if (access(args[0], X_OK) != 0 && strncmp(args[0], "./", 2) == 0)
	{
		fprintf(stderr, "./hsh: %d: %s: not found\n", 1, args[0]);
		return (127);
	}
	//check if ./program is not excutable and start with ./
	
	if (program_exist == 0 && access(args[0], X_OK) == 0)
	{
		if (strncmp(args[0], "/", 1) != 0 && strncmp(args[0], "./", 2) != 0 && strncmp(args[0], "../", 3))
		{
			fprintf(stderr, "./hsh: %d: %s: not found\n", 1, args[0]);
			return (127);
		}
	}
	// check if ./program is not starting with ./ and don't exist in path and not excutable 
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
		wait(&child_status);
	return (0);
}
