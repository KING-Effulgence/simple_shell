#include "shell.h"

/**
 * str_compare - Compares two strings up to n bytes.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * @n: The number of bytes to compare.
 *
 * Return: 0 if the strings match up to n bytes, 1 otherwise.
 */
int str_compare(const char *s1, const char *s2, size_t n)
{
	size_t index;

	if (!s1 || !s2)
		return (1);

	for (index = 0; index < n; index++)
	{
		if (s1[index] != s2[index])
			return (1);
	}
	return (0);
}
#include "shell.h"

/**
 * custom_strcmp - Compare two strings.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Return: 0 if the strings are equal, a positive value if str1 is greater,
 * and a negative value if str2 is greater.
 */
int custom_strcmp(const char *str1, const char *str2)
{
	if (str1 == NULL && str2 == NULL)
		return (0);

	if (str1 == NULL)
		return (-1);

	if (str2 == NULL)
		return (1);

	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
#include "shell.h"

/**
 * custom_strdup - Duplicate a string.
 * @src: Source string to be duplicated.
 *
 * Return: Pointer to the duplicated string or NULL if memory allocation fails.
 */
char *custom_strdup(const char *src)
{
	int idx, length;
	char *dup_str;

	length = calc_strlen(src);
	dup_str = malloc(sizeof(char) * (length + 1));

	if (!dup_str)
		return (NULL);

	for (idx = 0; src[idx]; idx++)
		dup_str[idx] = src[idx];

	dup_str[idx] = '\0';

	return (dup_str);
}

