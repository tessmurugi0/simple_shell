#include "shell.h"

/**
 * release_list - function that frees all nodes in a list
 * @start_ptr: the head nide
 * 
 * Return: void
*/
void release_list(list_t **start_ptr)
{
    list_t *current_node, *next_node, *start;

    if (!start_ptr || !*start_ptr)
        return;

    start = *start_ptr;
    current_node = start;

    while (current_node)
    {
        next_node = current_node->next;
        free(current_node->str);
        free(current_node);
        current_node = next_node;
    }

    *start_ptr = NULL;
}


/**
 * delete_node_at_index - clears a specific nodfe
 * @start_ptr: first node
 * @position: index of node in question
 * 
 * Return: on success, 1
*/
int delete_node_at_index(list_t **start_ptr, unsigned int position)
{
    list_t *current_node;
    list_t *previous_node;
    unsigned int i = 0;

    if (!start_ptr || !*start_ptr)
        return(0);

    if (!position)
    {
        current_node = *start_ptr;
        *start_ptr = (*start_ptr)->next;
        free(current_node->str);
        free(current_node);
        return(1);
    }

    current_node = *start_ptr;
    while (current_node)
    {
        if (i == position)
        {
            previous_node->next = current_node->next;
            free(current_node->str);
            free(current_node);
            return(1);
        }
        i++;
        previous_node = current_node;
        current_node = current_node->next;
    }

    return(0);
}

/**
 * print_list_strings - prints the string of a linked
 * list
 * @head: - the first node
 * 
 * @Return: the linked list
*/

size_t print_list_strings(const list_t *head)
{
    size_t count = 0;

    while (head)
    {
        _puts(head->str ? head->str : "(nil)");
        _puts("\n");
        head = head->next;
        count++;
    }

    return(count);
}

/**
 * add_node_end - inserts the last node to a linked list
 * @head: first node
 * @str: str field of node
 * @num: indx pf node
 *
 * Return: size of list
 */

list_t *add_last_node(list_t **start_ptr, const char *text, int number)
{
    list_t *new_node, *current_node;

    if (!start_ptr)
        return(NULL);

    current_node = *start_ptr;
    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return(NULL);

    _memset((void *)new_node, 0, sizeof(list_t));
    new_node->num = number;

    if (text)
    {
        new_node->str = _strdup(text);
        if (!new_node->str)
        {
            free(new_node);
            return(NULL);
        }
    }

    if (current_node)
    {
        while (current_node->next)
            current_node = current_node->next;
        current_node->next = new_node;
    }
    else
        *start_ptr = new_node;

    return(new_node);
}

/**
 * add_new_node - adds a node to the start of the list
 * @start: address of pointer to head node
 * @text: str field of node
 * @number: node index used by history
 *
 * Return: size of list
 */

list_t *add_new_node(list_t **start, const char *text, int number)
{
    list_t *new_start;

    if (!start)
        return(NULL);

    new_start = malloc(sizeof(list_t));
    if (!new_start)
        return(NULL);

    _memset((void *)new_start, 0, sizeof(list_t));
    new_start->num = number;

    if (text)
    {
        new_start->str = _strdup(text);
        if (!new_start->str)
        {
            free(new_start);
            return(NULL);
        }
    }

    new_start->next = *start;
    *start = new_start;

    return(new_start);
}

