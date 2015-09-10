#include "bit_helper.h"

unsigned int get_bit(void* data, size_t index)
{
  unsigned int mask = (1 << index);

  return (*((char*)data) & mask) >= 1;
}

void set_bit(void* data, size_t index)
{
  unsigned int mask = (1 << index);

  *(char*)data |= mask;
}

void clear_bit(void* data, size_t index)
{
  unsigned int mask = ~(1 << index);

  *(char*)data &= mask;
}
