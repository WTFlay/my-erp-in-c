#ifndef _TAX_H_
#define _TAX_H_

#include "../account/account.h"

typedef struct Tax {
  double value;
  Account *account;
} Tax;

#endif
