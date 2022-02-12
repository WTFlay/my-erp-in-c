#include "move.h"

#define CUSTOMER_MOVE_LINE 1
#define PRODUCT_MOVE_LINE 1

Move * move_new(Customer *customer);
MoveLine * move_line_new(Account *account, double debit, double credit);

Move * move_create_from_invoice(Invoice *invoice) {
  return NULL;
}

Move * move_new(Customer *customer) {
    return NULL;
}

MoveLine ** move_line_list_from_invoice_line(Invoice *invoice, InvoiceLine *invoice_line) {
  MoveLine **move_line_list = calloc(2, sizeof(MoveLine *));
  double price_without_tax = invoice_line_calcul_total_price_without_tax(invoice_line);
  move_line_list[0] = move_line_new(invoice->customer->account, 0, price_without_tax);
  move_line_list[1] = move_line_new(invoice_line->product->account, price_without_tax, 0);
  return move_line_list;
}
