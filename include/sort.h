#ifndef SORT_H_
#define SORT_H_

#include <stddef.h>
#include "function_alias.h"

/**
 * A generic binary search.
 *
 * Returns 1 if the search item was found.
 * Returns 0 if the search item was not found.
 * Returns -1 if there was an error. [Comparator return value.]
 */
int generic_binary_search(
  void* data,
  void* search,
  size_t elements,
  size_t size,
  Comparator compare
);

/**
 * A generic in place buble sort.
 *
 * Returns 1 if the sort completed.
 * Returns -1 if there was an error. [Comparator return value.]
 */
int generic_bubble_sort(
  void* data, 
  size_t elements, 
  size_t size,
  Comparator compare
);

/**
 * A generic in place insertion sort.
 */
void generic_insertion_sort(
  void* data, 
  size_t elements, 
  size_t size,
  Comparator compare
);

/**
 * A generic in place quick sort.
 */
void generic_quick_sort(
  void* data, 
  size_t elements, 
  size_t size,
  Comparator compare
);

/**
 * A generic in place selection sort.
 *
 * Returns 1 if the sort completed.
 * Returns -1 if there was an error. [Comparator return value.]
 */
int generic_selection_sort(
  void* data, 
  size_t elements, 
  size_t size,
  Comparator compare
);

#endif // SORT_H_
