#include <check.h>
#include "heap_helper.h"

START_TEST(test_heap_helper_get_heap_parent_index)
{
  size_t index = 10;

  size_t result = get_heap_parent_index(index);

  ck_assert_int_eq(result, 5);
}
END_TEST

START_TEST(test_heap_helper_get_heap_left_index)
{
  size_t index = 10;

  size_t result = get_heap_left_index(index);

  ck_assert_int_eq(result, 20);
}
END_TEST

START_TEST(test_heap_helper_get_heap_right_index)
{
  size_t index = 10;

  size_t result = get_heap_right_index(index);

  ck_assert_int_eq(result, 21);
}
END_TEST

Suite* create_heap_helper_test_suite()
{
  Suite* suite = suite_create("HeapHelper");
  TCase *test_case = tcase_create("HeapHelper");

  // get_heap_parent_index
  tcase_add_test(test_case, test_heap_helper_get_heap_parent_index);
  tcase_add_test(test_case, test_heap_helper_get_heap_parent_index);

  // get_heap_left_index
  tcase_add_test(test_case, test_heap_helper_get_heap_left_index);
  tcase_add_test(test_case, test_heap_helper_get_heap_left_index);

  // get_heap_right_index
  tcase_add_test(test_case, test_heap_helper_get_heap_right_index);
  tcase_add_test(test_case, test_heap_helper_get_heap_right_index);

  suite_add_tcase(suite, test_case);

  return suite;
}
