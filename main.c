#include <stdio.h>
#include <string.h>
#include "c_booster.h"
#include "sort.h"
#include "comparator_helper.h"

void print_queue()
{
  Queue queue;

  init_queue(&queue, sizeof(int));

  for (int i = 0; i < 10; i++) {
    enqueue_queue(&queue, &i);
  }

  printf("Printing Queue:\n");
  for (int i = 0; i < 10; i++) {
    int* data = dequeue_queue(&queue);
    printf("%d\n", *data);
  }
}

void print_stack()
{
  Stack stack;

  init_stack(&stack, sizeof(int));

  for (int i = 0; i < 10; i++) {
    push_stack(&stack, &i);
  }

  printf("Printing Stack:\n");
  for (int i = 0; i < 10; i++) {
    int* data = pop_stack(&stack);
    printf("%d\n", *data);
  }
}

void print_linked_list()
{
  LinkedList list;

  init_linked_list(&list, sizeof(int));

  for (int i = 0; i < 10; i++) {
    insert_next_linked_list(&list, NULL, &i);
  }

  printf("Printing LinkedList:\n");
  for_each_linked_list(&list, print_integers_iterator);
}

void print_string(char* string)
{
  while (*string != '\0') {
    printf("%c", *string);
    string++;
  }
}

void sort_string(char string[])
{
  char* forward = (string + 1);
  char* backward;

  while (*forward != '\0') {
    backward = forward;

    while (backward != (string - 1) && *backward < *(backward - 1)) {
      char temp = *backward;
      *backward = *(backward - 1);
      *(backward - 1) = temp;

      backward--;
    }
    
    forward++;
  }
}

int main(int argc, char* argv[])
{
  int data[] = {10, 33, 2, 101, 5, 33};

  generic_insertion_sort(&data, 6, sizeof(int), compare_int);

  for (int i = 0; i < 6; i++) {
    printf("%d\n", data[i]);
  }

  //print_queue();
  //print_stack();
  //print_linked_list();

  return 0;
}
