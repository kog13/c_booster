#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular_buffer.h"

void _advance(CircularBuffer* buffer, size_t* location)
{
  *location = (*location + buffer->size) % (buffer->elements * buffer->size);
}

void init_circular_buffer(CircularBuffer* buffer, size_t elements, size_t size)
{
  void* data = malloc((elements * size) + size);

  if (data == NULL) {
    fputs("Not enough memory to allocate table for hash_table.", stderr);
    exit(1);
  }

  buffer->data = data;
  buffer->elements = elements;
  buffer->size = size;
  buffer->head = 0;
  buffer->tail = 0;
}

void write_circular_buffer(CircularBuffer* buffer, void* data)
{
  memcpy(buffer->data + buffer->head, data, buffer->size);

  _advance(buffer, &buffer->head);
}

void* read_circular_buffer(CircularBuffer* buffer)
{
  void* data = (buffer->data + buffer->tail);

  _advance(buffer, &buffer->tail);

  return data;
}
