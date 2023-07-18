#include "shell.h"
//#include <stdlib.h>
//#include <unistd.h>

/**
 * f_eputchar - prints a string to the standard error
 * @c: the string to be printed into te standard error
 * 
 * Return: on success, 1. On error, -1
*/

int f_eputchar(char c)
{
    static int a = 0;
    static buf[WRITE_BUF_SIZE];

    if (c == '\n' || c >= WRITE_BUF_SIZE - 1)
    {
        write(2, buf, a);
        a = 0;
    }

    if (c != '\n')
    {
        buf[a++] = c;
    }

    return(1);
}

/**
 * f_eputs - writes a string to standard output
 * @str: string to be written
 * 
 * Return: NULL
*/
void f_eputs(char *str)
{
    int i = 0;

    if (!str)
    {
        return;
    }
    while (str[i] != '\0')
    {
        f_eputchar(str[i]);
        i++;
    }
}


/**
 * f_writefd - writes a string to the specified file desriptor
 * @c: what to write the the file descriptor
 * @fd: integral specification of the file descriptor
 * 
 * Return: on success, 1
*/

int f_writefd(char c, int fd)
{
   	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1); 
}

/**
 * _putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int f_putsfd(char *str, int fd)
{
    int count = 0;

    if (!str)
        return(0);

    while (*str)
    {
        if (f_writefd(*str, fd) == -1)
            return(-1);

        count++;
        str++;
    }

    return(count);
}