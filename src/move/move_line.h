#ifndef _MOVE_LINE_H_
#define _MOVE_LINE_H_

#include "../account/account.h"

typedef struct MoveLine {
  Account *account;
  double debit;
  double credit;
  struct MoveLine *next_move_line;
} MoveLine;

MoveLine * move_line_new(Account *account, double debit, double credit);
void move_line_delete(MoveLine *);
MoveLine *move_line_find_by_account(MoveLine *move_line, Account *account);

#endif
