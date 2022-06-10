#include <stdlib.h>
#include "lists.h"

/**
* add_dnodeint - Add a node at the beginning of the linked list
*
* @head: Double pointer to the linked list
* @n: Value to fill
*
* Return: A pointer to the new created node
*/
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
dlistint_t *new;

if (head == NULL)
return (NULL);
new = malloc(sizeof(dlistint_t));
if (new == NULL)
return (NULL);

new->n = n;
new->next = *head;
new->prev = NULL;
if (*head != NULL)
(*head)->prev = new;
*head = new;
return (new);
}
