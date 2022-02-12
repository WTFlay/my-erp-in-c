#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include "../account/account.h"

typedef struct Customer {
  char *name;
  Account *account;
} Customer;

#endif
