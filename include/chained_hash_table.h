#ifndef C_BOOSTER_CHAINED_HASH_TABLE_H_
#define C_BOOSTER_CHAINED_HASH_TABLE_H_

#include <stddef.h>
#include "linked_list.h"

/*******************************************************************************
**                            ChainedHashTable
**----------------------------------------------------------------------------*/

/**
 * Hash function pointer signature.
 */
typedef unsigned int (*hash_function)(const void* key);

/**
 */
typedef struct
{
  unsigned int buckets; // number of buckets.
  unsigned int size;    // number of elements in the table.
  size_t element_size;  // size in bytes of elements stored.
  hash_function hash;   // key hashing function.
  LinkedList* table;    // chained table holding data.
} ChainedHashTable;

/**
 * Initializes a chained hash table.
 */
ChainedHashTable* init_chained_hash_table(
  ChainedHashTable* hash_table,
  size_t element_size,
  unsigned int buckets, 
  hash_function hash
);

/**
 * Free's the entire chained hash table.
 */
void free_chained_hash_table(ChainedHashTable* hash_table);

/**
 * Inserts data into the hash table.
 */
void insert_chained_hash_table(ChainedHashTable* hash_table, void* data);

/**
 * Performs a lookup into the hash table based on a key.
 */
void lookup_chained_hash_table(ChainedHashTable* hash_table, void** data);

/**
 * Removes an element from the hash table based on a key.
 */
void remove_chained_hash_table(ChainedHashTable* hash_table, void** data);

/**
 * Returns the size (number of elements) of the hash table.
 */
unsigned int size_chained_hash_table(ChainedHashTable* hash_table);

#endif // C_BOOSTER_CHAINED_HASH_TABLE_H_
