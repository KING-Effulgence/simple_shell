#include "shell.h"

/**
 * fetch_path_env - Retrieve and duplicate the environment's PATH variable.
 *
 * This function searches the environment variables for the PATH variable,
 * duplicates its value, and returns a new string containing the PATH.
 *
 * Return: A string representing the PATH variable, or NULL if not found.
 */
char *fetch_path_env(void)
{
	int index;
	char *clonedPath = NULL;

	for (index = 0; environ[index] != NULL; index++)
	{
		if (compare_strings(environ[index], "PATH", 4) == 0)
		{
			clonedPath = string_dup(&environ[index][5]);
			break; /* Exit the loop when PATH is found */
		}
	}

	/* Remember to free the clonedPath if it's not NULL */
	return (clonedPath);
}

