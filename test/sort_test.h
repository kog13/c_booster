#include <check.h>
#include "sort.h"
#include "comparator_helper.h"

START_TEST(test_sort_generic_binary_search_less)
{
  int data[] = {3, 10, 33, 55, 98, 100};
  int search = 10;

  int found = generic_binary_search(&data, &search, 6, sizeof(int), compare_int);

  ck_assert_int_eq(found, 1);
}
END_TEST

START_TEST(test_sort_generic_binary_search_greater)
{
  int data[] = {3, 10, 33, 55, 98, 100};
  int search = 98;

  int found = generic_binary_search(&data, &search, 6, sizeof(int), compare_int);

  ck_assert_int_eq(found, 1);
}
END_TEST

START_TEST(test_sort_generic_binary_search_middle)
{
  int data[] = {3, 10, 33, 55, 98, 100};
  int search = 55;

  int found = generic_binary_search(&data, &search, 6, sizeof(int), compare_int);

  ck_assert_int_eq(found, 1);
}
END_TEST

START_TEST(test_sort_generic_binary_search_below)
{
  int data[] = {3, 10, 33, 55, 98, 100};
  int search = 2;

  int found = generic_binary_search(&data, &search, 6, sizeof(int), compare_int);

  ck_assert_int_eq(found, 0);
}
END_TEST

START_TEST(test_sort_generic_binary_search_above)
{
  int data[] = {3, 10, 33, 55, 98, 100};
  int search = 202;

  int found = generic_binary_search(&data, &search, 6, sizeof(int), compare_int);

  ck_assert_int_eq(found, 0);
}
END_TEST

START_TEST(test_sort_generic_binary_search_odd)
{
  int data[] = {3, 10, 33, 55, 98};
  int search = 98;

  int found = generic_binary_search(&data, &search, 6, sizeof(int), compare_int);

  ck_assert_int_eq(found, 1);
}
END_TEST

START_TEST(test_sort_generic_binary_search_even)
{
  int data[] = {3, 10, 33, 55, 98, 100};
  int search = 98;

  int found = generic_binary_search(&data, &search, 6, sizeof(int), compare_int);

  ck_assert_int_eq(found, 1);
}
END_TEST

START_TEST(test_sort_generic_binary_search_bad_comparator)
{
  // TODO:
}
END_TEST

START_TEST(test_sort_generic_bubble_sort)
{
  int data[] = {10, 33, 2, 101, 5, 33};

  generic_bubble_sort(&data, 6, sizeof(int), compare_int);

  ck_assert_int_eq(data[0], 2);
  ck_assert_int_eq(data[1], 5);
  ck_assert_int_eq(data[2], 10);
  ck_assert_int_eq(data[3], 33);
  ck_assert_int_eq(data[4], 33);
  ck_assert_int_eq(data[5], 101);
}
END_TEST

START_TEST(test_sort_generic_insertion_sort)
{
  int data[] = {10, 33, 2, 101, 5, 33};

  generic_insertion_sort(&data, 6, sizeof(int), compare_int);

  ck_assert_int_eq(data[0], 2);
  ck_assert_int_eq(data[1], 5);
  ck_assert_int_eq(data[2], 10);
  ck_assert_int_eq(data[3], 33);
  ck_assert_int_eq(data[4], 33);
  ck_assert_int_eq(data[5], 101);
}
END_TEST

START_TEST(test_sort_generic_selection_sort)
{
  int data[] = {10, 33, 2, 101, 5, 33};

  generic_insertion_sort(&data, 6, sizeof(int), compare_int);

  ck_assert_int_eq(data[0], 2);
  ck_assert_int_eq(data[1], 5);
  ck_assert_int_eq(data[2], 10);
  ck_assert_int_eq(data[3], 33);
  ck_assert_int_eq(data[4], 33);
  ck_assert_int_eq(data[5], 101);
}
END_TEST

Suite* create_sort_test_suite()
{
  Suite* suite = suite_create("sort");
  TCase *test_case = tcase_create("sort");

  // generic_binary_search
  tcase_add_test(test_case, test_sort_generic_binary_search_less);
  tcase_add_test(test_case, test_sort_generic_binary_search_greater);
  tcase_add_test(test_case, test_sort_generic_binary_search_middle);
  tcase_add_test(test_case, test_sort_generic_binary_search_below);
  tcase_add_test(test_case, test_sort_generic_binary_search_above);
  tcase_add_test(test_case, test_sort_generic_binary_search_odd);
  tcase_add_test(test_case, test_sort_generic_binary_search_even);

  // generic_bubble_sort
  tcase_add_test(test_case, test_sort_generic_bubble_sort);

  // generic_insertion_sort
  tcase_add_test(test_case, test_sort_generic_insertion_sort);

  // generic_selection_sort
  tcase_add_test(test_case, test_sort_generic_selection_sort);

  suite_add_tcase(suite, test_case);

  return suite;
}
