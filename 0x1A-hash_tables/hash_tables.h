#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

hash_table_t *create_hash_table(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_insert(hash_table_t *ht, const char *key, const char *value);
char *hash_table_search(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);

typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *next;
	struct shash_node_s *sprev;
	struct shash_node_s *snext;
} shash_node_t;

typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
} shash_table_t;

shash_table_t *create_sorted_hash_table(unsigned long int size);
int sorted_hash_table_insert(shash_table_t *ht, const char *key, const char *value);
char *sorted_hash_table_search(const shash_table_t *ht, const char *key);
void sorted_hash_table_print(const shash_table_t *ht);
void sorted_hash_table_print_rev(const shash_table_t *ht);
void sorted_hash_table_delete(shash_table_t *ht);

#endif /* HASH_TABLES_H */
