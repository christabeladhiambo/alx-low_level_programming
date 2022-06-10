#include "lists.h"


/**
* delete_dnodeint_at_index - Delete a node at a certain index
*
* @head: Double pointer to the linked list
* @index: Index
*
* Return: 1 if all work well, -1 if any issues
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
unsigned int i = 0;
dlistint_t *browse = *head;

while (browse != NULL && i < index)
{
browse = browse->next;
i++;
}
if (browse == NULL)
return (-1);
if (i == 0 && browse->next == NULL)
*head = NULL;
else if (i == 0 && browse->next != NULL)
{
browse->next->prev = NULL;
(*head) = browse->next;
}
else if (i != 0 && browse->next == NULL)
{
browse->prev->next = NULL;
}
else
{
browse->next->prev = browse->prev;
browse->prev->next = browse->next;
}
free(browse);
return (1);
}
