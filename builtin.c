#include "shell.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <signal.h>

/**
 * exit_shell - Exits the shell
 * @shell_data: Structure containing potential arguments. Used to maintain
 *              constant function prototype.
 *
 * Return: Exits with a given exit status
 *         (0) if shell_data->argv[0] != "exit"
 */
int exit_shell(shell_data_t *shell_data)
{
	int exit_status = 0;

	if (shell_data->argv[1])
	{
		exit_status = atoi(shell_data->argv[1]);

		if (exit_status == 0 && strcmp(shell_data->argv[1], "0") != 0)
		{
			shell_data->status = 2;
			print_error(shell_data, "Illegal number: ");
			eputs(shell_data->argv[1]);
			eputchar('\n');
			return (1);
		}

		shell_data->error_number = exit_status;
		return (-2);
	}

	shell_data->error_number = -1;
	return (-2);
}

/**
 * change_directory - Changes the current directory
 * @shell_data: Structure containing potential arguments. Used to maintain
 *               constant function prototype.
 *
 * Return: Always 0
 */
int change_directory(shell_data_t *shell_data)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		return (-1);
	}

	char *directory = NULL;

	if (!shell_data->argv[1])
	{
		directory = getenv(shell_data, "HOME=");
		if (directory == NULL)
			directory = getenv(shell_data, "PWD=");
	}
	else if (strcmp(shell_data->argv[1], "-") == 0)
	{
		directory = getenv(shell_data, "OLDPWD=");
	}
	else
	{
		directory = shell_data->argv[1];
	}

	if (chdir(directory) == -1)
	{
		perror("chdir");
	}
	else
	{
		setenv(shell_data, "OLDPWD", getenv(shell_data, "PWD="));
		setenv(shell_data, "PWD", getcwd(cwd, sizeof(cwd)));
	}

	return (0);
}

/**
 * show_help - Displays help information
 * @shell_data: Structure containing potential arguments. Used to maintain
 *              constant function prototype.
 *
 * Return: Always 0
 */
int show_help(shell_data_t *shell_data)
{
	char **arg_array = shell_data->argv;

	puts("help call works. Function not yet implemented\n");

	if (0)
		puts(*arg_array); /* temp att_unused workaround */

	return (0);
}
