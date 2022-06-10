#include "lists.h"


/**
* insert_dnodeint_at_index - Insert a node at an given index
*
* @h: Double pointer to the linked list
* @idx: Index
* @n: Value to fill
*
* Return: A pointer to the new created node
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *browse = *h;
dlistint_t *new = NULL;
unsigned int i = 0;
if (h == NULL)
return (NULL);
if (idx == 0)
return (add_dnodeint(h, n));
while (i < idx && browse->next != NULL)
{
i++;
browse = browse->next;
}
if (browse->next == NULL && i == idx - 1)
return (add_dnodeint_end(h, n));
else if (i == idx)
{
new = malloc(sizeof(dlistint_t));
if (!new)
return (NULL);
new->n = n;
browse->prev->next = new;
new->next = browse;
new->prev = browse->prev;
browse->prev = new;
}
return (new);
}
