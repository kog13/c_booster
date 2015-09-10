#include "string_helper.h"
#include "string.h"

/*
int are_permutation(char* string_one, char* string_two)
{
  sort_string(string_one);
  sort_string(string_two);

  int compare = strcmp(string_one, string_two);

  return compare == 0;
}

void sort_string(char* string)
{
  char* forward = string;

  while (forward != '\0') {
    backward = forward;

    while (backward != string && *backward < *(backward - 1)) {
      char tmp = *backward;
      *backward = *(backward--);
      *(backward--) = tmp;
      backward--;
    }

    forward++;
  }
}
*/
