#include <check.h>
#include "circular_buffer.h"

START_TEST(test_init_circular_buffer)
{
  CircularBuffer buffer;

  int one = 1, two = 2, three = 3, four = 4, five = 5;

  init_circular_buffer(&buffer, 3, sizeof(int));

  write_circular_buffer(&buffer, &one);
  write_circular_buffer(&buffer, &two);
  write_circular_buffer(&buffer, &three);
  write_circular_buffer(&buffer, &four);
  write_circular_buffer(&buffer, &five);

  int* data_one = (int*)read_circular_buffer(&buffer);
  int* data_two = (int*)read_circular_buffer(&buffer);
}
END_TEST

Suite* create_circular_buffer_test_suite()
{
  Suite* suite = suite_create("CircularBuffer");
  TCase *test_case = tcase_create("CircularBuffer_DataStructure");

  // init_circular_buffer
  tcase_add_test(test_case, test_init_circular_buffer);

  suite_add_tcase(suite, test_case);

  return suite;
}
