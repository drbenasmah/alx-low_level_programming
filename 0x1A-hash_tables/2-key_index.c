#include "hash_tables.h"

/**
 * key_index - gives the index of a key.
 * @key: the key
 * @size: size of the hash table array
 *
 * Return: index of the key/value pair in the hash table array
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    unsigned long int hash_val;

    hash_val = hash_djb2(key);
    return (hash_val % size);
}
