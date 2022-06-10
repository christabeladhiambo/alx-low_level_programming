#include "lists.h"
#include <stdlib.h>

/**
* add_dnodeint_end - Add a new node to the end of the linked list
*
* @head: Double pointer to the linked list
* @n: Value to fill
*
* Return: A pointer to the new created node
*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
dlistint_t *new, *browse;

if (head == NULL)
return (NULL);

new = malloc(sizeof(dlistint_t));
if (!new)
return (NULL);
new->n = n;
new->prev = NULL;
new->next = NULL;
if (*head == NULL)
*head = new;
else
{
browse = *head;
while (browse->next != NULL)
browse = browse->next;
browse->next = new;
new->prev = browse;
}

return (new);
}
