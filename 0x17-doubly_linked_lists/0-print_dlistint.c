#include <stdio.h>
#include "lists.h"

/**
* print_dlistint - Print a double linked list
*
* @h: Pointer to the linked list
*
* Return: The size of the linked list
*/
size_t print_dlistint(const dlistint_t *h)
{
size_t size = 0;

while (h != NULL)
{
printf("%d\n", h->n);
size++;
h = h->next;
}

return (size);
}
