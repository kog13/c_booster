#include <check.h>
#include "stack.h"

START_TEST(test_push_stack_single_push)
{
  Stack stack;
  init_stack(&stack, sizeof(int));

  int element = 6;

  push_stack(&stack, &element);
  int* result = (int*) peek_stack(&stack);

  ck_assert_int_eq(*result, element);
}
END_TEST

START_TEST(test_push_stack_multiple_pushes)
{
  Stack stack;
  init_stack(&stack, sizeof(int));

  int element_one = 5;
  int element_two = 10;

  push_stack(&stack, &element_one);
  push_stack(&stack, &element_two);

  int* pop_one = (int*) pop_stack(&stack);
  int* pop_two = (int*) pop_stack(&stack);

  // LIFO ordering.
  ck_assert_int_eq(*pop_one, element_two);
  ck_assert_int_eq(*pop_two, element_one);
}
END_TEST

Suite* create_stack_test_suite()
{
  Suite* suite = suite_create("Stack");
  TCase *test_case = tcase_create("Stack_DataStucture");

  // push_stack
  tcase_add_test(test_case, test_push_stack_single_push);
  tcase_add_test(test_case, test_push_stack_multiple_pushes);

  suite_add_tcase(suite, test_case);

  return suite;
}
