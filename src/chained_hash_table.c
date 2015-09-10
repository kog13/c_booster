#include <stdlib.h>
#include <stdio.h>
#include "chained_hash_table.h"

ChainedHashTable* init_chained_hash_table(
  ChainedHashTable* hash_table,
  size_t element_size,
  unsigned int buckets, 
  hash_function hash
)
{
  // create an array of linked_lists for holding data.
  LinkedList* table;
  table = (LinkedList*) malloc(sizeof(LinkedList) * buckets);

  if (table == NULL) {
    fputs("Not enough memory to allocate table for hash_table.", stderr);
    exit(1);
  }

  // init each linked list in the table array.
  for (int i = 0; i < buckets; i++) {
    init_linked_list(&table[i], element_size);
  }

  hash_table->element_size = element_size;
  hash_table->buckets = buckets;
  hash_table->size = 0;
  hash_table->hash = hash;
  hash_table->table = table;

  return hash_table;
}

void free_chained_hash_table(ChainedHashTable* hash_table)
{
}

void insert_chained_hash_table(ChainedHashTable *hash_table, void* data)
{
  unsigned int index = hash_table->hash(data) % hash_table->buckets;

  LinkedList* list = &hash_table->table[index];
  push_back_linked_list(list, data);

  hash_table->size++;
}

void lookup_chained_hash_table(ChainedHashTable* hash_table, void** data)
{
}

void remove_chained_hash_table(ChainedHashTable* list, void** data)
{
}

unsigned int size_chained_hash_table(ChainedHashTable* hash_table)
{
  return hash_table->size;
}
