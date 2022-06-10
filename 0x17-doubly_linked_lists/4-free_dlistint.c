#include <stdlib.h>
#include "lists.h"

/**
* free_dlistint - Free a linked list
*
* @head: Pointer to the linked list
*
* Return: Anything, cause void function
*/
void free_dlistint(dlistint_t *head)
{
dlistint_t *cur;

while (head != NULL)
{
cur = head;
head = head->next;
free(cur);
}
}
