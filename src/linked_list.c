#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

LinkedList* init_linked_list(LinkedList* list, size_t element_size)
{
  list->head = NULL;
  list->element_size = element_size;
  list->size = 0;

  return list;
}

LinkedListNode* alloc_linked_list_node()
{
  LinkedListNode *node; 

  node = malloc(sizeof(LinkedListNode));

  if (node == NULL) {
    fputs("Not enough memory to allocate LinkedListNode.", stderr);
    exit(1);
  }

  node->next = NULL;
  node->value = NULL;

  return node;
}

LinkedListNode* first_node_linked_list(LinkedList* list)
{
  return list->head;
}

void free_linked_list(LinkedList* list, Reclaim reclaim)
{
  if (list->head != NULL) {
    LinkedListNode *current = list->head;
    LinkedListNode *next;

    while (current != NULL) {
      next = current->next;

/*
      if (reclaim != NULL) {
        reclaim(current->data); // free the node data.
      }
      */

      free(current); // free the node.
      current = next;
    }
  }

  free(list); // free the list.
}

LinkedListNode* insert_next_linked_list(
  LinkedList* list, 
  LinkedListNode* previous_node, 
  void* data
) {
  LinkedListNode* new_node = alloc_linked_list_node();
  new_node->value = malloc(sizeof(list->element_size));
  memcpy(new_node->value, data, list->element_size);

  if (previous_node == NULL) {
    if (list->head == NULL) {
      list->head = new_node;
    } else {
      LinkedListNode* previous_head = list->head;
      new_node->next = previous_head;

      list->head = new_node;
    }
  } else {
    new_node->next = previous_node->next;
    previous_node->next = new_node;
  }

  list->size++;
  return new_node;
}

LinkedListNode* last_node_linked_list(LinkedList* list)
{
  if (list->head == NULL) {
    return NULL;
  }

  LinkedListNode* current = list->head;

  while (current->next != NULL) {
    current = current->next;
  }

  return current;
}

LinkedListNode* push_back_linked_list(LinkedList* list, void* data)
{
  LinkedListNode* last_node = last_node_linked_list(list);

  return insert_next_linked_list(list, last_node, data);
}

void remove_next_linked_list(LinkedList* list, LinkedListNode* previous_node)
{
  if (previous_node == NULL) {
    if (list->head == NULL) {
      return;
    } else {
      LinkedListNode* previous_head = list->head;
      list->head = list->head->next;
      // TODO: relclaim previous head
    }
  } else {
    if (previous_node->next != NULL) {
      LinkedListNode* remove = previous_node->next; // TODO: reclaim
      previous_node->next = previous_node->next->next;
      // reclaim next
    } else {
      return;
    }
  }

  list->size--;
}

unsigned int size_linked_list(LinkedList* list)
{
  return list->size;
}
