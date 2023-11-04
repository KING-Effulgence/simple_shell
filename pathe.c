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
	int idx;
	char *clonedPath = NULL;

	for (idx = 0; environ[idx] != NULL; idx++)
	{
		if (compare_strings(environ[idx], "PATH", 4) == 0)
		{
			clonedPath = string_dup(&environ[idx][5]);
			break; /*Exit loop once PATH is found*/
		}
	}
	/*Free this return value if it's not NULL */
	return (clonedPath);
}
