#include "shell.h"

/**
 * trim_spaces - ......
 *
 * @line: text to trim spaces from.
 *
 * Return: line without spaces.
 */
char *trim_spaces(char *line)
{

	int i = 0;
	int len = strlen(line);
	char *copied;
	char *temp = line;

	while (*temp != '\0')
	{
		if (*temp != ' ')
		{
			break;
		}
		else
			i++;
		*temp++;
	}
	copied = malloc(sizeof(char) * (len + 1));
	strcpy(copied, line + i);

	return (copied);
}

// char **
char **command_args(char **cmd_arr, char *full_line)
{
	char *token;
	int arr_len = 0;
	char *temp_line = malloc(strlen(full_line) + 1);
	int i;

	strcpy(temp_line, full_line);
	token = strtok(temp_line, " ");
	while (token != NULL)
	{
		arr_len++;
		token = strtok(NULL, " ");
	}
	cmd_arr = malloc(sizeof(char *) * (arr_len + 1));
	token = strtok(full_line, " ");
	for (i = 0; i < arr_len, token != NULL; i++)
	{
		cmd_arr[i] = malloc(strlen(token) + 1);
		strcpy(cmd_arr[i], token);
		token = strtok(NULL, " ");
	}
	cmd_arr[arr_len] = NULL;
	free(token);
	free(temp_line);
	return cmd_arr;
}

