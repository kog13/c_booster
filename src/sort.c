#include "sort.h"
#include "swap.h"
#include "string.h"

int generic_binary_search(
  void* data,
  void* search,
  size_t elements,
  size_t size,
  Comparator compare
) {
  int left = 0, right = (elements - 1);

  while (left <= right) {
    int index = ((right + left) / 2);

    switch(compare((data + (index * size)), search)) {
      case 0:
        return 1; // item found.
      case -1:
        left = index + 1;
        break;
      case 1:
        right = index - 1;
        break;
      default:
        return -1; // error with comparator return value.
    }
  }

  return 0; // not found.
}

int generic_bubble_sort(
  void* data, 
  size_t elements, 
  size_t size,
  Comparator compare
) {
  int swaps = 1;

  while (swaps) {
    swaps = 0;

    for (size_t index = size; index < size * elements; index += size) {
      switch(compare(data + index, data + (index - size))) {
        case 0:
        case 1:
          break;
        case -1:
          swap(data + index, data + (index - size), size);
          swaps = 1;
          break;
        default:
          return -1; // error with comparator return value.
      }
    }
  }

  return 1;
}

void generic_insertion_sort(
  void* data, 
  size_t elements, 
  size_t size,
  Comparator compare
) {
  size_t forward, backward;

  for (forward = size; forward < (size * elements); forward += size) {
    backward = forward;

    while (backward != 0 && 
      compare(data + backward, data + (backward - size)) == -1
    ) {
      swap(data + backward, data + (backward - size), size);
      backward -= size;
    }
  }
}

int generic_selection_sort(
  void* data, 
  size_t elements, 
  size_t size,
  Comparator compare
) {
  for (size_t low = 0; low < (elements * size); low += size) {
    size_t min = low;

    for (size_t index = (low + size); index < (elements * size); index += size) {
      switch (compare(data + index, data + min)) {
        case -1:
          min = index;
          break;
        case 0:
        case 1:
          break;
        default:
          return -1;
      }
    }

    swap(data + low, data + min, size); // push the min value to the bottom.
  }
  
  return 1;
}

/*
void* _quick_sort_median(void* data, Median, median)
{
  return median_value;
}

void _quick_sort_partition(void* data, size_t low, size_t high)
{
  int partition_value = _quick_sort_median(data);
  int middle = ((high + low) / 2);
  int i = low, j = high;

  while (i <= j) {
    while (low <= middle && compare(low, partition_value) =< 0) {
      i++;
    }
    while (high >= middle && compare(high, partition_value), >= 0) {
      j--;
    }

    swap(i, j);
  }
}

void generic_quick_sort(
  void* data, 
  size_t elements, 
  size_t size,
  Comparator compare,
  Median median
) {
  int middle = ((elements - 1) / 2);

  _quick_sort_partition(data, 0, elements);

  _quick_sort_partition(data, middle + 1, elements)
}
*/
