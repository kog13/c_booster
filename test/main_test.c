#include "bit_helper_test.h"
#include "heap_helper_test.h"
#include "chained_hash_table_test.h"
#include "circular_buffer_test.h"
#include "doubly_linked_list_test.h"
#include "linked_list_test.h"
#include "queue_test.h"
#include "sort_test.h"
#include "stack_test.h"

int run_test_suite(Suite* test_suite)
{
  SRunner* runner = srunner_create(test_suite);

  int failed;
  srunner_run_all(runner, CK_ENV);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}

int main(void)
{
  // data structures
  int linked_list_failed = run_test_suite(create_linked_list_test_suite());
  int chained_hash_table_failed = run_test_suite(create_chained_hash_table_test_suite());
  int stack_failed = run_test_suite(create_stack_test_suite());
  int queue_failed = run_test_suite(create_queue_test_suite());
  int circular_buffer_failed = run_test_suite(create_circular_buffer_test_suite());
  int doubly_linked_list_failed = run_test_suite(create_doubly_linked_list_test_suite());

  // algorithms
  int sort_failed = run_test_suite(create_sort_test_suite());

  // helpers
  int bit_helper_failed = run_test_suite(create_bit_helper_test_suite());
  int heap_helper_failed = run_test_suite(create_heap_helper_test_suite());

  int failed = 
    linked_list_failed + 
    heap_helper_failed + 
    chained_hash_table_failed + 
    circular_buffer_failed + 
    stack_failed +
    queue_failed +
    doubly_linked_list_failed +
    sort_failed +
    bit_helper_failed;

  return failed == 0 ? 0 : 1;
}
