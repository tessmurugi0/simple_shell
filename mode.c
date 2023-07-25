#include "shell.h"

/**
 * mode - a function that determines the current shell mode
 * it determines whether the shell inpuit is in interactive mode
 * and examines the type of terminal device
 * @info: input struct
 * 
 * Return: 1 on success.
*/

int mode(info_t *info)
{
    if (isatty(STDIN_FILENO))
    {
        if (info->readfd <= 2)
        {
            return(1);
        }
        return(0);
    }
    return(0);
}


/**
 * isdelimiter - fucntion that iterates through input in the
 * stdin and checks character by character for delimeters
 * @c: specific character to iterate through
 * @delimeter: the delimeter to check for
 * 
 * Return: 1 on successs and 0 on failure
*/

int isdelimeter(char c, char *delimeter)
{
    while (*delimeter)
    {
        if (*delimeter == c)
        {
            reurn(1);
            delimeter++;
        }
    }
    return(0);
}

/**
 * isalpha - iterates through an input string checking for
 * alphabet characters
 * @c: specific string character to loop through
 * 
 * Return: 1 if character is an alphabet and 0 if not
*/

int isalpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - function that converts a string character to an integer
 * @s: te string to be converted
 * 
 * Return: 0 if there are no numbers in the string.
*/

int _atoi(char *s)
{
    int counter;
    int sign = 1;
    int flag = 0;
    int result;
    unsigned int result1;

    for (counter = 0; s[counter] != '\0' && flag != 2; counter++)
    {
        if (s[counter] == '-')
        {
            sign = sign * -1;
        }
            if (s[counter] > '0' && s[counter] <= '9')
            {
                flag = 1;
                result1 = result1 * 10;
                result1 = result1 + (s[counter] - '0');
            }
            else if (flag == 1)
            {
                flag = 2;
            }
        else if (flag == -1)
        {
            result = -result;
        }
        else
        {
            result = result1;
        }
    }
    return (result);
}