#include "shell.h"
/**
 * _strncpy - copies a string
 * @dest: the destination string to be copied to
 * @src: the source string
 * @n: the maximum number of characters to be copied
 *
 * Return: the pointer to the destination string
 */
char *_strncpy(char *dest, const char *src, int n)
{
	int i;

	/* Copy characters from source to destination */
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	/* Pad remaining characters in destination with null terminators */
	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}

/**
 * _strncat - concatenates two strings
 * @dest: the destination string
 * @src: the source string
 * @n: the maximum number of characters to be appended
 *
 * Return: the pointer to the destination string
 */
char *_strncat(char *dest, const char *src, int n)
{
	int dest_len, i;

	/* Find the length of the destination string */
	for (dest_len = 0; dest[dest_len] != '\0'; dest_len++)
		;

	/* Append characters from source to destination */
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];

	/* Null terminate the destination string */
	dest[dest_len + i] = '\0';

	return (dest);
}

/**
 * _strchr - locates a character in a string
 * @s: the string to be searched
 * @c: the character to be found
 *
 * Return: a pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found
 */
char *_strchr(const char *s, char c)
{
	/* Iterate through the string until the character is found */
	while (*s != '\0')
	{
		if (*s == c)
			return ((char)s); /* Cast const pointer to non-const pointer */
		s++;
	}

	return (NULL); /* Character not found */
}
