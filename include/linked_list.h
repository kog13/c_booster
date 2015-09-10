#ifndef C_BOOSTER_LINKED_LIST_H_
#define C_BOOSTER_LINKED_LIST_H_

#include <stddef.h>
#include "function_alias.h"

/*******************************************************************************
**                                LinkedList
**----------------------------------------------------------------------------*/

/**
 * A linked list node.
 */
typedef struct __LinkedListNode
{
  struct __LinkedListNode *next; // next element in list.
  void* value;                   // value of the node.
} LinkedListNode;

/**
 * A linked list.
 */
typedef struct
{
  LinkedListNode *head; // head node, sometimes known as the root node.
  unsigned int size;    // current number of nodes in the list.
  size_t element_size;  // the size of each element.
} LinkedList;

/**
 * Initializes a linked list.
 */
LinkedList* init_linked_list(LinkedList* list, size_t element_size);

/**
 * Allocates a single node for a linked list.
 */
LinkedListNode* alloc_linked_list_node();

/**
 * Returns a pointer to the last node in the list.
 */
LinkedListNode* first_node_linked_list(LinkedList* list);

/**
 * Free's the entire linked list.
 *
 * Reclaim is an optional function that will free the data at each node.
 */
void free_linked_list(LinkedList* list, Reclaim reclaim);

/**
 * Inserts a new node directly after the node passed.
 *
 * Will insert the data at the head of the list if previous_node is passed as
 * NULL.
 */
LinkedListNode* insert_next_linked_list(
  LinkedList* list, 
  LinkedListNode* previous_node, 
  void* data
);

/**
 * Returns a pointer to the first node (head) in the list.
 */
LinkedListNode* last_node_linked_list(LinkedList* list);

/**
 * Adds a new node to the back of the list.
 */
LinkedListNode* push_back_linked_list(LinkedList* list, void* data);

/**
 * Removes the node after the node passed from a linked list.
 *
 * Will remove the head of the list if previous_node is passed as NULL.
 */
void remove_next_linked_list(LinkedList* list, LinkedListNode* previous_node);

/**
 * Returns the current size of the linked list.
 */
unsigned int size_linked_list(LinkedList* list);

/**
 * Linked list can also be refered to as a ForwardList -- as it is in C++.
 */
typedef LinkedList ForwardList;
typedef LinkedListNode ForwardListNode;

#endif // C_BOOSTER_LINKED_LIST_H_
