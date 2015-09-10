#include <check.h>
#include <stdio.h>
#include "linked_list.h"

START_TEST(test_init_linked_list_defaults_size_to_0)
{
  LinkedList list;
  init_linked_list(&list, sizeof(int));

  ck_assert_int_eq(list.size, 0);
}
END_TEST

START_TEST(test_init_linked_list_defaults_head_to_null)
{
  LinkedList list;
  init_linked_list(&list, sizeof(int));

  ck_assert_ptr_eq(list.head, NULL);
}
END_TEST

START_TEST(test_init_linked_list_sets_element_size_to_passed_size)
{
  LinkedList list;
  init_linked_list(&list, sizeof(double));

  ck_assert_int_eq(list.element_size, sizeof(double));
}
END_TEST

START_TEST(test_push_back_linked_list_increments_size)
{
  LinkedList list;
  init_linked_list(&list, sizeof(int));

  int element_one = 5;
  int element_two = 10;

  push_back_linked_list(&list, &element_one);
  push_back_linked_list(&list, &element_two);
  unsigned int size = size_linked_list(&list);

  ck_assert_int_eq(size, 2);
}
END_TEST

START_TEST(test_push_back_linked_list_adds_elements_in_correct_order)
{
  LinkedList list;
  init_linked_list(&list, sizeof(int));

  int element_one = 5;
  int element_two = 10;

  push_back_linked_list(&list, &element_one);
  push_back_linked_list(&list, &element_two);

  ck_assert_int_eq(*(int*)list.head->value, 5);
  ck_assert_int_eq(*(int*)list.head->next->value, 10);
}
END_TEST

START_TEST(test_push_back_linked_list_when_empty_adds_to_head)
{
  LinkedList list;
  init_linked_list(&list, sizeof(int));

  int element_one = 5;

  push_back_linked_list(&list, &element_one);

  ck_assert_int_eq(*(int*)list.head->value, 5);
}
END_TEST

START_TEST(test_remove_next_linked_list_decrements_size)
{
  LinkedList list;
  init_linked_list(&list, sizeof(int));

  int element_one = 5;
  int element_two = 10; // should be removed.
  int element_three = 15;

  push_back_linked_list(&list, &element_one);
  push_back_linked_list(&list, &element_two);
  push_back_linked_list(&list, &element_three);

  remove_next_linked_list(&list, list.head);
  unsigned int size = size_linked_list(&list);

  ck_assert_int_eq(size, 2);
}
END_TEST

START_TEST(test_remove_next_linked_list_removes_correct_element)
{
  LinkedList list;
  init_linked_list(&list, sizeof(int));

  int element_one = 5;
  int element_two = 10; // should be removed.
  int element_three = 15;

  push_back_linked_list(&list, &element_one);
  push_back_linked_list(&list, &element_two);
  push_back_linked_list(&list, &element_three);

  remove_next_linked_list(&list, list.head);
  unsigned int size = size_linked_list(&list);

  ck_assert_int_eq(*(int*)list.head->value, 5);
  ck_assert_int_eq(*(int*)list.head->next->value, 15);
}
END_TEST

START_TEST(test_remove_next_linked_list_when_null_node_passed)
{
  LinkedList list;
  init_linked_list(&list, sizeof(int));

  // [0]->[1]->[2]->[3]
  for (int i = 0; i < 4; i++) {
    push_back_linked_list(&list, &i);
  }

  remove_next_linked_list(&list, NULL);
  ck_assert_int_eq(*(int*)list.head->value, 1);

  remove_next_linked_list(&list, NULL);
  ck_assert_int_eq(*(int*)list.head->value, 2);
}
END_TEST

START_TEST(test_insert_next_linked_list_when_empty_list)
{
  LinkedList list;
  init_linked_list(&list, sizeof(int));

  int element_one = 5;

  insert_next_linked_list(&list, NULL, &element_one); // [5]

  ck_assert_int_eq(*(int*)list.head->value, 5);
}
END_TEST

START_TEST(test_insert_next_linked_list_when_null_node)
{
  LinkedList list;
  init_linked_list(&list, sizeof(int));

  int element_one = 5;
  int element_two = 10;

  insert_next_linked_list(&list, NULL, &element_one); // [5]
  insert_next_linked_list(&list, NULL, &element_two); // [10, 5]

  LinkedListNode* last_node = last_node_linked_list(&list);

  ck_assert_int_eq(*(int*)list.head->value, 10);
  ck_assert_int_eq(*(int*)last_node->value, 5);
}
END_TEST

START_TEST(test_insert_next_linked_list_no_node_repeat)
{
  LinkedList list;
  init_linked_list(&list, sizeof(int));

  for (int i = 0; i < 4; i++) {
    insert_next_linked_list(&list, NULL, &i);
  }

  ck_assert_int_eq(*(int*)list.head->value, 3);
  ck_assert_int_eq(*(int*)list.head->next->value, 2);
  ck_assert_int_eq(*(int*)list.head->next->next->value, 1);
  ck_assert_int_eq(*(int*)list.head->next->next->next->value, 0);
}
END_TEST

START_TEST(test_insert_next_linked_list_with_passed_node)
{
  LinkedList list;
  init_linked_list(&list, sizeof(int));

  int element_one = 5;
  int element_two = 10;

  insert_next_linked_list(&list, NULL, &element_one); // [5]
  insert_next_linked_list(&list, list.head, &element_two); // [5, 10]

  LinkedListNode* last_node = last_node_linked_list(&list);

  ck_assert_int_eq(*(int*)list.head->value, 5);
  ck_assert_int_eq(*(int*)last_node->value, 10);
}
END_TEST

START_TEST(test_insert_next_linked_list_increments_size)
{
  LinkedList list;
  init_linked_list(&list, sizeof(int));

  int element_one = 5;
  int element_two = 10;

  insert_next_linked_list(&list, NULL, &element_one); // [5]
  insert_next_linked_list(&list, list.head, &element_two); // [5, 10]

  unsigned int size = size_linked_list(&list);

  ck_assert_int_eq(size, 2);
}
END_TEST

START_TEST(test_last_node_linked_list_returns_last_node)
{
  LinkedList list;
  init_linked_list(&list, sizeof(int));

  int element_one = 5;
  int element_two = 10;
  int element_three = 15;

  push_back_linked_list(&list, &element_one);
  push_back_linked_list(&list, &element_two);
  LinkedListNode* last_push = push_back_linked_list(&list, &element_three);

  LinkedListNode* last_node = last_node_linked_list(&list);

  ck_assert_ptr_eq(last_push, last_node);
}
END_TEST

START_TEST(test_last_node_linked_list_when_empty_returns_null)
{
  LinkedList list;
  init_linked_list(&list, sizeof(int));

  LinkedListNode* last_node = last_node_linked_list(&list);

  ck_assert_ptr_eq(NULL, last_node);
}
END_TEST

START_TEST(test_first_node_linked_list_returns_head)
{
  LinkedList list;
  init_linked_list(&list, sizeof(int));

  int element_one = 5;
  int element_two = 10;
  int element_three = 15;

  push_back_linked_list(&list, &element_one);
  push_back_linked_list(&list, &element_two);
  push_back_linked_list(&list, &element_three);

  LinkedListNode* first_node = first_node_linked_list(&list);

  ck_assert_ptr_eq(list.head, first_node);
}
END_TEST

Suite* create_linked_list_test_suite()
{
  Suite* suite = suite_create("LinkedList");
  TCase *test_case = tcase_create("LinkedList_DataStructure");

  // init_linked_list
  tcase_add_test(test_case, test_init_linked_list_defaults_size_to_0);
  tcase_add_test(test_case, test_init_linked_list_defaults_head_to_null);
  tcase_add_test(test_case, test_init_linked_list_sets_element_size_to_passed_size);

  // push_back_linked_list
  tcase_add_test(test_case, test_push_back_linked_list_increments_size);
  tcase_add_test(test_case, test_push_back_linked_list_adds_elements_in_correct_order);
  tcase_add_test(test_case, test_push_back_linked_list_when_empty_adds_to_head);

  // remove_next_linked_list
  tcase_add_test(test_case, test_remove_next_linked_list_decrements_size);
  tcase_add_test(test_case, test_remove_next_linked_list_removes_correct_element);
  tcase_add_test(test_case, test_remove_next_linked_list_when_null_node_passed);

  // insert_next_linked_list
  tcase_add_test(test_case, test_insert_next_linked_list_when_empty_list);
  tcase_add_test(test_case, test_insert_next_linked_list_when_null_node);
  tcase_add_test(test_case, test_insert_next_linked_list_with_passed_node);
  tcase_add_test(test_case, test_insert_next_linked_list_no_node_repeat);
  tcase_add_test(test_case, test_insert_next_linked_list_increments_size);

  // last_node_linked_list
  tcase_add_test(test_case, test_last_node_linked_list_returns_last_node);
  tcase_add_test(test_case, test_last_node_linked_list_when_empty_returns_null);

  // first_node_linked_list
  tcase_add_test(test_case, test_first_node_linked_list_returns_head);

  suite_add_tcase(suite, test_case);

  return suite;
}
