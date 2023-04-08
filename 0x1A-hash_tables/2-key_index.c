/*
 * key_index - gets the index where a key/value pair should be stored in
 * the hash table's array
 *
 * @key: the key of the key/value pair
 * @size: the size of the hash table's array
 *
 * Return: the index where the key/value pair should be stored
 *
 * Description: uses the djb2 hash algorithm to calculate the index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    unsigned long int hash_value = hash_djb2(key);
    unsigned long int index = hash_value % size;
    return index;
}
