#ifndef _MOVE_LINE_H_
#define _MOVE_LINE_H_

#include "../account/account.h"

typedef struct MoveLine {
  Account *account;
  double debit;
  double credit;
} MoveLine;

#endif
