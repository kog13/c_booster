#include <check.h>
#include <stdio.h>
#include "chained_hash_table.h"
#include "hash_table_helper.h"

START_TEST(test_init_chained_hash_table_defaults_size_to_0)
{
  ChainedHashTable hash_table;
  init_chained_hash_table(&hash_table, sizeof(int), 2, hash_pjw);

  ck_assert_int_eq(hash_table.size, 0);
}
END_TEST

START_TEST(test_init_chained_hash_table_sets_element_size_to_passed_value)
{
  ChainedHashTable hash_table;
  init_chained_hash_table(&hash_table, sizeof(double), 2, hash_pjw);

  ck_assert_int_eq(hash_table.element_size, sizeof(double));
}
END_TEST

START_TEST(test_init_chained_hash_table_sets_buckets_to_passed_value)
{
  unsigned int buckets = 7;
  ChainedHashTable hash_table;
  init_chained_hash_table(&hash_table, sizeof(int), buckets, hash_pjw);

  ck_assert_int_eq(hash_table.buckets, buckets);
}
END_TEST

START_TEST(test_init_chained_hash_table_sets_hash_to_passed_function)
{
  ChainedHashTable hash_table;
  init_chained_hash_table(&hash_table, sizeof(int), 2, hash_pjw);

  ck_assert_ptr_eq(hash_table.hash, hash_pjw);
}
END_TEST

START_TEST(test_init_chained_hash_table_inits_the_table)
{
  ChainedHashTable hash_table;
  init_chained_hash_table(&hash_table, sizeof(int), 2, hash_pjw);

  ck_assert_ptr_eq(hash_table.hash, hash_pjw);
}
END_TEST

START_TEST(test_insert_chained_hash_table_increments_size)
{
  ChainedHashTable hash_table;
  init_chained_hash_table(&hash_table, sizeof(int), 2, hash_pjw);

  int element_one = 5;
  int element_two = 10;

  insert_chained_hash_table(&hash_table, &element_one);
  insert_chained_hash_table(&hash_table, &element_two);
  unsigned int size = size_chained_hash_table(&hash_table);

  ck_assert_int_eq(size, 2);
}
END_TEST

START_TEST(test_size_chained_hash_table_returns_element_count)
{
  ChainedHashTable hash_table;
  init_chained_hash_table(&hash_table, sizeof(int), 2, hash_pjw);

  int data = 3;

  //insert_chained_hash_table(&hash_table, );

  ck_assert_ptr_eq(hash_table.hash, hash_pjw);
}
END_TEST

Suite* create_chained_hash_table_test_suite()
{
  Suite* suite = suite_create("ChainedHashTable");
  TCase *test_case = tcase_create("ChainedHashTable_DataStructure");

  // init_chained_hash_table
  tcase_add_test(test_case, test_init_chained_hash_table_defaults_size_to_0);
  tcase_add_test(test_case, test_init_chained_hash_table_sets_element_size_to_passed_value);
  tcase_add_test(test_case, test_init_chained_hash_table_sets_buckets_to_passed_value);
  tcase_add_test(test_case, test_init_chained_hash_table_sets_hash_to_passed_function);
  tcase_add_test(test_case, test_init_chained_hash_table_inits_the_table);
  // insert_chained_hash_table
  tcase_add_test(test_case, test_insert_chained_hash_table_increments_size);

  // size_chained_hash_table
  tcase_add_test(test_case, test_size_chained_hash_table_returns_element_count);

  suite_add_tcase(suite, test_case);

  return suite;
}
