#include "shell.h"

/**
 * _custom_memset - fills memory with a constant byte
 * @dest: the pointer to the memory area
 * @ch: the character to fill *dest with
 * @n: the number of bytes to be filled
 * Return: (dest) a pointer to the memory area dest
 */
char *_custom_memset(char *dest, char ch, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        dest[i] = ch;

    return (dest);
}

/**
 * custom_free_strings - frees an array of strings
 * @str_arr: array of strings to be freed
 */
void custom_free_strings(char **str_arr)
{
    char **temp = str_arr;

    if (!str_arr)
        return;

    while (*str_arr)
    {
        free(*str_arr);
        str_arr++;
    }

    free(temp);
}

/**
 * _custom_realloc - reallocates a block of memory
 * @ptr: pointer to the previously allocated block
 * @old_size: byte size of the previous block
 * @new_size: byte size of the new block
 *
 * Return: pointer to the new block of memory
 */
void *_custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *new_ptr;

    if (!ptr)
        return (malloc(new_size));

    if (!new_size)
    {
        free(ptr);
        return (NULL);
    }

    if (new_size == old_size)
        return (ptr);

    new_ptr = malloc(new_size);

    if (!new_ptr)
        return (NULL);

    old_size = old_size < new_size ? old_size : new_size;

    while (old_size--)
        new_ptr[old_size] = ((char *)ptr)[old_size];

    free(ptr);

    return (new_ptr);
}
