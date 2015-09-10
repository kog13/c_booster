#include <string.h>

void swap(void* left, void* right, size_t size)
{
  char temp[size];

  memcpy(temp, right, size);
  memcpy(right, left, size);
  memcpy(left, temp, size);
}
