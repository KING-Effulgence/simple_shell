#include "shell.h"

/**
 * tokenize_directories - Tokenize a colon-separated string of directories.
 * @directories: A string containing directories separated by colons.
 * @tokens: An array to store the resulting tokens.
 *
 * Return: The number of tokens.
 */
int tokenize_directories(char *directories, char **tokens)
{
	int index = 0;
	char *token = NULL;

	token = strtok(directories, ":");

	while (token)
	{
		tokens[index++] = token;
		token = strtok(NULL, ":");
	}
	tokens[index] = NULL;
	return (index);
}

/**
 * find_command_path - Find the valid path of a
 * command in specified directories.
 * @directories: A colon-separated string of
 * directories to search for the command.
 * @command: The command name to identify.
 *
 * Return: A dynamically allocated string showing the full path to the command
 * or NULL if unavailable.
 */
char *find_command_path(char *directories, char *command)
{
	int token_count;
	int index;
	size_t path_size;
	char **tokens = NULL, *path = NULL;

	if (!directories)
		return (NULL);

	directories = strchr(directories, '=');

	if (directories)
		directories++;

	tokens = malloc(sizeof(char *) * 40);

	if (!tokens)
		return (NULL);

	token_count = tokenize_directories(directories, tokens);

	for (index = 0; index < token_count; index++)
	{
		path_size = strlen(tokens[index]) + strlen(command) + 2;
		path = malloc(path_size);

		if (!path)
			continue;

		sprintf(path, "%s/%s", tokens[index], command);

		if (access(path, X_OK) == 0)
		{
			free(tokens);
			return (path);
		}
		free(path);
	}

	free(tokens);
	return (NULL);
}
