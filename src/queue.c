#include "queue.h"

QueueNode* enqueue_queue(Queue* queue, void* data)
{
  return push_back_queue(queue, data);
}

void* dequeue_queue(Queue* queue)
{
  void* value = queue->head->value;

  remove_next_queue(queue, NULL);

  return value;
}

void* peek_queue(Queue* queue)
{
  QueueNode* head = first_node_queue(queue);

  return head->value;
}
