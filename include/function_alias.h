#ifndef C_BOOSTER_ITERATOR_H_
#define C_BOOSTER_ITERATOR_H_

/*******************************************************************************
**                               Function Aliases
**----------------------------------------------------------------------------*/

/**
 * An iterator function.
 */
typedef void (*Iterator)(void*);

/**
 * A memory reclaiming (freeing) function.
 */
typedef void (*Reclaim)(void*);

/**
 * Generic comparator for two items.
 *
 * Returns 0 if items are equal.
 * Returns 1 if left is greater than right.
 * Returns -1 if left is less than right.
 */
typedef int (*Comparator)(void* left, void* right);

#endif // C_BOOSTER_ITERATOR_H_
