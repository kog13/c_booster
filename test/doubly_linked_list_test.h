#include <check.h>
#include "doubly_linked_list.h"

START_TEST(test_doubly_linked_list)
{
  DoublyLinkedList doubly_linked_list;
  //init_doubly_linked_list(&doubly_linked_list, sizeof(int));

  ck_assert_int_eq(1, 1);
}
END_TEST

Suite* create_doubly_linked_list_test_suite()
{
  Suite* suite = suite_create("DoublyLinkedList");
  TCase *test_case = tcase_create("DoublyLinkedList_DataStructure");

  // ???
  tcase_add_test(test_case, test_doubly_linked_list);

  suite_add_tcase(suite, test_case);

  return suite;
}
