//Include header file
#include "hash_tables.h"

//Create a sorted hash table
shash_table_t *shash_table_create(unsigned long int size) {
  //Allocate memory for the hash table
  shash_table_t *ht = malloc(sizeof(shash_table_t));
  if (ht == NULL)
    return NULL;

  //Initialize variables of the hash table
  ht->size = size;
  ht->array = malloc(sizeof(shash_node_t *) * size);
  if (ht->array == NULL)
    return NULL;
  for (unsigned long int i = 0; i < size; i++)
    ht->array[i] = NULL;
  ht->shead = NULL;
  ht->stail = NULL;

  return ht;
}

//Add a new key-value pair to the sorted hash table
int shash_table_set(shash_table_t *ht, const char *key, const char *value) {
  //Allocate memory for the new node
  shash_node_t *new_node = malloc(sizeof(shash_node_t));
  if (new_node == NULL)
    return 0;

  //Set values of the new node
  new_node->key = strdup(key);
  if (new_node->key == NULL) {
    free(new_node);
    return 0;
  }
  new_node->value = strdup(value);
  if (new_node->value == NULL) {
    free(new_node->key);
    free(new_node);
    return 0;
  }

  //Calculate index of the new node
  unsigned long int index = hash_djb2((unsigned char *)key) % ht->size;

  //Insert the new node into the sorted linked list
  if (ht->array[index] == NULL) {
    new_node->next = NULL;
    new_node->sprev = NULL;
    new_node->snext = NULL;
    ht->array[index] = new_node;
  } else {
    shash_node_t *tmp = ht->array[index];
    while (tmp != NULL && strcmp(key, tmp->key) > 0)
      tmp = tmp->snext;
    if (tmp == NULL) {
      new_node->next = NULL;
      new_node->sprev = ht->stail;
      new_node->snext = NULL;
      ht->stail = new_node;
      new_node->sprev->snext = new_node;
    } else {
      if (tmp->sprev == NULL) {
        new_node->next = tmp;
        new_node->sprev = NULL;
        new_node->snext = tmp;
        tmp->sprev = new_node;
        ht->array[index] = new_node;
      } else {
        new_node->next = tmp;
        new_node->sprev = tmp->sprev;
        new_node->snext = tmp;
        tmp->sprev->snext = new_node;
        tmp->sprev = new_node;
      }
    }
  }

  return 1;
}
//Declare and define the remaining functions for getting a value from a key, printing the table, printing the table in reverse order, and deleting the table.
// Check if hash table pointer, key, and value are not NULL, and key is not an empty string
if (ht == NULL || key == NULL || *key == '\0' || value == NULL) {
    return 0;
}

// Copy the value string
char *value_copy = strdup(value);
if (value_copy == NULL) {
    return 0;
}

// Get the index of the key in the hash table array
unsigned long int index = key_index((const unsigned char *)key, ht->size);

// Try to find the node with the same key in the sorted linked list
shash_node_t *tmp = ht->shead;
while (tmp) {
    if (strcmp(tmp->key, key) == 0) {
        // Update the value if the key is found
        free(tmp->value);
        tmp->value = value_copy;
        return 1;
    }
    tmp = tmp->snext;
}

// Allocate a new node and set its key, value, and next pointer
shash_node_t *new_node = malloc(sizeof(shash_node_t));
if (new_node == NULL) {
    free(value_copy);
    return 0;
}
new_node->key = strdup(key);
if (new_node->key == NULL) {
    free(value_copy);
    free(new_node);
    return 0;
}
new_node->value = value_copy;
new_node->next = ht->array[index];
ht->array[index] = new_node;

// Insert the new node into the sorted linked list
if (ht->shead == NULL) {
    // If the sorted linked list is empty, make the new node the head and tail
    new_node->sprev = NULL;
    new_node->snext = NULL;
    ht->shead = new_node;
    ht->stail = new_node;
} else if (strcmp(ht->shead->key, key) > 0) {
    // If the new node should be inserted before the head, update the head
    new_node->sprev = NULL;
    new_node->snext = ht->shead;
    ht->shead->sprev = new_node;
    ht->shead = new_node;
} else {
    // Otherwise, find the correct position to insert the new node
    shash_node_t *current = ht->shead;
    while (current->snext != NULL && strcmp(current->snext->key, key) < 0) {
        current = current->snext;
    }
    new_node->sprev = current;
    new_node->snext = current->snext;
    if (current->snext == NULL) {
        ht->stail = new_node;
    } else {
        current->snext->sprev = new_node;
    }
    current->snext = new_node;
}
