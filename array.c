#include "shell.h"

/**
 * free_str_array - Frees memory dynamically allocated to string set.
 * @total: Total number elements in the array.
 * @string_set: Array of dynamically strings to be freed.
 */
void free_str_array(int total, char *string_set[])
{
	int i;

	if (string_set)
	{
		for (i = 0; i < total; i++)
		{
			free(string_set[i]);
		}
		free(string_set);
	}
}
