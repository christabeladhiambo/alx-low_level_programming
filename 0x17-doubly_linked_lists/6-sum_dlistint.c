#include "lists.h"

/**
* sum_dlistint - Sum the whole list number
*
* @head: Pointer to the linked list
*
* Return: The sum of the list
*/
int sum_dlistint(dlistint_t *head)
{
dlistint_t *browse = head;
int sum = 0;

while (browse)
{
sum += browse->n;
browse = browse->next;
}

return (sum);
}
