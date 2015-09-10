#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include <stddef.h>

typedef struct
{
  void* data;      // holds buffered data.
  size_t elements; // number of elements in the buffer.
  size_t size;     // size of each element in the buffer.
  size_t head;     // the header, where writes append.
  size_t tail;     // the tail, where reads pull.
} CircularBuffer;

/**
 * Initializes a circular buffer.
 */
void init_circular_buffer(CircularBuffer* buffer, size_t elements, size_t size);

/**
 * Writes to the buffer.
 */
void write_circular_buffer(CircularBuffer* buffer, void* data);

/**
 * Reads from the buffer.
 */
void* read_circular_buffer(CircularBuffer* buffer);

/**
 * Returns if the buffer is full or not.
 *
 * Returns 1 if the buffer is full.
 * Returns 0 if the buffer is not full.
 */
int is_full_circular_buffer(CircularBuffer* buffer);

/**
 * Returns if the buffer is empty or not.
 *
 * Returns 1 if the buffer is empty.
 * Returns 0 if the buffer is not empty.
 */
int is_empty_circular_buffer(CircularBuffer* buffer);

#endif // CIRCULAR_BUFFER_H_
