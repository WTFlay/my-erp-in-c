//
// Created by flay on 12/02/2022.
//
#include "move_line.h"
#include <stdlib.h>
#include <string.h>

MoveLine * move_line_new(Account *account, double debit, double credit) {
  MoveLine *move_line = malloc(sizeof(MoveLine));
  move_line->account = account;
  move_line->debit = debit;
  move_line->credit = credit;
  move_line->next_move_line = NULL;
  return move_line;
}

void move_line_delete(MoveLine *move_line) {
  MoveLine *current = move_line;
  MoveLine *next;
  while (current != NULL) {
    next = current->next_move_line;
    free(current);
    current = next;
  }
}

MoveLine *move_line_find_by_account(MoveLine *move_line, Account *account) {
  MoveLine *current = move_line;
  while (current != NULL) {
    if (strcmp(current->account->code, account->code) == 0) {
      return current;
    }
    current = current->next_move_line;
  }
  return NULL;
}
