#include "./hash_tables.h"

/**
 * hash_table_print - Prints the key-value pairs of a hash table.
 * @ht: A pointer to the hash table to print.
 *
 * Description: Key-value pairs are printed in the order they appear in
 *              the array of the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
    hash_node_t *node;
    unsigned long int i;
    unsigned char first_pair = 1;

    if (ht == NULL)
        return;

    printf("{");
    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node != NULL)
        {
            if (first_pair == 0)
                printf(", ");
            printf("'%s': '%s'", node->key, node->value);
            first_pair = 0;
            node = node->next;
        }
    }
    printf("}\n");
}
