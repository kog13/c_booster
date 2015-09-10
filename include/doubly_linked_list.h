#ifndef C_BOOSTER_DOUBLY_LINKED_LIST_H_
#define C_BOOSTER_DOUBLY_LINKED_LIST_H_

/*******************************************************************************
**                            DoublyLinkedList
**----------------------------------------------------------------------------*/

/**
 * A doubly linked list node.
 */
typedef struct __DoublyLinkedListNode
{
  struct __DoublyLinkedListNode *next;     // next element in the list.
  struct __DoublyLinkedListNode *previous; // previous element in the list.
  void* value;                             // value of the node.
} DoublyLinkedListNode;

/**
 * A doubly linked list.
 */
typedef struct {
  DoublyLinkedListNode *head; // head node, sometimes known as the root node.
  unsigned int size;          // current number of nodes in the list.
} DoublyLinkedList;

/**
 * Allocates a doubly linked list.
 */
DoublyLinkedList* init_doubly_linked_list(DoublyLinkedList* list);

/**
 * Allocates a single node for a doubly linked list.
 */
DoublyLinkedListNode* alloc_doubly_linked_list_node();

/**
 * Adds a new node to the back of the list.
 */
void push_back_doubly_linked_list(DoublyLinkedList* list, double value);

/**
 * Removes the node after the node passed from a linked list.
 */
void remove_next_node_doubly_linked_list(DoublyLinkedList* list, DoublyLinkedListNode* node);

/**
 * Returns a pointer to the first node (head) in the list.
 */
DoublyLinkedListNode* last_node_doubly_linked_list(DoublyLinkedList* list);

/**
 * Returns a pointer to the last node in the list.
 */
DoublyLinkedListNode* first_node_doubly_linked_list(DoublyLinkedList* list);

/**
 * Returns the current size of the linked list.
 */
unsigned int size_doubly_linked_list(DoublyLinkedList* list);

/**
 * Free's the entire doubly linked list.
 */
void free_doubly_linked_list(DoublyLinkedList* list);

#endif // C_BOOSTER_DOUBLY_LINKED_LIST_H_
