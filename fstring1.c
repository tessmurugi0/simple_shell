#include "shell.h"
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>

/**
 * f_strcpy - copies the contents of one string (src)
 * to another string (dst)
 * @dst: the destination string
 * @src: the source string.
 * 
 * Return: on success, the copied string
*/

char *f_strcpy(char *dst, char *src)
{
    int cnt = 0;

    if ((f_strcmp(dst, src) == !0) || (src == NULL))
    {
        return(dst);
    }
    while (src[cnt])
    {
        dst[cnt] = src[cnt];
        cnt++;
    }
    dst[cnt] = '\0';
    return(dst);
}


/**
 * f_strdup - function that duplicates a string
 * @str: the string to duplicate
 * 
 * Return: the duplicated string
*/

char* f_strdup(const char *str)
{
    int len = 0;
    char *dup;

    if (str == NULL)
    {
        return(NULL);
    }

    while (*str++)
        len++;

    dup = malloc(sizeof(char) * (len + 1));

    if (!dup)
    {
        return(NULL);
    }

    for (len++; len--;)
        dup[len] = *--str;
    
    return(dup);
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
