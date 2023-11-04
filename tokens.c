#include "shell.h"

/**
 * tokenize - Divides a string into tokens.
 * @input_str: The source of string to be divided.
 * Return: An array of pointers to the tokens.
 */

char **tokenize(char *input_str)
{
	const int MAX_TOKENS = 25;
	char **tokens = NULL;
	int idx = 0;
	char *token = NULL;
	char *delimiter = " \n";

	tokens = malloc(sizeof(char *) * MAX_TOKENS);

	if (!tokens)
		return (NULL);

	token = strtok(input_str, delimiter);

	while (token && idx < MAX_TOKENS - 1)
	{
		tokens[idx++] = token;
		token = strtok(NULL, delimiter);
	}
	tokens[idx] = NULL;
	return (tokens);
}
