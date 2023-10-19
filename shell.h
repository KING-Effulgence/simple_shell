#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stddef.h>
#include <sys/stat.h>

#define MAX_INPUT_LENGTH 100
#define MAX_LINE 1024

/* Function Prototypes */
char **tokenize(char *input_str);
void remove_comment(char *line);
void fixComments(char *inputLine);
void display_prompt(int mode);
int process_shell(char *buffer, char **argv, int count);
int tokenize_directory_paths(char *paths, char **path_tokens);
char *find_cmd_path(char *paths, char *cmd);
char *fetch_path_env(void);
int run_full_cmd(char **cmd_args, char **cmd_argv, char *full_cmd_path);
int run_command(char **cmd_args, char **cmd_argv);
int handle_builtin_commands(char **args, char *progname, char *buffer);
void print_environment(char **env);
void execute_builtin_env(char **env);
int process_builtin_commands(char **args, char *buffer);
int SetEnvVar(char **args);
int ModifyEnv(char *newVal, char **args);
int UnsetEnv(char **args);
int RunBuiltinCmds(char **args);
int custom_exit(char **args);

void print_env(void);
void ReportEnvError(char **cmd_tokens);
int display_environment(char **input_tokens);
int execute_full_command(char **args, char **argv, char *command_path);
int compareStrings(const char *s1, const char *s2);
char *string_dup(char *src);
int compare_strings(char *s1, char *s2, size_t n);
int handle_builtin_commands(char **args, char *name, char *buf);
void executeShellPrompt(int interactiveMode);
void processInput(char *inputLine, char **av);
int main(int ac, char **av);
void handleNonExecutable(char **arguments, char **av, char *inputLine);
void executeExecutable(char **arguments, char **av);
int handle_invalid_command(char **args, char *progname, int count);
void display_prompt(int mode);

void _start(void);
size_t calc_strlen(const char *str);
char *_strcat(char *destination, const char *source);
char *copy_string(char *target, const char *original);
int char_is_delimiter(char *ch, const char *delims);
char *modified_strtok(char *str, const char *delims);

void free_str_array(int total, char *string_set[]);
void display_error(char *prog_name, int cmd_seq, char *user_cmd);
void output_string(char *txt);
int output_char(char character_to display);

/* Global Variables */
extern char **environ;

#endif /* SHELL_H */

