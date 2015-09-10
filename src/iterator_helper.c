#include "stdio.h"

void print_integers_iterator(void* data)
{
  printf("%d\n", *((int*) data));
}

void print_floats_iterator(void* data)
{
  printf("%f\n", *((float*) data));
}

void print_doubles_iterator(void* data)
{
  printf("%f\n", *((double*) data));
}

void print_strings_iterator(void* data)
{
  printf("%c\n", *((char*) data));
}
