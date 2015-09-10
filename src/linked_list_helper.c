#include <stddef.h>
#include <stdio.h>
#include "linked_list_helper.h"

void remove_duplicated_linked_list(LinkedList* list)
{
  LinkedListNode* current = list->head;
  LinkedListNode* previous = list->head;
  LinkedListNode* current_check = list->head;

  while (current_check != NULL) {
    if (current_check->value == current->value) {
      remove_next_linked_list(list, previous);
    }

    previous = current_check;
    current_check = current->next;
  }
}

void for_each_linked_list(LinkedList* list, Iterator iterator)
{
  LinkedListNode* current = list->head;

  while (current != NULL) {
    iterator(current->value);
    current = current->next;
  }
}
