#include "heap_helper.h"

size_t get_heap_parent_index(size_t index)
{
  return index >> 1;
}

size_t get_heap_left_index(size_t index)
{
  return index << 1;
}

size_t get_heap_right_index(size_t index)
{
  return (index << 1) + 1;
}
