#include "lists.h"

/**
* get_dnodeint_at_index - Get a node by an index value
*
* @head: Pointer to the linked list
* @index: Index
*
* Return: A pointer to the new created node
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
size_t idx = 0;
dlistint_t *browse = head;

while (idx < index)
{
if (browse == NULL)
return (NULL);
browse = browse->next;
idx++;
}
return (browse);
}
