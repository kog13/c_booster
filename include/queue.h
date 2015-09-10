#ifndef C_BOOSTER_QUEUE_H_
#define C_BOOSTER_QUEUE_H_

#include "linked_list.h"

/*******************************************************************************
**                                    Queue
**----------------------------------------------------------------------------*/

/**
 * A Queue is implemented as a LinkedList.
 */
typedef LinkedList Queue;
typedef LinkedListNode QueueNode;

#define first_node_queue first_node_linked_list

#define init_queue init_linked_list

#define insert_next_queue insert_next_linked_list

#define last_node_queue last_node_linked_list

/**
 * Add data into the queue.
 */
QueueNode* enqueue_queue(Queue* queue, void* data);

/**
 * Remove data from the queue.
 */
void* dequeue_queue();

/**
 * Look at the value of the data at the top of the queue.
 */
void* peek_queue();

#define push_back_queue push_back_linked_list

#define remove_next_queue remove_next_linked_list

#define size_queue size_linked_list

#endif // C_BOOSTER_QUEUE_H_
