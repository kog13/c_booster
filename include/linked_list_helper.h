#ifndef C_BOOSTER_LINKED_LIST_HELPER_H_
#define C_BOOSTER_LINKED_LIST_HELPER_H_

#include "linked_list.h"
#include "function_alias.h"

/*******************************************************************************
**                              LinkedList Helpers
**----------------------------------------------------------------------------*/

/**
 * Removes any duplicates from the unsorted linked list.
 */
void remove_duplicated_linked_list(LinkedList* list);

/**
 * Iterates through each element in the linked list calling iterator for each.
 */
void for_each_linked_list(LinkedList* list, Iterator iterator);

#endif // C_BOOSTER_LINKED_LIST_HELPER_H_
