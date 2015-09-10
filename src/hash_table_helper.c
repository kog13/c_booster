#include "hash_table_helper.h"

// hashpjw function by P.J. Weinberger.
unsigned int hash_pjw(const void* key) 
{
  const char *ptr = key;
  unsigned int val = 0;

  while (*ptr != '\0') {
    unsigned int tmp;

    val = (val << 4) + (*ptr);
    tmp = (val & 0xf0000000);

    if (tmp) {
      val = val ^ (tmp >> 24);
      val = val ^ tmp;
    }

    ptr++;
  }

  return val;
}
