#include "shell.h"


/**
 * f_erratoi - converts string to integer
 * @s: the string to convert
 * 
 * Return: integer numbers on success, on error
 * error message
*/

int custom_atoi(const char *s)
{
    int i = 0;
    int sign = 1;
    long int result = 0;

    if (*s == '-')
    {
        sign = -1;
        s++;
    }
    else if (*s == '+')
    {
        s++;
    }

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            result *= 10;
            result += (s[i] - '0');
            if (sign == 1 && result > INT_MAX)
                return INT_MAX;
	    else if (sign == -1 && -result < INT_MIN)
                return INT_MIN;
        }
        else
        {
            /**Invalid input, return 0 or handle as needed for your use case.*/
            return 0;
        }
    }
    return sign * (int)result;
}



/**
 * print_error - prints an error message
 * @info: information on the struct used
 * @estr: the error type
 *
 * Return: on success, 0
*/

void print_error(info_t *info, char *estr)
{
        f_eputs(info->fname);
        f_eputs(": ");
        print_d(info->line_count, STDERR_FILENO);
        f_eputs(": ");
        f_eputs(info->argv[0]);
        f_eputs(": ");
        f_eputs(estr);
}

/**
* print-d - Creates a decimal integer number
 * @input: data fetced from the standard input
 * @fd- file descriptor
 * 
 * Return: number
*/

int print_d(int input, int fd)
{
    int (*__putchar)(char) = (fd == STDERR_FILENO) ? _eputchar : _putchar;
    int count = 0;
    unsigned int _abs_, current;

    if (input < 0)
    {
        __putchar('-');
        count++;
        _abs_ = -input;
    }
    else
    {
        _abs_ = input;
    }

    if (_abs_ == 0)
    {
        __putchar('0');
        return(1);
    }

    int i;
    for (i = 1000000000; i > 0; i /= 10)
    {
        if (_abs_ / i)
		{
            current = _abs_ / i;
            __putchar('0' + current);
            count++;
        }
        else if (count > 0)
        {
            __putchar('0');
            count++;
        }
        _abs_ %= i;
    }

    return(count);
}

/**
 * convert-number - converts a function to an integer
 * @num: the string literal to be converted
 * @base: the base number
 * @flags: function arguments
 *
 * Return: Pointer to the converted number
*/

char *convert_number(long int num, int base, int flags)
{
    static char buffer[50];
    char sign = 0;
    char *array;
    char *ptr;
    unsigned long n = num;

    if (!(flags & 0x01) && num < 0)
	    {
        n = -num;
        sign = '-';
    }

    array = (flags & 0x02) ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = '\0';

    do {
        *--ptr = array[n % base];
        n /= base;
    } while (n != 0);

    if (sign)
        *--ptr = sign;

    return ptr;
}

/**
 * remove_comments - removes comments from m a block of C code
 * @buf: variable used to store the code before comments
 * are removed
 *
 * Return: NULL
*/

void remove_comments(char *buf)
{
    int i;
    comment_found = false;

    for (i = 0; buf[i] != '\0'; i++)
    {
        if (buf[i] == '#' && (i == 0 || buf[i - 1] == ' '))
        {
            comment_found = true;
            buf[i] = '\0';
            break;
        }
    }

    // If a comment was found and removed, remove any trailing spaces.
    if (comment_found)
    {
        for (i--; i >= 0; i--)
        {
            if (buf[i] == ' ')
                buf[i] = '\0';
            else
                break;
        }
    }
}
