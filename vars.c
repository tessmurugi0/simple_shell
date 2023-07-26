#include "shell.h"

/**
 * check_command_chain - function checks for chain delimiters
 * in buffer
 * @information: the parameter struct
 * @buffer: the char buffer
 * @index: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */

int check_command_chain(info_t *information, char *buffer, size_t *index)
{
    size_t j = *index;

    if (buffer[j] == '|' && buffer[j + 1] == '|')
    {
        buffer[j] = 0;
        j++;
        information->cmd_buf_type = CMD_OR;
    }
    else if (buffer[j] == '&' && buffer[j + 1] == '&')
    {
        buffer[j] = 0;
        j++;
        information->cmd_buf_type = CMD_AND;
    }
    else if (buffer[j] == ';') /* found end of this command */
    {
        buffer[j] = 0; /* replace semicolon with null */
        information->cmd_buf_type = CMD_CHAIN;
    }
    else
        return(0);
    
    *index = j;
    return(1);
}

/**
 * evaluate_command_chain - checks to continue chaining based on last status
 * @information: the parameter struct
 * @buffer: the char buffer
 * @index: address of current position in buf
 * @current_index: starting position in buf
 * @buffer_length: length of buf
 *
 * Return: Void
 */

void evaluate_command_chain(info_t *information, char *buffer, size_t *index, size_t current_index, size_t buffer_length)
{
    size_t j = *index;

    if (information->cmd_buf_type == CMD_AND)
    {
        if (information->status)
        {
            buffer[current_index] = 0;
            j = buffer_length;
        }
    }
    if (information->cmd_buf_type == CMD_OR)
    {
        if (!information->status)
        {
            buffer[current_index] = 0;
            j = buffer_length;
        }
    }

    *index = j;
}

/**
 * replace_command_alias - replaces an alias in the tokenized string
 * @information: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */

int replace_command_alias(info_t *information)
{
    int i;
    list_t *node;
    char *found;

    for (i = 0; i < 10; i++)
    {
        node = find_node_starts_with(information->alias, information->arguments[0], '=');
        if (!node)
            return(0);
        free(information->arg[0]);
        found = _strchr(node->str, '=');
        if (!found)
            return(0);
        found = f_strdup(found + 1);
        if (!found)
            return(0);
        information->arg[0] = found;
    }
    return(1);
}

/**
 * replace_variables - replaces vars in the tokenized string
 * @information: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */

int replace_variables(info_t *information)
{
    int i = 0;
    list_t *node;

    for (i = 0; information->arg[i]; i++)
    {
        if (information->arg[i][0] != '$' || !information->arg[i][1])
            continue;

        if (!f_strcmp(information->arg[i], "$?"))
        {
            replace_string_content(&(information->arg[i]),
                    f_strdup(convert_number(information->status, 10, 0)));
            continue;
        }
        if (!f_strcmp(information->arg[i], "$$"))
        {
            replace_string_content(&(information->arg[i]),
                    f_strdup(convert_number(getpid(), 10, 0)));
            continue;
        }
        node = find_node_starts_with(information->env, &(information->arg[i][1]), '=');
        if (node)
        {
            replace_string_content(&(information->arg[i]),
                    f_strdup(_strchr(node->str, '=') + 1));
            continue;
        }
        replace_string_content(&(information->arg[i]), f_strdup(""));
    }
    return(0);
}

/**
 * replace_string_content - replaces string
 * @old_str: address of old string
 * @new_str: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */

int replace_string_content(char **old_str, char *new_str)
{
    free(*old_str);
    *old_str = new_str;
    return(1);
}
