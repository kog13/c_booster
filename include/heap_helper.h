#ifndef C_BOOSTER_HEAP_HELPER_H_
#define C_BOOSTER_HEAP_HELPER_H_

/*******************************************************************************
**                                Heap Helpers
**----------------------------------------------------------------------------*/

#include <stddef.h>

/**
 * Given a heap node index return the parent index.
 */
size_t get_heap_parent_index(size_t index);

/**
 * Given a heap node index return the left child index.
 */
size_t get_heap_left_index(size_t index);

/**
 * Given a heap node index return the right child index.
 */
size_t get_heap_right_index(size_t index);

#endif // C_BOOSTER_HEAP_HELPER_H_
