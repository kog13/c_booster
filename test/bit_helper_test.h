#include <check.h>
#include "bit_helper.h"

START_TEST(test_bit_helper_get_bit_on)
{
  unsigned int data = 8; // 00001000
  size_t index = 3;

  unsigned int bit = get_bit(&data, index);

  ck_assert_int_eq(bit, 1);
}
END_TEST

START_TEST(test_bit_helper_get_bit_off)
{
  unsigned int data = 8; // 00001000
  size_t index = 4;

  unsigned int bit = get_bit(&data, index);

  ck_assert_int_eq(bit, 0);
}
END_TEST

START_TEST(test_bit_helper_set_bit_was_off)
{
  unsigned int data = 8; // 00001000
  size_t index = 2;

  set_bit(&data, index);

  ck_assert_int_eq(data, 12);
}
END_TEST

START_TEST(test_bit_helper_set_bit_was_on)
{
  unsigned int data = 8; // 00001000
  size_t index = 3;

  set_bit(&data, index);

  ck_assert_int_eq(data, 8);
}
END_TEST

START_TEST(test_bit_helper_clear_bit_was_off)
{
  unsigned int data = 8; // 00001000
  size_t index = 2;

  clear_bit(&data, index);

  ck_assert_int_eq(data, 8);
}
END_TEST

START_TEST(test_bit_helper_clear_bit_was_on)
{
  unsigned int data = 12; // 00001100
  size_t index = 3;

  clear_bit(&data, index);

  ck_assert_int_eq(data, 4);
}
END_TEST

Suite* create_bit_helper_test_suite()
{
  Suite* suite = suite_create("BitHelper");
  TCase *test_case = tcase_create("BitHelper");

  // get_bit
  tcase_add_test(test_case, test_bit_helper_get_bit_on);
  tcase_add_test(test_case, test_bit_helper_get_bit_off);

  // set_bit
  tcase_add_test(test_case, test_bit_helper_set_bit_was_off);
  tcase_add_test(test_case, test_bit_helper_set_bit_was_on);

  // clear_bit
  tcase_add_test(test_case, test_bit_helper_clear_bit_was_off);
  tcase_add_test(test_case, test_bit_helper_clear_bit_was_on);

  suite_add_tcase(suite, test_case);

  return suite;
}
