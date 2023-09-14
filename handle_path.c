#include "shell.h"

/**
 * getpath - get PATH enviroment varible as string
 *
 * @env: eviroment array.
 *
 * Return: PATH enviroment varible as string.
*/

char *getpath(char **env)
{
	char *path = NULL;
	int path_len = 0;

	while (*env != NULL)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
		{
			path_len = strlen(*env + 5);
			path = malloc(sizeof(char) * (path_len + 1));
			path[path_len] = '\0';
			strcpy(path, *env + 5);
		}
		(void) *env++;
	}

	return (path);
}
/**
 * _path - handle path of the command.
 *
 * @command_arr: array of args and command.
 * @env: to get the path of the program.
 *
 * Return: Arr of exist commands.
 */

int _path(char **command_arr, char **env)
{
	char *token;
	char *full_path;
	char *path;
	char *path_copy;

	if (strncmp(command_arr[0], "./", 2) == 0)
		return (0);
	path = getpath(env);
	if (path == NULL)
		return (0);

	path_copy = malloc(strlen(path) + 1);
	if (path_copy == NULL)
	{
		return (0);
	}

	strcpy(path_copy, path);
	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		full_path = concat_command(command_arr[0], token);
		if (access(full_path, X_OK) == 0)
		{
			free(command_arr[0]);
			command_arr[0] = malloc(sizeof(char) * (strlen(full_path) + 1));
			strcpy(command_arr[0], full_path);
			free(full_path);
			free(path);
			free(path_copy);
			return (1);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path);
	free(path_copy);
	return (0);
}
