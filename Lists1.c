#include "shell.h"

/**
 * count_list_nodes - counts the number of nodes in a list
 * @head: pointer to first node
 *
 * Return: list size
 */

size_t count_list_nodes(const list_t *head)
{
    size_t count = 0;

    while (head)
    {
        head = head->next;
        count++;
    }

    return(count);
}

/**
 * convert_list_to_strings - returns an array of strings
 * @start: pointer to first node
 *
 * Return: array of strings
 */

char **convert_list_to_strings(list_t *start)
{
    list_t *node = start;
    size_t node_count = list_len(start), i, j;
    char **string_array;
    char *string;

    if (!start || !node_count)
        return(NULL);

    string_array = malloc(sizeof(char *) * (node_count + 1));
    if (!string_array)
        return(NULL);

    for (i = 0; node; node = node->next, i++)
    {
        string = malloc(_strlen(node->str) + 1);
        if (!string)
        {
            for (j = 0; j < i; j++)
                free(string_array[j]);
            free(string_array);
            return(NULL);
        }

        string = f_strcpy(string, node->str);
        string_array[i] = string;
    }
    string_array[i] = NULL;
    return(string_array);
}

/**
 * print_custom_list - prints all elements of a linked list
 * @head: pointer to first node
 *
 * Return: size of list
 */

size_t print_custom_list(const list_t *head)
{
    size_t count = 0;

    while (head)
    {
        _puts(convert_number(head->num, 10, 0));
        _putchar(':');
        _putchar(' ');
        _puts(head->str ? head->str : "(nil)");
        _puts("\n");
        head = head->next;
        count++;
    }

    return(count);
}

/**
 * find_node_starts_with - prints specified node from string
 * @start: pointer to linked list
 * @search_prefix: the string to match
 * @target_char: the next character after prefix to match
 *
 * Return: match node or null
 */

list_t *find_node_starts_with(list_t *start, char *search_prefix, char target_char)
{
    char *prefix_ptr = NULL;

    while (start)
    {
        prefix_ptr = starts_with(start->str, search_prefix);
        if (prefix_ptr && ((target_char == -1) || (*prefix_ptr == target_char)))
            return start;
        start = start->next;
    }

    return(NULL);
}

/**
 * find_node_index - returns the index of a node
 * @start: the first node in linked list
 * @target_node: pointer to the node
 *
 * Return: index of node or -1
 */

ssize_t find_node_index(list_t *start, list_t *target_node)
{
    size_t index = 0;

    while (start)
    {
        if (start == target_node)
            return index;
        
        start = start->next;
        index++;
    }

    return(-1);
}