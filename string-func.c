#include "shell.h"

/**
 * calc_strlen - Calculates the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
size_t calc_strlen(const char *str)
{
	size_t count = 0;

	if (!str)
		return (0);

	while (*str++)
		count++;

	return (count);
}

/**
 * _strcat - Concatenates two strings.
 * @destination: The target string.
 * @source: The string to be appended.
 *
 * Return: A pointer to the resulting string after the append.
 */
char *_strcat(char *destination, const char *source)
{
	char *initial_dest = destination;

	if (!destination)
		return (NULL);

	if (!source)
		return (destination);

	while (*destination)
		destination++;

	while ((*destination++ = *source++))
		;

	return (initial_dest);
}

/**
 * copy_string - Copies the contents of a string to another buffer.
 * @target: The buffer where the string will be copied to.
 * @original: The string to be copied.
 *
 * Return: A pointer to the buffer with the copied string.
 */
char *copy_string(char *target, const char *original)
{
	char *initial_target = target;

	if (!original || !target)
		return (NULL);

	while ((*target++ = *original++))
		;

	return (initial_target);
}

