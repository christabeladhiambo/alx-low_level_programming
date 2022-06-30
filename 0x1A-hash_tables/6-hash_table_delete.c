nclude "hash_tables.h"



/**

  * hash_table_delete - Del the hash table

  *

  * @ht: Pointer to the hash table

  *

  * Return: Anything, cause void function

  */

void hash_table_delete(hash_table_t *ht)

{

		unsigned long int i;

			hash_node_t *head, *tmp;



				if (!ht || !ht->array || ht->size == 0)

							return;



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
