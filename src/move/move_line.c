//
// Created by flay on 12/02/2022.
//
#include "move_line.h"
#include <stdlib.h>

MoveLine * move_line_new(Account *account, double debit, double credit) {
    MoveLine *move_line = malloc(sizeof(MoveLine));
    move_line->account = account;
    move_line->debit = debit;
    move_line->credit = credit;
    return move_line;
}

