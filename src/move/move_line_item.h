//
// Created by flay on 12/02/2022.
//

#ifndef MY_ERP_IN_C_MOVE_LINE_ITEM_H
#define MY_ERP_IN_C_MOVE_LINE_ITEM_H

#include "move_line.h"

typedef struct MoveLineItem {
    MoveLine *item;
    MoveLine *next;
} MoveLineItem;

#endif //MY_ERP_IN_C_MOVE_LINE_ITEM_H
