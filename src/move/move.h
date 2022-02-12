#ifndef _MOVE_H_
#define _MOVE_H_

#include "../invoice/invoice.h"
#include "../customer/customer.h"
#include "move_line.h"
#include <stdlib.h>

typedef struct Move {
  Customer *customer;
  size_t move_line_list_len;
  MoveLine **move_line_list;
} Move;

Move * move_create_from_invoice(Invoice *);
void move_delete(Move *);



#endif
