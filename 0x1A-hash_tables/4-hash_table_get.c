#include "hash_tables.h"

/**
* hash_table_get - Get the content of a key in the hash
*
* @ht: The given key
* @key: The given key to get the value
*
* Return: The value
*/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *head;

	if (!ht || !ht->array || ht->size == 0)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	head = ht->array[index];

	if (!head)
		return (NULL);

	while (head)
	{
		if (strcmp(head->key, key) == 0)
			return (head->value);
		head = head->next;
	}
	return (NULL);
}
