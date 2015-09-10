#include <check.h>
#include "queue.h"

START_TEST(test_enqueue_queue_increments_size)
{
  Queue queue;
  init_queue(&queue, sizeof(int));

  int element_one = 5;
  int element_two = 10;

  enqueue_queue(&queue, &element_one);
  enqueue_queue(&queue, &element_two);

  unsigned int size = size_queue(&queue);

  ck_assert_int_eq(size, 2);
}
END_TEST

START_TEST(test_dequeue_queue_decrements_size)
{
  Queue queue;
  init_queue(&queue, sizeof(int));

  int element_one = 5;
  int element_two = 10;

  enqueue_queue(&queue, &element_one);
  enqueue_queue(&queue, &element_two);
  dequeue_queue(&queue);

  unsigned int size = size_queue(&queue);

  ck_assert_int_eq(size, 1);
}
END_TEST

START_TEST(test_dequeue_queue_returns_correct_value)
{
  Queue queue;
  init_queue(&queue, sizeof(int));

  int element_one = 5;
  int element_two = 10;

  enqueue_queue(&queue, &element_one);
  enqueue_queue(&queue, &element_two);

  int* dequeue_one = (int*) dequeue_queue(&queue);
  int* dequeue_two = (int*) dequeue_queue(&queue);

  // FIFO ordering.
  ck_assert_int_eq(*dequeue_one, 5);
  ck_assert_int_eq(*dequeue_two, 10);
}
END_TEST

START_TEST(test_peek_queue_returns_first_enqueued_value)
{
  Queue queue;
  init_queue(&queue, sizeof(int));

  int element_one = 5;
  int element_two = 10;

  enqueue_queue(&queue, &element_one);
  enqueue_queue(&queue, &element_two);

  int* value = (int*) peek_queue(&queue);

  ck_assert_int_eq(*value, 5);
}
END_TEST

START_TEST(test_peek_queue_does_not_change_size)
{
  Queue queue;
  init_queue(&queue, sizeof(int));

  int element_one = 5;
  int element_two = 10;

  enqueue_queue(&queue, &element_one);
  enqueue_queue(&queue, &element_two);

  peek_queue(&queue);
  peek_queue(&queue);

  unsigned int size = size_queue(&queue);

  ck_assert_int_eq(size, 2);
}
END_TEST

Suite* create_queue_test_suite()
{
  Suite* suite = suite_create("Queue");
  TCase *test_case = tcase_create("Queue_DataStucture");

  // enqueue_queue
  tcase_add_test(test_case, test_enqueue_queue_increments_size);

  // dequeue_queue
  tcase_add_test(test_case, test_dequeue_queue_decrements_size);
  tcase_add_test(test_case, test_dequeue_queue_returns_correct_value);

  // peek_queue
  tcase_add_test(test_case, test_peek_queue_returns_first_enqueued_value);
  tcase_add_test(test_case, test_peek_queue_does_not_change_size);

  suite_add_tcase(suite, test_case);

  return suite;
}
