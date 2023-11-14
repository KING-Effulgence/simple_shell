#include "shell.h"

/**
 * get_env_value - Gets the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable.
 */
char *get_env_value(char *name)
{
    char **environ_ptr = environ;
    int i, name_len;

    name_len = strlen(name);

    for (i = 0; environ_ptr[i] != NULL; i++)
    {
        if (strncmp(environ_ptr[i], name, name_len) == 0 && environ_ptr[i][name_len] == '=')
        {
            len = strlen(environ_ptr[i] + name_len + 1);
            return strdup(environ_ptr[i] + name_len + 1);
        }
    }

    return NULL;
}

/**
 * set_env - Sets or updates the value of an environment variable.
 * @name: The name of the environment variable.
 * @value: The value to set.
 *
 * Return: 1 if successful, 0 otherwise.
 */
int set_env(char *name, char *value)
{
    char **environ_ptr = environ;
    int i, name_len;
    char *new_var;

    name_len = strlen(name);
    len = name_len + strlen(value) + 2;

    new_var = malloc(len);
    if (new_var == NULL)
        return 0;

    strncpy(new_var, name, name_len);
    new_var[name_len] = '=';
    strcpy(new_var + name_len + 1, value);

    for (i = 0; environ_ptr[i] != NULL; i++)
    {
        if (strncmp(environ_ptr[i], name, name_len) == 0 && environ_ptr[i][name_len] == '=')
        {
            free(environ_ptr[i]);
            environ_ptr[i] = new_var;
            return 1;
        }
    }

    return 0;
}

