#ifndef C_BOOSTER_COMPARATOR_HELPER_H_
#define C_BOOSTER_COMPARATOR_HELPER_H_

/*******************************************************************************
**                           Comparator Helpers
**----------------------------------------------------------------------------*/

/**
 * Comparator for chars.
 */
int compare_char(void* left, void* right);

/**
 * Comparator for double.
 */
int compare_double(void* left, void* right);

/**
 * Comparator for floats.
 */
int compare_float(void* left, void* right);

/**
 * Comparator for integers.
 */
int compare_int(void* left, void* right);

#endif // C_BOOSTER_COMPARATOR_HELPER_H_
