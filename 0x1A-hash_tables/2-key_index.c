#include "hash_tables.h"
/**
 * key_index - Get the index for storing a key in a hash table.
 * @key: The key to get the index of.
 * @size: The size of the hash table array.
 *
 * Return: The index of the key.
 *
 * Description: Uses the djb2 algorithm for index computation.
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
