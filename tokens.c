#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * tokenize - Divides a string into tokens based on delimiters.
 * @input_str: The source string to be divided.
 *
 * Return: An array of pointers to the tokens.
 */
char **tokenize(char *input_str);

/**
 * main - Entry point of the program.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	char input[] = "This is a sample sentence";
	char **tokens = tokenize(input);

	if (tokens == NULL)
	{
		printf("Tokenization failed.\n");
		return (1);
	}

	int i = 0;

	while (tokens[i] != NULL)
	{
		printf("Token %d: %s\n", i + 1, tokens[i]);
		free(tokens[i]);
		i++;
	}

	free(tokens);
	return (0);
}

/**
 * tokenize - Divides a string into tokens based on delimiters.
 * @input_str: The source string to be divided.
 *
 * Return: An array of pointers to the tokens.
 */
char **tokenize(char *input_str)
{
	const int MAX_TOKENS = 25;
	char *tokens = (char *)malloc(sizeof(char *) * MAX_TOKENS);

	if (!tokens)
	{
		return (NULL);
	}

	int idx = 0;
	char *token = NULL;
	char *delimiter = " \n";

	token = strtok(input_str, delimiter);
	while (token && idx < MAX_TOKENS - 1)
	{
		tokens[idx++] = strdup(token);
		token = strtok(NULL, delimiter);
	}

	tokens[idx] = NULL;
	return (tokens);
}
