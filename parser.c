#include "shell.h"

/**
 * is_cmd - checks if command is erxecutable
 * @info: data struct
 * @path: file location
 * 
 * TReturn: on success, 0
*/

int fis_command(info_t* info, char* path)
{
    struct stat st;

    if (!path || stat(path, &st) != 0)
	{
        // Return 0 if the path is NULL or stat fails (file not found)
        return(0);
    }

    if (S_ISREG(st.st_mode))
	{
        // Check if the file mode indicates a regular file (executable command)
        return(1);
    }

    return(0);
}

/**
 * dup_chars - duplicates characters in a  string
 * @pathstr - the string location
 * @start: string[0]
 * @stop - last character
 * 
 * Return: the duplicated character string
*/

char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - finds command in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((f_strlen(cmd) > 2) && f_starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				f_strcat(path, cmd);
			else
			{
				f_strcat(path, "/");
				f_strcat(path, cmd);
			}
			if (fis_command(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return(NULL);
}