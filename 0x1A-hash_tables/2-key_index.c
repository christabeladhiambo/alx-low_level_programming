#include "hash_tables.h"

/**
* key_index - Get the index of a key for the hash table
*
* @key: The key to trasform into index
* @size: The size of the hash table
*
* Return: The index
*/
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
unsigned long int index;

index = hash_djb2(key);

return (index %= size);
}
