#include "stack.h"

StackNode* push_stack(Stack* stack, void* data)
{
  return insert_next_stack(stack, NULL, data);
}

void* pop_stack(Stack* stack)
{
  void* data = first_node_stack(stack)->value;

  remove_next_stack(stack, NULL);

  return data;
}

void* peek_stack(Stack* stack)
{
  return first_node_stack(stack)->value;
}
