#ifndef C_BOOSTER_BIT_HELPER_H_
#define C_BOOSTER_BIT_HELPER_H_

#include <stddef.h>

/*******************************************************************************
**                                Bit Helper
**----------------------------------------------------------------------------*/

/**
 * Returns the ith bit.
 */
unsigned int get_bit(void* data, size_t index);

/**
 * Sets the ith bit.
 */
void set_bit(void* data, size_t index);

/**
 * Clears the ith bit.
 */
void clear_bit(void* data, size_t index);

#endif // C_BOOSTER_BIT_HELPER_H_
