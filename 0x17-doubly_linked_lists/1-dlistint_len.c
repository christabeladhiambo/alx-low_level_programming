#include <stdio.h>
#include "lists.h"

/**
* dlistint_len - Return the size of the double linked list
*
* @h: Pointer to the linked list
*
* Return: The size of the linked list
*/
size_t dlistint_len(const dlistint_t *h)
{
size_t size = 0;

while (h != NULL)
{
size++;
h = h->next;
}

return (size);
}
