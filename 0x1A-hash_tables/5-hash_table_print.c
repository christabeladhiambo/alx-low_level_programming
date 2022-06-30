nclude "hash_tables.h"



/**

  *hash_table_print - Print the hash table as a python directory

  *

  * @ht: Pointer to the hash table

  *

  * Return: Anything, cause void function

  */

void hash_table_print(const hash_table_t *ht)

{

		unsigned long int i, j = 0;

			hash_node_t *head;



				if (!ht || !ht->array || ht->size == 0)

							return;



					printf("{");

						for (i = 0; i < ht->size; i++)

								{

											head = ht->array[i];

													while (head)

																{

																				if (j != 0)

																									printf(", ");

																							printf("'%s': '%s'", head->key, head->value);

																										head = head->next;

																													j++;

																															}

														}

							printf("}\n");

}
