#ifndef C_BOOSTER_STACK_H_
#define C_BOOSTER_STACK_H_

#include "linked_list.h"

/*******************************************************************************
**                                    Stack
**----------------------------------------------------------------------------*/

/**
 * A Stack is implemented as a LinkedList.
 */
typedef LinkedList Stack;
typedef LinkedListNode StackNode;

#define first_node_stack first_node_linked_list

#define init_stack init_linked_list

#define insert_next_stack insert_next_linked_list

#define last_node_stack last_node_linked_list

/**
 * Look at the value of the data on the top of the stack.
 */
void* peek_stack(Stack* stack);

/**
 * Pop data off of the stack.
 */
void* pop_stack(Stack* stack);

/**
 * Push data onto the top of the stack.
 */
StackNode* push_stack(Stack* stack, void* data);

#define remove_next_stack remove_next_linked_list

#define size_stack size_linked_list

#endif // C_BOOSTER_STACK_H_
