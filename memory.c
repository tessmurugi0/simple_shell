#include "shell.h"

/**
 * bfree - function that freees a pointers variable of its memory
 * @ptr: pointer variable whose memory is to
 * be freed
 * 
 * Return: on success, 0
*/

int memfree(void** ptr)
{
    if (ptr != NULL && *ptr != NULL)
    {
        free(*ptr);
        *ptr = NULL;
        return(1);
    }
    return(0);
}