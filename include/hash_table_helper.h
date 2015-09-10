#ifndef C_BOOSTER_HASH_TABLE_HELPER_H_
#define C_BOOSTER_HASH_TABLE_HELPER_H_

/*******************************************************************************
**                              Hash Table Helpers
**----------------------------------------------------------------------------*/

/**
 * Simple hashing function that works well for strings.
 *
 * hashpjw function by P.J. Weinberger.
 */
unsigned int hash_pjw(const void* key);

#endif // C_BOOSTER_HASH_TABLE_HELPER_H_
