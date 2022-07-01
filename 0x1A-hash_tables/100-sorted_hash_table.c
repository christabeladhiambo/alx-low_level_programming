#include "hash_tables.h"

/**
* shash_table_create - Create a hash table
*
* @size: The size of the hash table
*
* Return: Pointer to the hash table
*/
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;
	ht->array = calloc(ht->size, sizeof(shash_node_t));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	return (ht);
}

/**
* shash_table_print_rev - Print the shash table in rev
*
* @ht: Pointer to the shash table
*
* Return: Anything, cause void function
*/
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *rev_browse;
	int j = 0;

	if (ht == NULL || ht->array == NULL)
		return;
	rev_browse = ht->stail;
	printf("{");
	while (rev_browse != NULL)
	{
		if (j != 0)
			printf(", ");
		printf("'%s': '%s'", rev_browse->key, rev_browse->value);
		rev_browse = rev_browse->sprev;
		j++;
	}
	printf("}\n");
}

/**
* shash_table_print - Print the shash table
*
* @ht: Pointer to the shash table
*
* Return: Anything, cause void function
*/
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *browse;
	int j = 0;

	if (ht == NULL || ht->array == NULL)
		return;

	browse = ht->shead;
	printf("{");
	while (browse != NULL)
	{
		if (j != 0)
			printf(", ");
		printf("'%s': '%s'", browse->key, browse->value);
		browse = browse->snext;
		j++;
	}
	printf("}\n");
}

/**
* shash_sorted_node - Add the node to the sorted linked list
*
* @ht: Pointer to the hash table
* @node: Node to fill into the ll
*
* Return: Anything, cause void function
*/
void shash_sorted_node(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *browse;

	if (ht->shead == NULL && ht->stail == NULL)
	{
		ht->shead = ht->stail = node;
		return;
	}
	browse = ht->shead;
	while (browse != NULL)
	{
		if (strcmp(node->key, browse->key) < 0)
		{
			node->snext = browse;
			node->sprev = browse->sprev;
			browse->sprev = node;
			if (node->sprev)
				node->sprev->snext = node;
			else
				ht->shead = node;
			return;
		}
		browse = browse->snext;
	}
	node->sprev = ht->stail;
	ht->stail->snext = node;
	ht->stail = node;
}

/**
* shash_table_set - Set the key and value into the shash table
*
* @ht: Pointer to the hash table
* @key: Key to fill
* @value: Value to fill
*
* Return: 1 if success, 0 else
*/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *head;
	shash_node_t *new_node = NULL;

	if (!ht || !ht->array || ht->size == 0 || !key ||
		strcmp(key, "") == 0 || !value)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	head = ht->array[index];
	while (head)
	{
		if (strcmp(head->key, key) == 0)
		{
			free(head->value);
			head->value = strdup(value);
			if (head->value == NULL)
				return (0);
			return (1);
		}
		head = head->next;
	}
	new_node = create_node(key, value);
	if (!new_node)
		return (0);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	shash_sorted_node(ht, new_node);
	return (1);
}

/**
* create_node - create a node
*
* @key: The key of the node
* @value: The value of the key
*
* Return: The node, NULL if any issues
*/
shash_node_t *create_node(const char *key, const char *value)
{
	shash_node_t *new_node = malloc(sizeof(shash_node_t));

	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}
	new_node->snext = NULL;
	new_node->sprev = NULL;
	new_node->next = NULL;
	return (new_node);
}

/**
* shash_table_delete - Del the hash table
*
* @ht: Pointer to the hash table
*
* Return: Anything, cause void function
*/
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *head, *tmp;

	if (!ht || !ht->array)
		return;
	if (ht->size == 0)
	{
		free(ht->array);
		free(ht);
		return;
	}

	for (i = 0; i < ht->size; i++)
	{
		head = ht->array[i];
		while (head)
		{
			tmp = head;
			head = head->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
	}
	free(ht->array);
	free(ht);
}

/**
* shash_table_get - Get the content of a key in the hash
*
* @ht: The given key
* @key: The given key to get the value
*
* Return: The value
*/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *head;

	if (!ht || !ht->array || ht->size == 0 || !key ||
		strcmp(key, "") == 0)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	head = ht->array[index];

	while (head)
	{
		if (strcmp(head->key, key) == 0)
			return (head->value);
		head = head->next;
	}
	return (NULL);
}
