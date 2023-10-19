#include "shell.h"

/**
 * char_is_delimiter - Checks if a character is a delimiter.
 * @ch: The character to check.
 * @delims: String containing delimiter characters.
 *
 * Return: 1 if 'ch' is a delimiter, 0 otherwise.
 */
int char_is_delimiter(char *ch, const char *delims);

/**
 * modified_strtok - Tokenizes a string using specified delimiters.
 * @str: The string to tokenize.
 * @delims: Delimiter characters.
 *
 * Return: Pointer to the next available token or NULL if none are left.
 */
char *modified_strtok(char *str, const char *delims);

/**
 * main - Entry point of the program.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	char input[] = "This is a sample sentence";
	const char delimiters[] = " \n";
	char *token;

	token = modified_strtok(input, delimiters);

	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = modified_strtok(NULL, delimiters);
	}

	return (0);
}

/**
 * char_is_delimiter - Checks if a character is a delimiter.
 * @ch: The character to check.
 * @delims: String containing delimiter characters.
 *
 * Return: 1 if 'ch' is a delimiter, 0 otherwise.
 */
int char_is_delimiter(char *ch, const char *delims)
{
	if (ch == NULL || delims == NULL)
		return (0);

	int idx = 0;

	while (delims[idx] != '\0')
	{
		if (*ch == delims[idx])
			return (1);
		idx++;
	}
	return (0);
}

/**
 * modified_strtok - Tokenizes a string using specified delimiters.
 * @str: The string to tokenize.
 * @delims: Delimiter characters.
 *
 * Return: Pointer to the next available token or NULL if none are left.
 */
char *modified_strtok(char *str, const char *delims)
{
	static char remainder;
	char *token_start, *token_end;

	if (str != NULL)
		remainder = str;

	if (remainder == NULL || *remainder == '\0')
		return (NULL);

	token_start = remainder;
	token_end = strpbrk(remainder, delims);

	if (token_end)
	{
		*token_end = '\0';
		remainder = token_end + 1;
	}
	else
	{
		remainder = NULL;
	}

	while (remainder && char_is_delimiter(remainder, delims))
	{
		remainder++;
	}

	return ((*token_start) ? token_start : NULL);
}
