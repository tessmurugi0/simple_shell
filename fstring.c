#include "shell.h"
//#include <stdio.h>
//#include <string.h>

/**
 * f_strlen - loops through a string and returns its length
 * as an integer
 * @s: the string to iterate through
 * 
 * Return: 0 on success
*/

int f_strlen(char *s)
{
	int counter = 0;

    if (!s)
    {
        return(0);
    }

	while (*s)
	{
	    counter++;
	    *s++;
    }
    return(counter);
}


/**
 * f_strcmp - Loops through two strings comparing
 * their characters one by one
 * @s: first string to loop through
 * @t: second string to loop trough
 * 
 * Return: 0 on success
*/

int f_strcmp(char *s, char *t)
{
    int counter = 0;

    while (s[counter] && t[counter])
    {
        if (s[counter] != t[counter])
        {
            return(-1);
        }
        counter++;
    }

    if (s[counter] != t[counter])
    {
        return(-1);
    }

    return(0);
}



/**
 * f_starts_with - checks is a string starts witha  specified sub string
 * @hasytack: the main string to loop through
 * @needle: sub string to loop through
 * 
 * Return: 0 on success
*/

char *f_starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}


/**
 * f_strcat - function that joins two strings, the second
 * to the first.
 * @destination: first string onto which the second is joined
 * @source: the second string provided
 * 
 * Return: concatenated string.
*/
char *f_strcat(char *destination, char *source)
{
    char *result = destination;
    while (*destination)
    {
        destination++;
    }

    while (*source)
    {
        *destination++ = *source++;
    }
    *destination = *source;
    return (result);
}
